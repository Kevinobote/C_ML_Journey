#include <stdio.h>
#include <stdlib.h>

// Use a typedef to create a custom data type for our analysis results
typedef struct {
    double average;
    double min;
    double max;
    int count;
} AnalysisResult_t;

// Function to read numbers from a file into a dynamically allocated array
// Returns a pointer to the array, or NULL on failure.
double* read_data_from_file(const char* filename, int* count) {
    FILE* file_ptr = fopen(filename, "r");
    if (file_ptr == NULL) {
        perror("Error opening input file");
        return NULL;
    }

    // Step 1: Count the number of lines to determine array size
    int line_count = 0;
    double temp_val;
    while (fscanf(file_ptr, "%lf", &temp_val) == 1) {
        line_count++;
    }

    // Rewind to the beginning of the file for the actual reading
    rewind(file_ptr);

    // Step 2: Dynamically allocate memory for the array
    double* data_array = (double*)malloc(line_count * sizeof(double));
    if (data_array == NULL) {
        perror("Memory allocation failed");
        fclose(file_ptr);
        return NULL;
    }

    // Step 3: Read the numbers into the allocated array
    *count = 0;
    while (fscanf(file_ptr, "%lf", &data_array[*count]) == 1) {
        (*count)++;
    }

    fclose(file_ptr);
    return data_array;
}

// Function to analyze the data and populate the AnalysisResult_t struct
void analyze_data(const double* data, int count, AnalysisResult_t* result) {
    if (count <= 0 || data == NULL) {
        // Handle empty or invalid data
        result->average = 0.0;
        result->min = 0.0;
        result->max = 0.0;
        result->count = 0;
        return;
    }

    // Initialize with the first element
    double sum = data[0];
    double min_val = data[0];
    double max_val = data[0];

    // Iterate through the rest of the elements
    for (int i = 1; i < count; i++) {
        sum += data[i];
        if (data[i] < min_val) {
            min_val = data[i];
        }
        if (data[i] > max_val) {
            max_val = data[i];
        }
    }

    // Populate the result struct members
    result->average = sum / count;
    result->min = min_val;
    result->max = max_val;
    result->count = count;
}

// Function to write the analysis results to a file
void write_results_to_file(const char* filename, const AnalysisResult_t* result) {
    FILE* file_ptr = fopen(filename, "w");
    if (file_ptr == NULL) {
        perror("Error opening output file");
        return;
    }

    fprintf(file_ptr, "--- Data Analysis Report ---\n");
    fprintf(file_ptr, "Total numbers processed: %d\n", result->count);
    fprintf(file_ptr, "Average: %.2f\n", result->average);
    fprintf(file_ptr, "Minimum value: %.2f\n", result->min);
    fprintf(file_ptr, "Maximum value: %.2f\n", result->max);

    fclose(file_ptr);
}

int main(int argc, char* argv[]) {
    // Check for correct command-line arguments
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <input_filename>\n", argv[0]);
        return 1;
    }

    const char* input_filename = argv[1];
    const char* output_filename = "analysis_report.txt";

    int data_count = 0;
    double* data_array = read_data_from_file(input_filename, &data_count);

    // Error handling for file read and memory allocation
    if (data_array == NULL) {
        return 1; // An error message has already been printed
    }

    // Perform the analysis
    AnalysisResult_t analysis_results;
    analyze_data(data_array, data_count, &analysis_results);

    // Print results to the console
    printf("--- Data Analysis Results ---\n");
    printf("Total numbers processed: %d\n", analysis_results.count);
    printf("Average: %.2f\n", analysis_results.average);
    printf("Minimum value: %.2f\n", analysis_results.min);
    printf("Maximum value: %.2f\n", analysis_results.max);
    printf("\n");

    // Write results to an output file
    write_results_to_file(output_filename, &analysis_results);
    printf("Results have also been written to '%s'.\n", output_filename);

    // Clean up dynamically allocated memory
    free(data_array);
    data_array = NULL;

    return 0;
}