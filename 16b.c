/*
============================================================================
Name : 16b.c
Author : Harsh Kumar Chandrakar
Description : Write a program to perform mandatory locking.
  b. Implement read lock
Date: 28th Aug, 2024.
============================================================================
*/
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

void main(int argv, char *argc[])
{
        struct flock lock;

        lock.l_type = F_RDLCK;
        lock.l_start = 0;
        lock.l_len = 0;
        lock.l_whence = SEEK_SET;
        lock.l_pid = getpid();

        int fd = open(argc[1], O_RDWR);

        if (fd < 0)
        {
                perror("file problem");
        }

        printf("Entering Read lock \n");
        fcntl(fd, F_SETLK, &lock);
        printf("Press enter to unlock..");
        getchar();
        printf("Exiting read lock  ...\n");
        lock.l_type = F_UNLCK;

        fcntl(fd, F_SETLK, &lock);
}
/*
============================================================================
Output: Entering Read lock 
Press enter to unlock..
Exiting read lock  ...
============================================================================
*/