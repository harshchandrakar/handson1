/*
============================================================================
Name : 7.c
Author : Harsh Kumar Chandrakar
Description : Write a program to copy file1 into file2 ($cp file1 file2).
Date: 13th Aug, 2024.
============================================================================
*/
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

void main(int argc, char *argv[])
{
	char *source = "file1.txt";
	char *dest = "file2.txt";

	int fd1 = open(argv[1], O_RDONLY);

	if (fd1 < 0)
	{
		perror("file1: ");
	}

	int fd2 = open(argv[2], O_WRONLY | O_EXCL | O_CREAT, 0600);

	if (fd2 < 0)
	{
		perror("file2");
	}

	char buffer[BUFFER_SIZE];
	ssize_t bytes_read, bytes_written;

	if ((bytes_read = read(fd1, buffer, BUFFER_SIZE)) > 0)
	{

		if (bytes_read > 0)
		{
			bytes_written = write(fd2, buffer, bytes_read);
			if (bytes_written < 0)
			{
				perror("write");
			}
		}
	}

	if (bytes_read < 0)
	{
		perror("read");
	}
	close(fd1);
	close(fd2);
}
/*
============================================================================
Output: copies file 1 data to file 2
============================================================================
*/