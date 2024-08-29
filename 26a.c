#include <stdio.h>
#include <unistd.h>


int main(int argc, char *argv[])
{
    // just have to provide path of the executible file as argv
    execv(argv[1], &argv[1]);
    return 1;
}