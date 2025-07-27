#include <stdio.h>   // For file I/O functions (fopen, fclose, fprintf, fscanf, fgets, fputs)
#include <stdlib.h>  // For exit()
#include <string.h>  // For strlen() (optional, if you're writing fixed strings)

#define BUFFER_SIZE 256 // Define a buffer size for reading lines

int main() {
    printf("--- File I/O: Reading from and Writing to Files ---\n\n");

    FILE *file_ptr; // Declare a file pointer (FILE is a structure defined in stdio.h)
    char filename[] = "my_data.txt"; // Name of the file we'll work with

    // --- PART 1: Writing Data to a File ---

    printf("--- Writing data to '%s' ---\n", filename);

    // Open the file in "write" mode ("w").
    // If the file exists, its content will be truncated (erased).
    // If the file does not exist, it will be created.
    file_ptr = fopen(filename, "w");

    // Always check if fopen was successful!
    if (file_ptr == NULL) {
        perror("Error opening file for writing"); // perror prints a system-specific error message
        return 1; // Indicate an error
    }

    // Write a string to the file using fputs()
    fputs("Hello, C File I/O!\n", file_ptr);
    fputs("This is the second line.\n", file_ptr);

    // Write formatted data to the file using fprintf()
    int number = 123;
    float pi = 3.14159f;
    fprintf(file_ptr, "The number is: %d\n", number);
    fprintf(file_ptr, "Pi is approximately: %.2f\n", pi);
    fprintf(file_ptr, "End of writing data.\n");

    // Close the file when done writing. This flushes buffers and releases resources.
    fclose(file_ptr);
    printf("Data successfully written to '%s'.\n\n", filename);


    // --- PART 2: Reading Data from a File ---

    printf("--- Reading data from '%s' ---\n", filename);

    // Open the file in "read" mode ("r").
    // The file must exist, otherwise fopen will return NULL.
    file_ptr = fopen(filename, "r");

    // Always check if fopen was successful!
    if (file_ptr == NULL) {
        perror("Error opening file for reading");
        return 1; // Indicate an error
    }

    char buffer[BUFFER_SIZE]; // Buffer to store data read from the file
    int read_number;
    float read_pi;

    // Reading line by line using fgets()
    printf("Reading line by line with fgets:\n");
    while (fgets(buffer, BUFFER_SIZE, file_ptr) != NULL) {
        printf("%s", buffer); // fgets includes the newline character if present
    }
    printf("Finished reading lines.\n\n");

    // !!! IMPORTANT: To re-read from the beginning, you must either:
    // 1. Close and reopen the file, OR
    // 2. Use rewind(file_ptr);
    // Let's close and reopen for demonstration clarity.
    fclose(file_ptr);

    file_ptr = fopen(filename, "r"); // Reopen the file for reading
    if (file_ptr == NULL) {
        perror("Error re-opening file for reading");
        return 1;
    }

    // Reading formatted data using fscanf()
    printf("Reading formatted data with fscanf:\n");
    // fscanf reads formatted input until it finds whitespace or conversion mismatch
    // It returns the number of items successfully read.
    char temp_str[50]; // To consume "The number is:" etc.

    // Read the first two lines (fputs content) to advance file pointer
    fgets(buffer, BUFFER_SIZE, file_ptr); // "Hello, C File I/O!\n"
    fgets(buffer, BUFFER_SIZE, file_ptr); // "This is the second line.\n"

    // Now read the formatted lines
    // "The number is: 123"
    if (fscanf(file_ptr, "%s %s %s %d\n", temp_str, temp_str, temp_str, &read_number) == 4) {
        printf("Read number: %d\n", read_number);
    } else {
        printf("Failed to read number from file.\n");
    }

    // "Pi is approximately: 3.14"
    if (fscanf(file_ptr, "%s %s %s %f\n", temp_str, temp_str, temp_str, &read_pi) == 4) {

        printf("Read Pi: %.2f\n", read_pi);
    } else {
        printf("Failed to read Pi from file.\n");
    }

    // Close the file after reading
    fclose(file_ptr);
    printf("Data successfully read from '%s'.\n\n", filename);

    return 0; // Indicate successful program execution
}