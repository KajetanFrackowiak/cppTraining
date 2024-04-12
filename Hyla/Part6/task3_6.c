#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    pid_t child_pid;
    child_pid = fork();

    if (child_pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (child_pid == 0) {
        printf("Child process: Parent PPID = %d\n", getppid());
        exit(EXIT_SUCCESS);
    } else {
        // Parent process code
        int status;
        waitpid(child_pid, &status, 0);
        printf("Child process with PID=%d is finished\n", child_pid);
    }

    return 0;
}