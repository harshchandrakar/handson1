/*
============================================================================
Name : 22.c
Author : Harsh Kumar Chandrakar
Description : Write a program, open a file, call fork, and then write to the file by both the child as well as the
parent processes. Check output of the file.
Date: 29th Aug, 2024.
============================================================================
*/
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main()
{

    fork();
    int fd = open("newfile", O_WRONLY | O_APPEND | O_CREAT, 0644);
    char buffer[100];
    if (fd == -1)
        perror("error opening file : \n");

    sprintf(buffer, "From  process : %d \n", getpid());

    write(fd, &buffer, 100);
    // close(fd);
    return 1;
}
/*
============================================================================
Output: child and parent writes on same file 
============================================================================
*/