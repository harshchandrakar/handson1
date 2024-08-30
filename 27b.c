/*
============================================================================
Name : 27b.c
Author : Harsh Kumar Chandrakar
Description :  Write a program to execute ls -Rl by the following system calls
  b. execlp
Date: 29th Aug, 2024.
============================================================================
*/
#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    char *path = "/bin/ls";
    // just have to provide path of the executible file as argv
    execlp(path, path, "-Rl", NULL);
    return 1;
}
/*
============================================================================
Output: 
total 668
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
-rw-rw-r-- 1 harsh harsh  1611 Aug 30 11:41 17b.c
-rwxrwxr-x 1 harsh harsh 16528 Aug 30 11:41 18a
-rw-rw-r-- 1 harsh harsh  2356 Aug 30 11:41 18a.c
-rwxrwxr-x 1 harsh harsh 16400 Aug 30 11:41 18b
-rw-rw-r-- 1 harsh harsh  1498 Aug 30 11:41 18b.c
-rwxrwxr-x 1 harsh harsh 16032 Aug 30 11:41 19
-rw-rw-r-- 1 harsh harsh   993 Aug 30 11:42 19.c
-rwxrwxr-x 1 harsh harsh 16176 Aug 30 11:42 20
-rw-rw-r-- 1 harsh harsh  1098 Aug 30 11:42 20.c
-rwxrwxr-x 1 harsh harsh 16040 Aug 30 11:43 21
-rw-rw-r-- 1 harsh harsh   741 Aug 30 11:43 21.c
-rwxrwxr-x 1 harsh harsh 16224 Aug 30 11:44 22
-rw-rw-r-- 1 harsh harsh   946 Aug 30 11:46 22.c
-rwxrwxr-x 1 harsh harsh 16128 Aug 30 11:46 23
-rw-rw-r-- 1 harsh harsh  1262 Aug 30 11:47 23.c
-rwxrwxr-x 1 harsh harsh 16128 Aug 30 11:48 24
============================================================================
*/