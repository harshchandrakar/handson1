#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    if (!fork()){
        // to create session leader to detach daemon process from terminal
        setsid();
        // to set the directory
        chdir("/");

        umask(0);
            while(1){
                sleep(4);
                printf("Chind pid : %d \n",getpid());
                printf("running daemon process..... \n");
            }
    }else exit(0);
}

// we can check it using ps -el | grep pid