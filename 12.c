/*
============================================================================
Name : 12.c
Author : Harsh Kumar Chandrakar
Description : . Write a program to find out the opening mode of a file. Use fcntl.
Date: 13th Aug, 2024.
============================================================================
*/
#include <fcntl.h>
#include <stdio.h>
void main()
{
	int fd = open("newfile.txt", O_RDWR);

	if (fd < 0)
	{
		perror("opening:");
	}

	int status = fcntl(fd, F_GETFL);

	if (status < 0)
	{
		perror("fcntl");
	}

	switch (status & O_ACCMODE)
	{
	case O_RDONLY:
		printf("Read only access \n");
		break;
	case O_WRONLY:
		printf("write only access \n");
		break;
	case O_RDWR:
		printf("read and write mode \n");
		break;
	default:
		printf("mode not mentiond \n");
	}
}
/*
============================================================================
Output: giving access mode of file as read and write mode 
============================================================================
*/