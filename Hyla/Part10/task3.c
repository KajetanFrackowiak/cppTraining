#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_READERS 5
#define NUM_WRITERS 2

sem_t mutex; // Semaphore for synchronizing access to the resource
sem_t wrt;   // Semaphore for synchronizing writers

int readers_count = 0;

void *reader(void *arg) {
    int reader_id = *((int *)arg);
    while (1) {
        // Reader tries to enter
        sem_wait(&mutex);
        readers_count++;
        if (readers_count == 1) {
            sem_wait(&wrt); // If it's the first reader, block writers
        }
        sem_post(&mutex); // Release the semaphore

        // Reader reads
        printf("Reader %d is reading.\n", reader_id);
        // sleep(1); // Simulating reading

        // Reader leaves
        sem_wait(&mutex);
        readers_count--;
        if (readers_count == 0) {
            sem_post(&wrt); // If it's the last reader, allow writers to write
        }
        sem_post(&mutex); // Release the semaphore
    }
}

void *writer(void *arg) {
    int writer_id = *((int *)arg);
    while (1) {
        // Writer tries to enter
        sem_wait(&wrt);

        // Writer writes
        printf("Writer %d is writing.\n", writer_id);
        // sleep(2); // Simulating writing

        // Writer leaves
        sem_post(&wrt);
    }
}

int main() {
    pthread_t readers[NUM_READERS], writers[NUM_WRITERS];
    int reader_ids[NUM_READERS] = {0};
    int writer_ids[NUM_WRITERS] = {0};

    // Initializing semaphores
    sem_init(&mutex, 0, 1);
    sem_init(&wrt, 0, 1);

    // Creating reader threads
    for (int i = 0; i < NUM_READERS; ++i) {
        pthread_create(&readers[i], NULL, reader, &reader_ids[i]);
    }

    // Creating writer threads
    for (int i = 0; i < NUM_WRITERS; ++i) {
        pthread_create(&writers[i], NULL, writer, &writer_ids[i]);
    }

    // Waiting for threads to finish
    for (int i = 0; i < NUM_READERS; ++i) {
        pthread_join(readers[i], NULL);
    }

    for (int i = 0; i < NUM_WRITERS; ++i) {
        pthread_join(writers[i], NULL);
    }

    // Destroying semaphores
    sem_destroy(&mutex);
    sem_destroy(&wrt);

    return 0;
}
