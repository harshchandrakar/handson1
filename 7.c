#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

void main() {
	char *source = "file1.txt";
	char *dest = "file2.txt";

	int fd1 = open(source,O_RDONLY);

	if (fd1<0){
		perror("file1: ");
	}

	int fd2 =open(dest,O_RDWR);

	if (fd2<0){
		perror("file2");
	}

	char buffer[BUFFER_SIZE];
        ssize_t bytes_read , bytes_written;

	if ((bytes_read = read(fd1,buffer,BUFFER_SIZE))>0){
		
		if (bytes_read > 0) {
            		bytes_written = write(fd2, buffer, bytes_read);
            		if (bytes_written < 0) {
                		perror("write");
           	 	}
			int fd3 = write(0,buffer,bytes_read);

			if (fd3 <0){
				perror("file print");
			}
		}
	}

	if (bytes_read <0 ) {
		perror("read");
	}
	close(fd1);
	close(fd2);
}
