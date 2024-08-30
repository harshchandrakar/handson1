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
/*
============================================================================
Output: ./26a /bin/ls
10    12    14.c   16b    17b    18b    20    22    24    26a    27b.c  27d.c  28.c  30.c  7.c  a.out      file3         procfiles1.txt  procfiles5.txt
10.c  12.c  15.c   16b.c  17b.c  18b.c  20.c  22.c  24.c  26a.c  27c    27e    29    5     8.c  db         newfile       procfiles2.txt  tempCodeRunnerFile.c
11    13    16a    17a    18a    19     21    23    25    26b.c  27c.c  27e.c  29.c  5.c   9    file1.txt  newfile2.txt  procfiles3.txt  tickets
11.c  13.c  16a.c  17a.c  18a.c  19.c   21.c  23.c  25.c  27a.c  27d    28     30    6.c   9.c  file2.txt  newfile.txt   procfiles4.txt  tickets.txt
============================================================================
*/