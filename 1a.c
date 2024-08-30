/*
============================================================================
Name : 1a.c
Author : Harsh Kumar Chandrakar
Description : 1. Create the following types of a files using (i) shell command (ii) system call
 a. soft link (symlink system call)
Date: 10th Aug, 2024.
============================================================================
*/
#include<unistd.h>

int main(){
    symlink("./file1.txt","softlk");
    return 1;
}
/*
============================================================================
Output: 3580493 -rw-rw-r-- 2 harsh harsh   584 Aug 11 18:29 file1.txt
3580756 lrwxrwxrwx 1 harsh harsh    11 Aug 30 12:10 softlk -> ./file1.txt
============================================================================
*/