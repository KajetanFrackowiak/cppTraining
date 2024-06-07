#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

#define SIZE 85000
#define NUM_THREADS 4

int *array;
int *sorted_array;

typedef struct {
    int start;
    int end;
} ThreadData;

void merge(int *arr, int start, int mid, int end) {
    int i = start, j = mid + 1, k = 0;
    int size = end - start + 1;
    int *temp = (int*)malloc(size * sizeof(int));
    
    while (i <= mid && j <= end) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }
    while (i <= mid) {
        temp[k++] = arr[i++];
    }
    while (j <= end) {
        temp[k++] = arr[j++];
    }
    
    for (i = start, k = 0; i <= end; i++, k++) {
        arr[i] = temp[k];
    }
    
    free(temp);
}

void merge_sort(int *arr, int start, int end) {
    if (start < end) {
        int mid = start + (end - start) / 2;
        merge_sort(arr, start, mid);
        merge_sort(arr, mid + 1, end);
        merge(arr, start, mid, end);
    }
}

void* thread_sort(void* arg) {
    ThreadData *data = (ThreadData*)arg;
    merge_sort(array, data->start, data->end);
    pthread_exit(NULL);
}

void generate_random_numbers(int *arr, int size, int min, int max) {
    for (int i = 0; i < size; i++) {
        arr[i] = min + rand() % (max - min + 1);
    }
}

void merge_sections(int num_sections, int section_size) {
    for (int size = section_size; size < SIZE; size *= 2) {
        for (int start = 0; start < SIZE; start += 2 * size) {
            int mid = start + size - 1;
            int end = (start + 2 * size - 1 < SIZE) ? start + 2 * size - 1 : SIZE - 1;
            if (mid < end) {
                merge(array, start, mid, end);
            }
        }
    }
}

int main() {
    srand(time(NULL));
    
    array = (int*)malloc(SIZE * sizeof(int));
    sorted_array = (int*)malloc(SIZE * sizeof(int));
    
    generate_random_numbers(array, SIZE, 1, 1000000);
    
    pthread_t threads[NUM_THREADS];
    ThreadData thread_data[NUM_THREADS];
    
    int section_size = SIZE / NUM_THREADS;
    
    for (int i = 0; i < NUM_THREADS; i++) {
        thread_data[i].start = i * section_size;
        thread_data[i].end = (i == NUM_THREADS - 1) ? SIZE - 1 : (i + 1) * section_size - 1;
        pthread_create(&threads[i], NULL, thread_sort, &thread_data[i]);
    }
    
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }
    
    merge_sections(NUM_THREADS, section_size);
    
    // Print sorted array to verify (for debugging purposes)
    /*
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
    */
    
    free(array);
    free(sorted_array);
    
    return 0;
}
