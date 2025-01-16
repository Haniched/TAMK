#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>

int main (int argc, char *argv[]) {
    
    if (argc > 2) {
        fprintf(stderr, "Usage: %s <argument>\n", argv[0]);
        exit(1);
    }
    printf("%s\n", argv[0]);

    char *program = "/bin/ls";

    char *new_argv[] = {"ls", NULL};
    char *envp[] = {NULL}; // Environment variables for the new program, not passing any


    if (execve(program, new_argv, envp) == -1) {
        perror("execve");
        exit(1);
    }
    
    printf("This will never be printed\n");

    return 0;
}
