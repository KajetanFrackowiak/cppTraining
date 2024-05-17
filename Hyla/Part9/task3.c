#include <pthread.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

volatile bool stop_thread = false;
volatile bool timer_paused = false;
int seconds = 0;
int total_elapsed_time = 0;
pthread_t tid;
time_t start_time, pause_time;

void *timer_thread(void *arg) {
    time(&start_time);
    while (!stop_thread) {
        if (!timer_paused) {
            // printf("\rTime elapsed: %d seconds", seconds);
            fflush(stdout);
            sleep(1);
            seconds++;
        } else {
            time(&pause_time);
            pause_time -= start_time;
            pause_time -= seconds;
            sleep(1);
        }
    }
    pthread_exit(NULL);
}
int main() {
    char input[10];

    while (true) {
        printf("\nCommands:\n");
        printf("start - Start the timer\n");
        printf("stop - Stop the timer\n");
        printf("reset - Reset the timer\n");
        printf("exit - Exit the program\n");
        printf("Enter command: ");
        scanf("%s", input);

        if (strcmp(input, "start") == 0) {
            if (!tid) {
                stop_thread = false;
                timer_paused = false;
                pthread_create(&tid, NULL, timer_thread, NULL);
                if (seconds > 0) {
                    time_t current_time;
                    time(&current_time);
                    start_time = current_time - seconds;
                }
                printf("Timer started.\n");
            } else {
                printf("Timer is already running.\n");
            }
        } else if (strcmp(input, "stop") == 0) {
            if (tid) {
                stop_thread = true;
                pthread_join(tid, NULL);
                tid = 0;
                printf("\nTimer stopped. Elapsed time: %d seconds\n", seconds);
            } else {
                printf("Timer is not running.\n");
            }
        } else if (strcmp(input, "reset") == 0) {
            if (!tid) {
                total_elapsed_time += seconds;
                seconds = 0;
                printf("Total elapsed time: %d seconds\n", total_elapsed_time);
                printf("Timer reset.\n");
            } else {
                printf("First stop, then reset.\n");
            }
        } else if (strcmp(input, "exit") == 0) {
            if (tid) {
                stop_thread = true;
                pthread_join(tid, NULL);
            }
            printf("Exiting program.\n");
            break;
        } else {
            printf("Invalid command. Please try again.\n");
        }
    }
    return 0;
}
