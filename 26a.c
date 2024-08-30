/*
============================================================================
Name : 26a.c
Author : Harsh Kumar Chandrakar
Description : Write a program to execute an executable program.
 a. use some executable program
Date: 29th Aug, 2024.
============================================================================
*/
#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    // just have to provide path of the executible file as argv
    execv(argv[1], &argv[1]);
    return 1;
}