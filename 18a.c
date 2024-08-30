/*
============================================================================
Name : 18a.c
Author : Harsh Kumar Chandrakar
Description : Write a program to perform Record locking.
 a. Implement write lock
Create three records in a file. Whenever you access a particular record, first lock it then modify/access
to avoid race condition.
Date: 28th Aug, 2024.
============================================================================
*/
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main()
{
    struct flock lock;
    int train;

    struct
    {
        int ticket_number;
    } db;

    printf("select train number(1,2,3): \t");
    scanf("%d", &train);
    lock.l_type = F_WRLCK;
    lock.l_start = (train - 1) * sizeof(db);
    lock.l_len = sizeof(db);
    lock.l_whence = SEEK_SET;
    lock.l_pid = getpid();

    int fd;

    // checking if file already exist or not
    if (access("db", F_OK) == 0)
    {
        fd = open("db", O_RDWR);
        if (fd < 0)
            perror("error in opening: \n");
    }
    else
    {
        fd = open("db", O_RDWR | O_CREAT, 0644);
        if (fd < 0)
            perror("error in creating new: \n");
        db.ticket_number = 0;
        for (int i = 0; i < 3; i++)
        {
            write(fd, &db, sizeof(db));
        }

        if (lseek(fd, 0, SEEK_SET) < 0)
        {
            perror("error in lseek: ");
            close(fd);
            return 1;
        }
    }

    lseek(fd, (train - 1) * sizeof(db), SEEK_SET);
    read(fd, &db, sizeof(db));

    printf("Entering Write lock... \n");
    fcntl(fd, F_SETLKW, &lock);

    printf("current ticket number : %d \n", db.ticket_number);
    db.ticket_number++;

    lseek(fd, -1 * sizeof(db), SEEK_CUR);

    if (0 > write(fd, &db, sizeof(db)))
        perror("error in write : \n");

    printf("Ticket number after increment: %d \n", db.ticket_number);

    printf("Press enter to exit lock....\n");

    getchar();
    getchar();

    lock.l_type = F_UNLCK;
    fcntl(fd, F_SETLK, &lock);

    return 0;
}
