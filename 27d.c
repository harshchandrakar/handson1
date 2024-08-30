/*
============================================================================
Name : 27d.c
Author : Harsh Kumar Chandrakar
Description :  Write a program to execute ls -Rl by the following system calls
 a. execv
Date: 29th Aug, 2024.
============================================================================
*/
#include <stdio.h>
#include <unistd.h>

int main()
{
    char *path = "/bin/ls";
    char *argv[] = {path, "-Rl", NULL};

    // passing first parameter as a path and others as its argumnets
    // passing /bin/ls -l
    execv(path, argv);
    return 1;
}