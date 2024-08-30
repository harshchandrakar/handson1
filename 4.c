/*
============================================================================
Name : 4.c
Author : Harsh Kumar Chandrakar
Description : Write a program to open an existing file with read write mode. Try O_EXCL flag also. 
Date: 10th Aug, 2024.
============================================================================
*/
#include<stdio.h>
#include <fcntl.h>
int main(){
    int fd = open("./newfile.txt",O_RDWR);

    if (fd<0) perror("error opening file");
    fd = open("./newfile.txt",O_CREAT|O_EXCL|O_RDWR,0666);
    if (fd<0) perror("can't create already existing file");
    return 1;
}
/*
============================================================================
Output: can't create already existing file: File exists
============================================================================
*/