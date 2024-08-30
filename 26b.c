/*
============================================================================
Name : 26b.c
Author : Harsh Kumar Chandrakar
Description : Write a program to execute an executable program.
 b. pass some input to an executable program. (for example execute an executable of $./a.out name)
Date: 29th Aug, 2024.
============================================================================
*/
#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    char *path = argv[1];
    argv++;
    // passing first parameter as a path and others as its argumnets
    // passing /bin/ls -l
    execv(path, argv);
    return 1;
}