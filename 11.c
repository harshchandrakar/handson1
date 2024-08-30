/*
============================================================================
Name : 11.c
Author : Harsh Kumar Chandrakar
Description : Write a program to open a file, duplicate the file descriptor and append the file with both the
descriptors and check whether the file is updated properly or not.
 a. use dup
 b. use dup2
 c. use fcntl
Date: 13th Aug, 2024.
============================================================================
*/
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

void append_with_fd(int fd, const char *data)
{
    if (write(fd, data, 2) < 0)
    {
        perror("write");
    }
}

int main()
{

    int fd = open("newfile2.txt", O_WRONLY | O_CREAT | O_APPEND, 0644);
    if (fd < 0)
    {
        perror("open");
    }

    append_with_fd(fd, "1\n");

    int fd_dup = dup(fd);
    if (fd_dup < 0)
    {
        perror("dup");
        close(fd);
    }
    append_with_fd(fd_dup, "2\n");

    int fd_dup2 = dup2(fd, fd_dup);
    if (fd_dup2 < 0)
    {
        perror("dup2");
        close(fd);
        close(fd_dup);
    }
    append_with_fd(fd_dup2, "3\n");

    int fd_fcntl = fcntl(fd, F_DUPFD, fd_dup + 1);
    if (fd_fcntl < 0)
    {
        perror("fcntl");
        close(fd);
        close(fd_dup);
        close(fd_dup2);
    }
    append_with_fd(fd_fcntl, "4\n");
    close(fd);
    close(fd_dup);
    close(fd_dup2);
    close(fd_fcntl);

    fd = open("newfile2.txt", O_RDONLY);
    char buffer[1024];
    int rd = read(fd, buffer, 8);
    if (rd < 0)
    {
        perror("read");
    }

    int wr = write(0, buffer, rd);

    if (wr < 0)
    {
        perror("write on screen");
    }

    close(fd);
}
/*
============================================================================
Output: dublicatng file descriptor from 1 to another
============================================================================
*/