/*
============================================================================
Name : 5.c
Author : Harsh Kumar Chandrakar
Description : Write a program to create five new files with infinite loop. Execute the program in the background
and check the file descriptor table at /proc/pid/fd.
Date: 10th Aug, 2024.
============================================================================
*/

#include <fcntl.h>
#include <stdio.h>

void main()
{
  int fd;

  for (int i = 1; i <= 5; i++)
  {
    char file[20];
    snprintf(file, sizeof(file), "procfiles%d.txt", i);
    fd = creat(file, 0666);

    if (fd < 0)
    {
      perror("file not created");
    }
  }
  while (1)
    ;
}
/*
============================================================================
Output: created all 5 text files by name procfiles{1..5}.txt
============================================================================
*/