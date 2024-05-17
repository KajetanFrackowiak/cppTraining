#include <stdio.h>
#include <pthread.h>

pthread_mutex_t mutex;
int counter;

void *threadFunction(void* args) {
    pthread_mutex_lock(&mutex);

    for (int i = 0; i < 1000; ++i) {
        counter++;
    }

    pthread_mutex_unlock(&mutex);

    return NULL;
}

int main() {
    pthread_t thread1, thread2, thread3, thread4, thread5;
    pthread_mutex_init(&mutex, NULL);

    pthread_create(&thread1, NULL, threadFunction, NULL);
    pthread_create(&thread2, NULL, threadFunction, NULL);
    pthread_create(&thread3, NULL, threadFunction, NULL);
    pthread_create(&thread4, NULL, threadFunction, NULL);
    pthread_create(&thread5, NULL, threadFunction, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    pthread_join(thread3, NULL);
    pthread_join(thread4, NULL);
    pthread_join(thread5, NULL);

    pthread_mutex_destroy(&mutex);

    printf("Result: %d\n", counter);

    return 0;
}