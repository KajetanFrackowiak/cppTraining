#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int i;
    pid_t child_pid[3];

    // Three child processes
    for (i = 0; i < 3; i++) {
        child_pid[i] = fork();

        if (child_pid[i] == -1) {
            perror("fork");
            exit(EXIT_FAILURE);
        } else if (child_pid[i] == 0) {
            // Child's process code
            printf("Child process: PID=%d, PPID=%d\n", getpid(), getppid());
            exit(EXIT_SUCCESS);
        }
    }

    // Parent process that waiting for the end of the all processes
    for (i = 0; i < 3; i++) {
        int status;
        waitpid(child_pid[i], &status, 0);
        printf("Child process with PID=%d ended.\n", child_pid[i]);
    }

    printf("All child processes terminated");

    return 0;
}