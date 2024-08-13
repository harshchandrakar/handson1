#include <fcntl.h>
#include <stdio.h>
void main() {
	int fd = open("newfile.txt",O_RDWR);

	if (fd<0){
		perror("opening:");
	}

	int status = fcntl(fd,F_GETFL);

	if (status<0){
		perror("fcntl");
	}

	printf("access mode from fcntl: %d\n" ,status & O_ACCMODE);
	printf("given access mode on opening: %d\n", O_RDWR);

}
