/*
============================================================================
Name : 14.c
Author : Harsh Kumar Chandrakar
Description :  Write a program to find the type of a file.
 a. Input should be taken from command line.
 b. program should be able to identify any type of a file.
Date: 15th Aug, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string.h>
int main(int argc, char *argv[])
{
	struct stat st;
	if (stat(argv[1], &st) == -1)
	{
		perror("NO such FILE");
	}
	unsigned int res = st.st_mode;

	if ((res & S_IFMT) == S_IFSOCK)
		printf("This file is a socket\n");
	else if ((res & S_IFMT) == S_IFLNK)
		printf("This file is a symbolic link\n");
	else if ((res & S_IFMT) == S_IFREG)
		printf("This file is a regular file\n");
	else if ((res & S_IFMT) == S_IFBLK)
		printf("This file is a block device\n");
	else if ((res & S_IFMT) == S_IFCHR)
		printf("This file is a character device\n");
	else if ((res & S_IFMT) == S_IFDIR)
		printf("This file is a directory\n");
	else if ((res & S_IFMT) == S_IFIFO)
		printf("This file is a named pipe\n");
	else
		printf("Not known");
}
/*
============================================================================
Output: ./a.out file1.txt 
This file is a regular file
============================================================================
*/