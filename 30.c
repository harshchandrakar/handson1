/*
============================================================================
Name : 27a.c
Author : Harsh Kumar Chandrakar
Description : Write a program to run a script at a specific time using a Daemon process.
Date: 29th Aug, 2024.
============================================================================
*/
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    if (!fork())
    {
        // to create session leader to detach daemon process from terminal
        setsid();
        // to set the directory
        chdir("/");

        umask(0);
        while (1)
        {
            sleep(4);
            printf("Chind pid : %d \n", getpid());
            printf("running daemon process..... \n");
        }
    }
    else
        exit(0);
}

// we can check it using ps -el | grep pid
/*
============================================================================
Output: 
Chind pid : 9990 
running daemon process..... 
Chind pid : 9990 
running daemon process..... 
Chind pid : 9990 
running daemon process..... 
============================================================================
*/