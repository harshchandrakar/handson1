#include <stdio.h>
#include <unistd.h>


int main(int argc, char *argv[])
{
    char *path = "/bin/ls";
    // just have to provide path of the executible file as argv
    execl(path,path,"-Rl",NULL);
    return 1;
}