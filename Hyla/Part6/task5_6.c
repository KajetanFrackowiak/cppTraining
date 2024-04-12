#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    pid_t child_pid;
    int status;

    child_pid = fork();

    if (child_pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (child_pid == 0) {
        // Child process code
        wait(&status); // Child process waits for another process to complete
        printf("Child process: PID of the terminated process = %d, Return code = %d\n", getpid(), WEXITSTATUS(status));
        exit(EXIT_SUCCESS);
    } else {
        // Parent process code
        exit(EXIT_SUCCESS); // Parent process terminates without waiting for the child process to complete
    }

    return 0;
}