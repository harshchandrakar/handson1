/*
============================================================================
Name : 27c.c
Author : Harsh Kumar Chandrakar
Description :  Write a program to execute ls -Rl by the following system calls
 a. execle
Date: 29th Aug, 2024.
============================================================================
*/
#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[], char *env[])
{
    char *path = "/bin/ls";
    // just have to provide path of the executible file as argv
    execle(path, path, "-Rl", NULL, env);
    return 1;
}