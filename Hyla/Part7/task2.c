#include <stdio.h>
#include <ctype.h>

int main() {
    FILE *readFile, *writeFile;
    char ch;

    // Prompt user for filenames
    printf("Enter the name of the file to read: ");
    char filename[100];
    scanf("%s", filename);

    printf("Enter the name of the file to write the modified content: ");
    char newFilename[100];
    scanf("%s", newFilename);

    // Open file for reading
    readFile = fopen(filename, "r");
    if (readFile == NULL) {
        printf("Error opening file for reading!\n");
        return 1;
    }

    // Open file for writing
    writeFile = fopen(newFilename, "w");
    if (writeFile == NULL) {
        printf("Error opening file for writing!\n");
        fclose(readFile); // Close read file even if write fails
        return 1;
    }

    // Read and write characters with modification
    while ((ch = fgetc(readFile)) != EOF) {
        if (isprint(ch)) {
            ch++;
            fputc(ch, writeFile); // Write modified character to new file
        }
    }

    // Close files
    fclose(readFile);
    fclose(writeFile);

    return 0;
}
