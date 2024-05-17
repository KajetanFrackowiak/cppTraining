#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>

#define BUFFER_SIZE 5

sem_t empty, full, mutex;
int buffer[BUFFER_SIZE];
int in = 0, out = 0;

void *producer(void *arg) {
    int item = 0;
    while (1) {
        // Produce item
        item++;

        sem_wait(&empty); // Wait for empty slot
        sem_wait(&mutex); // Lock buffer

        // Add item to buffer
        buffer[in] = item;
        in = (in + 1) % BUFFER_SIZE;
        printf("Produced: %d\n", item);

        sem_post(&mutex); // Unlock buffer
        sem_post(&full); // Signal full slot
    }
}

void *consumer(void *args) {
    int item;
    while (1) {
        sem_wait(&full); // Wait for full slot
        sem_wait(&mutex);

        // Consume item from buffer
        item = buffer[out];
        out = (out + 1) % BUFFER_SIZE;
        printf("Consumed: %d\n", item);

        sem_post(&mutex); // Unlock buffer
        sem_post(&empty); // Signal empty slot
    }
}

int main() {
    pthread_t producer_thread, consumer_thread;

    // Initialize semaphores
    sem_init(&empty, 0, BUFFER_SIZE);
    sem_init(&full, 0, 0);
    sem_init(&mutex, 0, 1);

    // Create producer and consumer threads
    pthread_create(&producer_thread, NULL, producer, NULL);
    pthread_create(&consumer_thread, NULL, consumer, NULL);

    // Wait for thread to finish
    pthread_join(producer_thread, NULL);
    pthread_join(producer_thread, NULL);

    // Destroy semaphores
    sem_destroy(&empty);
    sem_destroy(&full);
    sem_destroy(&mutex);
}