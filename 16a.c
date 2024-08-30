/*
============================================================================
Name : 16a.c
Author : Harsh Kumar Chandrakar
Description : Write a program to perform mandatory locking.
 a. Implement write lock
Date: 28th Aug, 2024.
============================================================================
*/
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

void main(int argv, char *argc[])
{
	struct flock lock;

	lock.l_type = F_WRLCK;
	lock.l_start = 0;
	lock.l_len = 0;
	lock.l_whence = SEEK_SET;
	lock.l_pid = getpid();

	int fd = open(argc[1], O_RDWR);

	if (fd < 0)
	{
		perror("file problem");
	}

	printf("Entering write lock\n");
	fcntl(fd, F_SETLK, &lock);
	printf("Press enter to Unlock");
	getchar();
	printf("Exiting write lock\n");

	lock.l_type = F_UNLCK;
}
