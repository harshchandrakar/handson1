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
/*
============================================================================
Output: total 652
-rwxrwxr-x 1 harsh harsh 16168 Aug 30 11:32 10
-rw-rw-r-- 1 harsh harsh  1352 Aug 30 11:33 10.c
-rwxrwxr-x 1 harsh harsh 16336 Aug 30 11:33 11
-rw-rw-r-- 1 harsh harsh  1869 Aug 30 11:34 11.c
-rwxrwxr-x 1 harsh harsh 16080 Aug 30 11:34 12
-rw-rw-r-- 1 harsh harsh   996 Aug 30 11:35 12.c
-rwxrwxr-x 1 harsh harsh 16176 Aug 30 11:35 13
-rw-rw-r-- 1 harsh harsh  1295 Aug 30 11:36 13.c
-rw-rw-r-- 1 harsh harsh  1434 Aug 30 11:38 14.c
-rw-rw-r-- 1 harsh harsh   713 Aug 30 11:38 15.c
-rwxrwxr-x 1 harsh harsh 16264 Aug 30 11:38 16a
-rw-rw-r-- 1 harsh harsh  1016 Aug 30 11:39 16a.c
-rwxrwxr-x 1 harsh harsh 16264 Aug 30 11:39 16b
-rw-rw-r-- 1 harsh harsh  1189 Aug 30 11:40 16b.c
-rwxrwxr-x 1 harsh harsh 16232 Aug 30 11:40 17a
-rw-rw-r-- 1 harsh harsh   969 Aug 30 11:40 17a.c
-rwxrwxr-x 1 harsh harsh 16392 Aug 30 11:40 17b
============================================================================
*/