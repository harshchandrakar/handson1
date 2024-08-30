/*
============================================================================
Name : 2.c
Author : Harsh Kumar Chandrakar
Description : Write a simple program to execute in an infinite loop at the background. Go to /proc directory and
identify all the process related information in the corresponding proc directory. 
Date: 10th Aug, 2024.
============================================================================
*/
int main() {
    for(;;);
    return 1;
}

/*
============================================================================
Output: cat /proc/11472/status
Name:   2
Umask:  0002
State:  R (running)
Tgid:   11472
Ngid:   0
Pid:    11472
PPid:   4360
TracerPid:      0
Uid:    1000    1000    1000    1000
Gid:    1000    1000    1000    1000
FDSize: 256
Groups: 4 24 27 30 46 100 118 1000 
NStgid: 11472
NSpid:  11472
NSpgid: 11472
NSsid:  4360
VmPeak:     2548 kB
VmSize:     2484 kB
============================================================================
*/