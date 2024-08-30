/*
============================================================================
Name : 20.c
Author : Harsh Kumar Chandrakar
Description : Find out the priority of your running program. Modify the priority with nice command.
Date: 29th Aug, 2024.
============================================================================
*/
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/resource.h>

int main()
{

    int priority = getpriority(PRIO_PROCESS, getpid());
    printf("current priority of process is: %d \n", priority);

    printf("\n changing priority to 5: \n");

    int val = nice(5);

    if (val == -1)
        perror("error executing nice: \n");
    else
    {
        priority = getpriority(PRIO_PROCESS, getpid());
        printf("\n new priority of process is: %d \n", priority);
    }
    return 1;
}
/*
============================================================================
Output: current priority of process is: 0 

 changing priority to 5: 

 new priority of process is: 5
============================================================================
*/