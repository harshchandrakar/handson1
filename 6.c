/*
============================================================================
Name : 6.c
Author : Harsh Kumar Chandrakar
Description : Write a program to take input from STDIN and display on STDOUT. Use only read/write system calls.
Date: 10th Aug, 2024.
============================================================================
*/
#include <stdio.h>
#include <unistd.h>

void main()
{
	char buffer[20];
	for (int i = 0; i < 5; i++)
	{
		int n1 = read(0, buffer, 20);

		write(0, buffer, n1);
	}
}
