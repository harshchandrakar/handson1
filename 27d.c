#include <stdio.h>
#include <unistd.h>


int main()
{
    char *path = "/bin/ls";
    char *argv[] = {path,"-Rl",NULL};
    
    // passing first parameter as a path and others as its argumnets
    //passing /bin/ls -l
    execv(path, argv);
    return 1;
}