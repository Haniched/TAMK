#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include <unistd.h>

int main (int argc, char *argv[]) {
    pid_t pid;
    int status;

    printf("%s\n", argv[0]);

    pid = fork();

    if (pid < 0) {
        perror("fork failed");
        exit(1);
    } else if (pid == 0) {
        char *program = "/bin/ls";
        char *new_argv[] = {"ls", NULL};

        if (execve(program, new_argv, NULL) == -1) {
            perror("execve failed");
            exit(1);
        }
    } else {
        if (waitpid(pid, &status, 0) == -1) {
            perror("waitpid failed");
            exit(1);
        }
          if (WIFEXITED(status)) {
            printf("Parent: Child exited with status %d\n", WEXITSTATUS(status));
        } else if (WIFSIGNALED(status)) {
            printf("Parent: Child terminated by signal %d\n", WTERMSIG(status));
        }
    }

    return 0;
}
