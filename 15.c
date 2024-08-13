#include <stdio.h>

extern char **environ;

void main() {
    char **env = environ;

    printf("environment variables:\n");
    while (*env) {
        printf("%s\n", *env);
        env++;
    }

}

