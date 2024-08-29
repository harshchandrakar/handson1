#include <stdio.h>
#include <unistd.h>


int main(int argc, char *argv[])
{
    char *path = argv[1];
    argv++;
    // passing first parameter as a path and others as its argumnets
    //passing /bin/ls -l
    execv(path, argv);
    return 1;
}