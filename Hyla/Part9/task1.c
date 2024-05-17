#include <stdio.h>
#include <pthread.h>
#include <stdbool.h>
#include <unistd.h>

#define NUM_THREADS 1

void *thread_function(void *thread_arg) {
    int thread_id = *(int *)thread_arg;
    while(true) {
        printf("I am thread\n", thread_id);
        usleep(200000); 
    }
}

int main() {
    pthread_t threads[NUM_THREADS];
    int thread_args[NUM_THREADS];
    int i;

    for (i = 0; i < NUM_THREADS; i++) {
        thread_args[i] = i;
        pthread_create(&threads[i], NULL, thread_function, (void*)&thread_args);
    }

    // In main thread
    while(true) {
        printf("I am main\n");
        usleep(250000);
    }
    return 0;
}
