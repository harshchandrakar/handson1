/*
============================================================================
Name : 18b.c
Author : Harsh Kumar Chandrakar
Description : Write a program to perform Record locking.
 b. Implement read lock
Create three records in a file. Whenever you access a particular record, first lock it then modify/access
to avoid race condition.
Date: 28th Aug, 2024.
============================================================================
*/
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

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
	lock.l_type = F_RDLCK;
	lock.l_start = (train - 1) * sizeof(db);
	lock.l_len = sizeof(db);
	lock.l_whence = SEEK_SET;
	lock.l_pid = getpid();

	int fd = open("db", O_RDWR);

	if (fd < 0)
		perror("error in opening: \n");

	printf("Entering Read lock... \n");
	fcntl(fd, F_SETLKW, &lock);

	lseek(fd, (train - 1) * sizeof(db), SEEK_SET);
	read(fd, &db, sizeof(db));
	printf("Current ticket number is : %d \n", db.ticket_number);

	printf("Press enter to exit lock....\n");

	getchar();
	getchar();

	lock.l_type = F_UNLCK;
	fcntl(fd, F_SETLK, &lock);

	return 0;
}
/*
============================================================================
Output: select train number(1,2,3):     2
Entering Read lock... 
Current ticket number is : 3 
Press enter to exit lock....
============================================================================
*/