#include <stdio.h>
#include <unistd.h>


int main(int argc, char *argv[],char *env[])
{
    char *path = "/bin/ls";
    // just have to provide path of the executible file as argv
    execle(path,path,"-Rl",NULL,env);
    return 1;
}