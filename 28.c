/*
============================================================================
Name : 28.c
Author : Harsh Kumar Chandrakar
Description :  Write a program to get maximum and minimum real time priority.
Date: 29th Aug, 2024.
============================================================================
*/
#include <stdio.h>
#include <sched.h>

int main()
{
    printf("Realtime scheduling priorities: \n");

    printf("For FIFO scheduling Maximum priority: %d and Minimum priority: %d  \n", sched_get_priority_max(SCHED_FIFO), sched_get_priority_min(SCHED_FIFO));
    printf("For RR scheduling Maximum priority: %d and Minimum priority: %d  \n", sched_get_priority_max(SCHED_RR), sched_get_priority_min(SCHED_RR));
    return 0;
}
/*
============================================================================
Output: 
Realtime scheduling priorities: 
For FIFO scheduling Maximum priority: 99 and Minimum priority: 1  
For RR scheduling Maximum priority: 99 and Minimum priority: 1  
============================================================================
*/