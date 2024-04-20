#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_RECORDS 5

typedef struct {
    char name[50];
    char surname[50];
} Record;

int compare_records(const void *a, const void *b) {
    Record *record_a = (Record *)a;
    Record *record_b = (Record *)b;
    return strcmp(record_a->surname, record_b->surname);
}

int main() {
    FILE *file;
    char filename[100];
    Record records[MAX_RECORDS];

    printf("Enter filename where files will be saved: ");
    scanf("%s", filename);

    file = fopen(filename, "w");
    if (file == NULL) {
        fprintf(stderr, "Error opening file");
        return 1;
    }

    for (int i = 0; i < MAX_RECORDS; i++) {
        printf("Write name: ");
        scanf("%s", records[i].name);
        printf("Write surname: ");
        scanf("%s", records[i].surname);

        fprintf(file, "%s,%s\n", records[i].name, records[i].surname);
    }
    fclose(file);

    qsort(records, MAX_RECORDS, sizeof(Record), compare_records);

    printf("\nSorted list\n");
    for (int i = 0; i < MAX_RECORDS; i++) {
        printf("%s, %s\n", records[i].name, records[i].surname);
    }

    return 0;
}

