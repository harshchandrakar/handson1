/*
============================================================================
Name : 1b.c
Author : Harsh Kumar Chandrakar
Description : 1. Create the following types of a files using (i) shell command (ii) system call
  b. hard link (link system call)
Date: 10th Aug, 2024.
============================================================================
*/
#include<unistd.h>

int main(){
    link("./file1.txt","hardlk");
    return 1;
}

/*
============================================================================
Output: 3580493 -rw-rw-r-- 2 harsh harsh   584 Aug 11 18:29 file1.txt
3580493 -rw-rw-r-- 2 harsh harsh   584 Aug 11 18:29 hardlk
============================================================================
*/