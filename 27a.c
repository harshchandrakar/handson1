/*
============================================================================
Name : 27a.c
Author : Harsh Kumar Chandrakar
Description :  Write a program to execute ls -Rl by the following system calls
 a. execl
Date: 29th Aug, 2024.
============================================================================
*/
#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    char *path = "/bin/ls";
    // just have to provide path of the executible file as argv
    execl(path, path, "-Rl", NULL);
    return 1;
}