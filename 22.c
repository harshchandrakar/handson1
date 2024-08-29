#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main() {
    
    fork();
    int fd = open("newfile",O_WRONLY| O_APPEND |O_CREAT ,0644);
    char buffer[100];
    if (fd == -1) perror("error opening file : \n");

    sprintf(buffer,"From  process : %d \n",getpid());

    write(fd,&buffer,100);
    // close(fd);
    return 1;
}