#include <stdio.h>

int main() {
    FILE *file;
    char filename[100];
    int number, sum = 0;
    float average, count;

    printf("Enter filename: ");
    scanf("%s", filename);

    file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening the file.\n");
        return 1;
    }

    while (fscanf(file, "%d", &number) == 1) {
        sum += number;
        count++;
    }
    fclose(file);

    if (count != 0) {
        average = (float)sum / count;
    } else {
        fprintf(stderr, "No data to calculate.");
        return 1;
    }

    printf("Sum of the numbers: %d\n", sum);
    printf("Arithmetic average: %.2f\n", average);

    return 0;
}