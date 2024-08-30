/*
============================================================================
Name : 13.c
Author : Harsh Kumar Chandrakar
Description : Write a program to wait for a STDIN for 10 seconds using select. Write a proper print statement to
verify whether the data is available within 10 seconds or not (check in $man 2 select).
Date: 15th Aug, 2024.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/select.h>

void main()
{
	fd_set readFd;
	struct timeval tm;
	int res;

	FD_ZERO(&readFd);
	FD_SET(STDIN_FILENO, &readFd);

	tm.tv_sec = 10;

	printf("waited for 10 sec for input \n");

	res = select(STDIN_FILENO + 1, &readFd, NULL, NULL, &tm);

	if (res == -1)
	{
		perror("error with select \n");
	}
	else if (res)
	{
		printf("data available \n");
		char buffer[1024];
		int read_size = read(STDIN_FILENO, buffer, 1024);
		if (read_size > 0)
			buffer[read_size] = '\0';

		printf("input data : %s \n", buffer);
	}
	else
	{
		printf("time out \n");
	}
}
/*
============================================================================
Output: 
waited for 10 sec for input 
harsh
data available 
input data : harsh
============================================================================
*/