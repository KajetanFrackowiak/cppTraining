#include <stdio.h>
#include <ctype.h>

int main() {
    FILE *file;
    char ch;

    // Prompt user for filename
    printf("Enter filename: ");
    char filename[100];
    scanf("%s", filename);

    // Open file for reading
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    // Read and print characters one by one
    while ((ch = fgetc(file)) != EOF) {
        // Check for printable characters (avoid non-printable characters)
        if (isprint(ch)) {
            printf("%c", ch + 1);
        }
    }

    // Close the file
    fclose(file);

    return 0;
}