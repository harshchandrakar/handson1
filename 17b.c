/*
============================================================================
Name : 17b.c
Author : Harsh Kumar Chandrakar
Description : Write a program to simulate online ticket reservation.  Write a separate program, to
open the file, implement write lock, read the ticket number, increment the number and print
the new ticket number then close the file
Date: 28th Aug, 2024.
============================================================================
*/
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main()
{

	struct flock lock;
	lock.l_type = F_WRLCK;
	lock.l_start = 0;
	lock.l_len = 0;
	lock.l_whence = SEEK_SET;
	lock.l_pid = getpid();

	int fd = open("tickets", O_RDWR);

	if (fd < 0)
		perror("error in opening: \n");

	struct
	{
		int ticket_number;
	} db;

	printf("Entering Write lock... \n");
	fcntl(fd, F_SETLK, &lock);

	if (0 > read(fd, &db, sizeof(db)))
		perror("error in reading: \n");
	printf("Ticket number before increment: %d \n", db.ticket_number);

	lseek(fd, -1 * sizeof(db), SEEK_CUR);

	db.ticket_number += 1;

	if (0 > write(fd, &db, sizeof(db)))
		perror("error in write : \n");

	printf("Ticket number after increment: %d \n", db.ticket_number);

	printf("Press enter to exit lock....");

	getchar();

	lock.l_type = F_UNLCK;
	fcntl(fd, F_SETLK, &lock);

	return 0;
}
/*
============================================================================
Output: Entering Write lock... 
Ticket number before increment: 22 
Ticket number after increment: 23 
Press enter to exit lock....
============================================================================
*/