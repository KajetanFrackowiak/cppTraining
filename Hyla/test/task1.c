#include <pthread.h>
#include <stdio.h>

#define BUFFER_SIZE 10

int buffer[BUFFER_SIZE];
int count = 0;
int in = 0;
int out = 0;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t not_empty = PTHREAD_COND_INITIALIZER;
pthread_cond_t not_full = PTHREAD_COND_INITIALIZER;

void *producer(void *param) {
	int item;
	while (1) {
		item = rand() % 100;
		
		pthread_mutex_lock(&mutex);

		while (count == BUFFER_SIZE) {
			pthread_cond_wait(&not_full, &mutex);
		}

		buffer[in] = item;
		in = (in + 1) % BUFFER_SIZE;
		count++;

		printf("Produced: %d\n", item);

		pthread_cond_signal(&not_empty);
		pthread_mutex_unlock(&mutex);

		sleep(1); // Simulate time taken to produce and item
		}
}

void *consumer(void *param) {
	int item;
	while (1) {
		pthread_mutex_lock(&mutex);

		while (count == 0) {
			pthread_cond_wait(&not_empty, &mutex);
		}

		item = buffer[out];
		out = (out + 1) % BUFFER_SIZE;
		count--;

		printf("Consumed: %d\n", item);

		pthread_cond_signal(&not_full);
		pthread_mutex_unlock(&mutex);

		sleep(1);
	}
}

int main() {
	pthread_t tid1, tid2;

	pthread_create(&tid1, NULL, producer, NULL);
	pthread_create(&tid2, NULL, consumer, NULL);

	pthread_join(tid1, NULL);
	pthread_join(tid2, NULL);

	pthread_mutex_destroy(&mutex);
	pthread_cond_destroy(&not_empty);
	pthread_cond_destroy(&not_full);

	return 0;
}