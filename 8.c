#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

#define BUFFER_SIZE 1024

void main() {
        char *source = "file1.txt";

        int fd1 = open(source,O_RDONLY);

        if (fd1<0){
                perror("file1: ");
        }
        

        char buffer[BUFFER_SIZE];
        ssize_t bytes_read ;

        if ((bytes_read = read(fd1,buffer,BUFFER_SIZE))>0){
                
                if (bytes_read > 0) {
                        
                        int fd3 = write(0,buffer,bytes_read);

                        if (fd3 <0){
                                perror("file print");
                        }
			close(fd3);
                }
        }

        if (bytes_read <0 ) {
                perror("read");
        }
        close(fd1);
   
}

