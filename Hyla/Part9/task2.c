#include <stdio.h>
#include <pthread.h>

#define NUM_THREADS 1

void *thread_function(void *thread_arg) {
    int thread_id = *(int*)thread_arg;
    for (int i = 0; i < 10; ++i) {
        printf("I am thread\n"); 
    }
    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];
    int thread_args[NUM_THREADS];
    int i = 0;

    pthread_create(&threads[i], NULL, thread_function, (void*)&thread_args);

    for (int i = 0; i < 10; ++i) {
        printf("I am main\n");
    }

    pthread_join(threads[i], NULL);
    printf("Everything is finished\n");

    return 0;
}
