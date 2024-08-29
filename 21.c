#include <stdio.h>
#include <unistd.h>

int main(){

    printf("parent process id : %d \n",getpid());

    int child =fork();

    if (child) printf("child process id : %d \n",child);

    return 1;
}