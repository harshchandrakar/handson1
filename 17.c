#include<fcntl.h>
#include<stdio.h>
#include<unistd.h>

int main() {
	int fd;
	struct{
		int ticket;
	} db;

	fd = open("fdb", O_WRONLY |O_EXCL |O_CREAT ,0600);

	if (fd<0){
		perror("error opening file");
	}



