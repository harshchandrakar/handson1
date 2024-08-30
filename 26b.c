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
/*
============================================================================
Output: ./26b /bin/ls -l
total 636
-rwxrwxr-x 1 harsh harsh 16168 Aug 30 11:32 10
-rw-rw-r-- 1 harsh harsh  1352 Aug 30 11:33 10.c
-rwxrwxr-x 1 harsh harsh 16336 Aug 30 11:33 11
-rw-rw-r-- 1 harsh harsh  1869 Aug 30 11:34 11.c
-rwxrwxr-x 1 harsh harsh 16080 Aug 30 11:34 12
-rw-rw-r-- 1 harsh harsh   996 Aug 30 11:35 12.c
-rwxrwxr-x 1 harsh harsh 16176 Aug 30 11:35 13
-rw-rw-r-- 1 harsh harsh  1295 Aug 30 11:36 13.c......
============================================================================
*/