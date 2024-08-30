/*
============================================================================
Name : 17a.c
Author : Harsh Kumar Chandrakar
Description : Write a program to simulate online ticket reservation. Implement write lock
Write a program to open a file, store a ticket number and exit.
Date: 28th Aug, 2024.
============================================================================
*/
#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>

int main()
{
	struct
	{
		int ticket_number;
	} db;

	int fd = open("tickets", O_RDWR | O_CREAT, 0644);

	if (fd < 0)
		perror("error opening file: \n");

	int ticket;
	printf("enter ticket number :\t");
	scanf("%d", &ticket);

	db.ticket_number = ticket;

	write(fd, &db, sizeof(db));

	close(fd);

	return 0;
}
