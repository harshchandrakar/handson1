/*
============================================================================
Name : 1c.c
Author : Harsh Kumar Chandrakar
Description : 1. Create the following types of a files using (i) shell command (ii) system call
c. FIFO (mkfifo Library Function or mknod system call)
Date: 10th Aug, 2024.
============================================================================
*/
#include<sys/stat.h>

int main(){
    mknod("newfifo",S_IFIFO | 0666,0);
    return 0;
}


/*
============================================================================
Output: 3580759 prw-rw-r-- 1 harsh harsh     0 Aug 30 12:17 newfifo
============================================================================
*/