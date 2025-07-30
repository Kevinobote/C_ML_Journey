#include <stdio.h>   // For file I/O functions
#include <stdlib.h>  // For exit(), malloc, free
#include <string.h>  // For strlen, strcpy
#include <time.h>    // For time functions (to get current time for logging)

#define MAX_LOG_MESSAGE 100
#define NUM_INTEGERS_TO_WRITE 5
#define BUFFER_SIZE 256

// Function to log a message with timestamp to a file
// Returns 0 on success, -1 on failure
int log_event(const char *log_filename, const char *message) {
    FILE *log_file = fopen(log_filename, "a"); // Open in append mode
    if (log_file == NULL) {
        perror("Error opening log file");
        return -1;
    }

    time_t now = time(NULL);
    char *time_str = ctime(&now); // Returns string like "Wed Jul 30 11:06:35 2025\n"
    time_str[strlen(time_str) - 1] = '\0'; // Remove trailing newline

    fprintf(log_file, "[%s] %s\n", time_str, message);

    if (ferror(log_file)) { // Check for errors during writing
        perror("Error writing to log file");
        fclose(log_file);
        return -1;
    }

    fclose(log_file); // Close the file
    return 0; // Success
}

int main() {
    printf("--- Advanced File I/O: Error Handling & Binary Files ---\n\n");

    const char *text_log_file = "event_log.txt";
    const char *binary_data_file = "binary_numbers.bin";

    // --- PART 1: Robust Text File Logging with Error Handling ---

    printf("--- Robust Text File Logging ---\n");
    if (log_event(text_log_file, "Program started successfully.") == 0) {
        printf("Logged: Program started.\n");
    } else {
        fprintf(stderr, "Failed to log 'Program started'.\n");
    }

    if (log_event(text_log_file, "Performing operation A.") == 0) {
        printf("Logged: Operation A.\n");
    } else {
        fprintf(stderr, "Failed to log 'Operation A'.\n");
    }

    // Simulate an error (e.g., trying to write to a read-only file or full disk)
    // For demonstration, we can simulate an error by trying to open an invalid path or similar.
    // Real errors are harder to force programmatically without specific scenarios.
    // For now, assume log_event handles the fopen errors.

    printf("\nReading log file '%s' contents:\n", text_log_file);
    FILE *read_log_file = fopen(text_log_file, "r");
    if (read_log_file == NULL) {
        perror("Error opening log file for reading");
        // No exit here, continue to binary part if possible
    } else {
        char buffer[BUFFER_SIZE]; // Defined at top
        while (fgets(buffer, BUFFER_SIZE, read_log_file) != NULL) {
            printf("%s", buffer);
        }

        // After reading all lines, check for EOF or error
        if (feof(read_log_file)) {
            printf("\nReached End Of File (EOF).\n");
        }
        if (ferror(read_log_file)) {
            perror("Error during reading log file");
        }
        fclose(read_log_file);
    }
    printf("\n");

    // --- PART 2: Binary File I/O (fread, fwrite) ---

    printf("--- Binary File I/O ---\n");
    int numbers_to_write[NUM_INTEGERS_TO_WRITE] = {100, 200, 300, 400, 500};
    int numbers_read[NUM_INTEGERS_TO_WRITE];

    // Open for writing in binary mode ("wb")
    FILE *bin_file = fopen(binary_data_file, "wb");
    if (bin_file == NULL) {
        perror("Error opening binary file for writing");
        return 1;
    }

    printf("Writing %d integers to binary file '%s'...\n", NUM_INTEGERS_TO_WRITE, binary_data_file);
    // fwrite(data_ptr, size_of_each_item, num_items, file_stream)
    size_t items_written = fwrite(numbers_to_write, sizeof(int), NUM_INTEGERS_TO_WRITE, bin_file);

    if (items_written != NUM_INTEGERS_TO_WRITE) {
        fprintf(stderr, "Error: Only %zu out of %d items were written to binary file.\n",
                items_written, NUM_INTEGERS_TO_WRITE);
        if (ferror(bin_file)) { // Check if a specific error occurred
            perror("Error during binary file writing");
        }
        fclose(bin_file);
        return 1;
    }
    fclose(bin_file);
    printf("Successfully wrote %zu items to binary file.\n\n", items_written);

    // Open for reading in binary mode ("rb")
    bin_file = fopen(binary_data_file, "rb");
    if (bin_file == NULL) {
        perror("Error opening binary file for reading");
        return 1;
    }

    printf("Reading %d integers from binary file '%s'...\n", NUM_INTEGERS_TO_WRITE, binary_data_file);
    // fread(buffer_ptr, size_of_each_item, num_items, file_stream)
    size_t items_read = fread(numbers_read, sizeof(int), NUM_INTEGERS_TO_WRITE, bin_file);

    if (items_read != NUM_INTEGERS_TO_WRITE) {
        fprintf(stderr, "Error: Only %zu out of %d items were read from binary file.\n",
                items_read, NUM_INTEGERS_TO_WRITE);
        if (ferror(bin_file)) { // Check if a specific error occurred
            perror("Error during binary file reading");
        } else if (feof(bin_file)) { // Check if EOF was reached prematurely
            fprintf(stderr, "End of file reached prematurely during binary read.\n");
        }
        fclose(bin_file);
        return 1;
    }

    printf("Successfully read %zu items from binary file:\n", items_read);
    for (int i = 0; i < NUM_INTEGERS_TO_WRITE; i++) {
        printf("  %d\n", numbers_read[i]);
    }

    fclose(bin_file);
    printf("\n");

    // Clean up created files (optional)
    // remove(text_log_file);
    // remove(binary_data_file);

    return 0; // Indicate successful program execution
}