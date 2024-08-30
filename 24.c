/*
============================================================================
Name : 24.c
Author : Harsh Kumar Chandrakar
Description : . Write a program to create an orphan process.
Date: 29th Aug, 2024.
============================================================================
*/
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main()
{

    int pid = fork();
    if (pid == 0)
    {
        // inside child process pid will be 0
        sleep(40); // sleeping until parent finishes
        printf("inside child process %d \n", getpid());
        printf("parent process id is : %d \n", getppid());
    }
    else
    {
        // ps -l to see zombie process
        sleep(10);
        printf("inside parent process %d \n", getpid());
        printf("child id is : %d \n", pid);
    }
    return 1;
}