/*
============================================================================
Name : 25.c
Author : Harsh Kumar Chandrakar
Description : Write a program to create three child processes. The parent should wait for a particular child (use
waitpid system call).
Date: 29th Aug, 2024.
============================================================================
*/
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    int pid[3];
    for (int i = 1; i <= 3; i++)
    {
        pid[i - 1] = fork();
        if (pid[i - 1] == 0)
        {
            // executed by child
            pause(); // waiting for signal like kill the process from other terminal using ps aux|grep 25
            sleep(20);
        }
        else
        {
            printf("from parent %d and child no: %d with pid : %d \n", getpid(), i, pid[i - 1]);
        }
    }

    int process, status;

    printf("select which chid process to stop {1,2,3}: \t");
    scanf("%d", &process);
    waitpid(pid[process - 1], &status, 0);
    printf("exiting child with pid : %d \n", pid[process - 1]);
    return 0;
}