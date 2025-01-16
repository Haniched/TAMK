#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include <unistd.h>

void type_prompt () {
    
}

void read_command () {

}

int main (int argc, char *argv[]) {
    pid_t pid;
    int status;

    pid = fork();

    if (pid < 0) {
        perror("fork failed");
        exit(1);
    } else if (pid == 0) { // child process
        if (execvp(argv[1], &argv[1]) == -1) {
            perror("execvp failed");
            exit(1);
        }
    } else { // parent process
        if (waitpid(pid, &status, 0) == -1) {
            perror("waitpid failed");
            exit(1);
        }
    }
    

    return 0;
}
