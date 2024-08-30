/*
============================================================================
Name : 10.c
Author : Harsh Kumar Chandrakar
Description : Write a program to open a file with read write mode, write 10 bytes, move the file pointer by 10
bytes (use lseek) and write again 10 bytes.
 a. check the return value of lseek
 b. open the file with od and check the empty spaces in between the data.
Date: 13th Aug, 2024.
============================================================================
*/
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

void main()
{
    char *data = "12305678910";
    size_t data_size = 10;

    int fd = open("newfile.txt", O_RDWR | O_CREAT | O_TRUNC, 0644);
    if (fd < 0)
    {
        perror("open");
    }

    if (write(fd, data, data_size) != data_size)
    {
        perror("write");
    }

    off_t offset = lseek(fd, 10, SEEK_CUR);
    if (offset == (off_t)-1)
    {
        perror("lseek");
    }

    printf("lseek value: %ld \n", offset);

    if (write(fd, data, data_size) != data_size)
    {
        perror("write");
    }

    close(fd);
}
