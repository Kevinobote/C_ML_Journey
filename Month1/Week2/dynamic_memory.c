#include <stdio.h>  // For printf, scanf
#include <stdlib.h> // For malloc, calloc, free, exit

int main() {
    printf("--- Dynamic Memory Allocation ---\n\n");

    int num_elements; // To store the number of elements the user wants
    int *dynamic_array; // A pointer to hold the base address of our dynamic array

    // 1. Get user input for the number of elements
    printf("Enter the number of integers you want to store: ");
    scanf("%d", &num_elements);

    // Input validation (basic check)
    if (num_elements <= 0) {
        printf("Number of elements must be positive. Exiting.\n");
        return 1; // Indicate an error
    }

    // 2. Allocate memory using malloc()
    // malloc(size_in_bytes) returns a void* pointer to the allocated memory,
    // or NULL if allocation fails.
    // We cast it to the desired pointer type (int*).
    dynamic_array = (int *)malloc(num_elements * sizeof(int));

    // 3. Check if malloc() allocation was successful
    if (dynamic_array == NULL) {
        printf("Memory allocation failed! Exiting program.\n");
        return 1; // Indicate an error
    }

    printf("Memory allocated successfully for %d integers.\n", num_elements);

    // 4. Populate the dynamic array with user input
    printf("Enter %d integers:\n", num_elements);
    for (int i = 0; i < num_elements; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &dynamic_array[i]); // Use array-like indexing with the pointer
        // You could also use pointer arithmetic: scanf("%d", (dynamic_array + i));
    }
    printf("\n");

    // 5. Print the elements of the dynamic array
    printf("Elements in the dynamic array:\n");
    for (int i = 0; i < num_elements; i++) {
        printf("Element %d: %d\n", i + 1, dynamic_array[i]);
        // Or using pointer dereferencing: printf("Element %d: %d\n", i + 1, *(dynamic_array + i));
    }
    printf("\n");

    // --- Brief example of calloc() ---
    // calloc(num_elements, element_size) allocates memory and initializes all bytes to zero.
    // This is useful if you need memory that's already zeroed out.
    int *calloc_array;
    printf("--- Using calloc() ---\n");
    printf("Allocating 3 integers using calloc (should be zeroed):\n");
    calloc_array = (int *)calloc(3, sizeof(int));
    if (calloc_array == NULL) {
        printf("calloc failed.\n");
        // No exit here, as we still want to free dynamic_array
    } else {
        printf("Elements after calloc (should be 0s): [");
        for (int i = 0; i < 3; i++) {
            printf("%d", calloc_array[i]);
            if (i < 2) printf(", ");
        }
        printf("]\n\n");
    }

    // 6. Free the dynamically allocated memory
    // CRITICAL: Always free memory once you are done with it to prevent memory leaks.
    printf("Freeing dynamically allocated memory...\n");
    free(dynamic_array);
    dynamic_array = NULL; // Good practice to set pointer to NULL after freeing

    if (calloc_array != NULL) { // Only free if it was successfully allocated
        free(calloc_array);
        calloc_array = NULL;
    }

    printf("Memory freed successfully.\n");
    printf("Attempting to access freed memory: This is DANGEROUS and can crash your program!\n");
    // printf("Value after free (DANGEROUS): %d\n", dynamic_array[0]); // !!! DO NOT DO THIS IN REAL CODE !!!

    return 0; // Indicate successful program execution
}