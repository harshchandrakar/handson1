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
/*
============================================================================
Output: inside child process 8412 
parent process id is : 4360 

ps -l
F S   UID     PID    PPID  C PRI  NI ADDR SZ WCHAN  TTY          TIME CMD
0 S  1000    4360    3760  0  80   0 -  2859 do_wai pts/1    00:00:00 bash
1 S  1000    8413    1715  0  80   0 -   621 hrtime pts/1    00:00:00 23
4 R  1000    8459    4360 99  80   0 -  3550 -      pts/1    00:00:00 ps
============================================================================
*/