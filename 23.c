/*
============================================================================
Name : 23.c
Author : Harsh Kumar Chandrakar
Description : Write a program to create a Zombie state of the running program.
Date: 29th Aug, 2024.
============================================================================
*/
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main()
{

    int pid = fork();
    if (pid)
    {
        printf("inside child process %d \n", getpid());
        printf("parent process id is : %d \n", getppid());
    }
    else
    {
        // ps -l to see zombie process
        sleep(500);
        printf("inside parent process %d \n", getpid());
        printf("child id is : %d \n", pid);
    }
    return 1;
}