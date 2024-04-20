#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file;
    char filename[100];
    char text[1000];

    printf("Enter filename to save text: ");
    scanf("%s", filename);

    file = fopen(filename, "w");
    if (file == NULL) {
        fprintf(stderr, "Error opening file.\n");
        return 1;
    }

    printf("Enter text to save to file (max 1000 characters):\n");
    scanf(" %[^\n]", text);  // %[^\n] to read spaces as well

    fprintf(file, "%s", text);
    fclose(file);

    file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening file for reading.\n");
        return 1;
    }

    printf("\nText read from file:\n");
    while (fgets(text, sizeof(text), file) != NULL) {
        printf("%s", text);
    }

    fclose(file);

    return 0;
}