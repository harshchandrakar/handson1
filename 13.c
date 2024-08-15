#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/select.h>

void main() {
	fd_set readFd;
	struct timeval tm;
	int res;

	FD_ZERO(&readFd);
	FD_SET(STDIN_FILENO,&readFd);

	tm.tv_sec = 10;
	
	printf("waited for 10 sec for input \n");

	res = select(STDIN_FILENO+1,&readFd ,NULL ,NULL,&tm);

	if (res == -1){
		perror("error with select \n");
	}else if (res) {
		printf("data available \n");
		char buffer[1024];
		int read_size = read(STDIN_FILENO,buffer,1024);
		if (read_size >0 )
		buffer[read_size] = '\0';

		printf("input data : %s \n" , buffer);

	}else{
		printf("time out \n");
	}

}
