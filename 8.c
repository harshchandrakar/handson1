/*
============================================================================
Name : 8.c
Author : Harsh Kumar Chandrakar
Description : Write a program to open a file in read only mode, read line by line and display each line as it is read.
Close the file when end of file is reached.
Date: 13th Aug, 2024.
============================================================================
*/
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

#define BUFFER_SIZE 1024

void main()
{
        char *source = "file1.txt";

        int fd1 = open(source, O_RDONLY);

        if (fd1 < 0)
        {
                perror("file1: ");
        }

        char buffer[BUFFER_SIZE];
        ssize_t bytes_read;

        while (read(fd1, buffer, 1))
        {
                write(0, buffer, 1);
                if (buffer[0] == '\n')
                {
                        getchar();
                }
        }

        close(fd1);
}
