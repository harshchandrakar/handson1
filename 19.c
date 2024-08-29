#include <sys/time.h>
#include <unistd.h>
#include <stdio.h>

unsigned long long int tmstamp(){
    unsigned long long int tm;
    __asm__ __volatile__ ("rdtsc":"=A" (tm));
}

int main(){
    int i ,ns;
    unsigned long long int start,end;
    start = tmstamp();
    getpid();
    end=tmstamp();
    ns= (end-start)/2.9; // found max cpu frequency by lscpu
    printf("execution time for getpid in nano second is: %d  \n" ,ns);
}