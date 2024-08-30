/*
============================================================================
Name : 21.c
Author : Harsh Kumar Chandrakar
Description : Write a program, call fork and print the parent and child process id.
Date: 29th Aug, 2024.
============================================================================
*/
#include <stdio.h>
#include <unistd.h>

int main()
{

    printf("parent process id : %d \n", getpid());

    int child = fork();

    if (child)
        printf("child process id : %d \n", child);

    return 1;
}