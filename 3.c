/*
============================================================================
Name : 3.c
Author : Harsh Kumar Chandrakar
Description : Write a program to create a file and print the file descriptor value. Use creat ( ) system call?
Date: 10th Aug, 2024.
============================================================================
*/
#include<stdio.h>
#include <fcntl.h>
int main(){
    int fd = creat("./newfile.txt",0666);

    if (fd<0) perror("error creating file");
    printf("file descriptor of file: %d \n",fd);
    return 1;
}
/*
============================================================================
Output: file descriptor of file: 3
============================================================================
*/