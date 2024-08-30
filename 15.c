/*
============================================================================
Name : 15.c
Author : Harsh Kumar Chandrakar
Description : Write a program to display the environmental variable of the user (use environ).
Date: 15th Aug, 2024.
============================================================================
*/
#include <stdio.h>

extern char **environ;

void main()
{
    char **env = environ;

    printf("environment variables:\n");
    while (*env)
    {
        printf("%s\n", *env);
        env++;
    }
}
