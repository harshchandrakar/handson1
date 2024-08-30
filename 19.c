/*
============================================================================
Name : 19.c
Author : Harsh Kumar Chandrakar
Description : Write a program to find out time taken to execute getpid system call. Use time stamp counter.
Date: 29th Aug, 2024.
============================================================================
*/
#include <sys/time.h>
#include <unistd.h>
#include <stdio.h>

unsigned long long int tmstamp()
{
    unsigned long long int tm;
    __asm__ __volatile__("rdtsc" : "=A"(tm));
}

int main()
{
    int i, ns;
    unsigned long long int start, end;
    start = tmstamp();
    getpid();
    end = tmstamp();
    ns = (end - start) / 2.9; // found max cpu frequency by lscpu
    printf("execution time for getpid in nano second is: %d  \n", ns);
}
/*
============================================================================
Output: execution time for getpid in nano second is: 7470 
============================================================================
*/