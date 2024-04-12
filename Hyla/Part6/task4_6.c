#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char* argv[]) {
    pid_t child_pid1, child_pid2;
    child_pid1 = fork();
    
    if (child_pid1== -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (child_pid1 == 0) {
        printf("I am child process 1\n");
        exit(EXIT_SUCCESS);
    }

    child_pid2 = fork();

    if (child_pid2 == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (child_pid2 == 0) {
        printf("I am child process 2\n");
        exit(EXIT_SUCCESS);
    }

    int status1, status2;
    waitpid(child_pid1, &status1, 0);
    waitpid(child_pid2, &status2, 0);

    printf("All child processes are finished.\n");

    return 0;
}