#include <stdio.h> // Standard input/output library

int main() {
    printf("--- Pointers and Arrays: Pointer Arithmetic ---\n\n");

    // 1. Arrays as Pointers (or, how array names decay to pointers)
    int numbers[] = {10, 20, 30, 40, 50};
    int size = sizeof(numbers) / sizeof(numbers[0]);

    printf("Original array elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n\n");

    // The array name 'numbers' itself acts as a pointer to its first element.
    // 'numbers' is equivalent to '&numbers[0]'
    int *ptr_to_first_element = numbers; // No '&' needed, array name decays to pointer
    // int *ptr_to_first_element = &numbers[0]; // This is also valid and explicit

    printf("Address of first element using array name: %p\n", (void *)numbers);
    printf("Address of first element using '&numbers[0]': %p\n", (void *)&numbers[0]);
    printf("Value of ptr_to_first_element: %p\n", (void *)ptr_to_first_element);
    printf("Value at ptr_to_first_element (*ptr_to_first_element): %d\n", *ptr_to_first_element); // Should be 10
    printf("\n");

    // 2. Pointer Arithmetic (Addition and Subtraction)
    // When you add an integer to a pointer, the pointer moves by that many *elements*
    // of its base type, not by that many bytes.
    // E.g., if int is 4 bytes, ptr + 1 moves 4 bytes forward.

    printf("--- Pointer Arithmetic ---\n");
    printf("Value at numbers[0] using pointer arithmetic: %d\n", *(numbers + 0)); // Same as numbers[0]
    printf("Value at numbers[1] using pointer arithmetic: %d\n", *(numbers + 1)); // Same as numbers[1]
    printf("Value at numbers[3] using pointer arithmetic: %d\n", *(numbers + 3)); // Same as numbers[3]
    printf("\n");

    // Address progression using pointer arithmetic
    printf("Address of numbers[0]: %p\n", (void *)(numbers + 0));
    printf("Address of numbers[1]: %p\n", (void *)(numbers + 1));
    printf("Address of numbers[2]: %p\n", (void *)(numbers + 2));
    printf("\n");

    // 3. Traversing Arrays using Pointers
    printf("--- Traversing Array with Pointers ---\n");
    int *current_ptr = numbers; // Initialize pointer to the start of the array

    for (int i = 0; i < size; i++) {
        printf("Element %d: Value = %d, Address = %p\n", i, *current_ptr, (void *)current_ptr);
        current_ptr++; // Move pointer to the next integer element
    }
    printf("\n");

    // Resetting pointer to start for another traversal example
    current_ptr = numbers;
    printf("--- Another Traversal (using different loop style) ---\n");
    for (int i = 0; i < size; i++) {
        printf("Element %d: Value = %d\n", i, *(current_ptr + i)); // Access using offset
    }
    printf("\n");

    // 4. Pointer Subtraction (Difference between two pointers of the same type)
    // Subtracting two pointers gives the number of elements between them.
    int *last_element_ptr = &numbers[size - 1]; // Pointer to the last element
    int *first_element_ptr = numbers;           // Pointer to the first element

    long int difference = last_element_ptr - first_element_ptr; // Result is a 'long int'
    printf("Number of elements between first and last: %ld\n", difference); // Should be size - 1 (e.g., 4)
    printf("Total size of array in elements: %ld\n", difference + 1); // Confirms the size
    printf("\n");

    // 5. Modifying Array Elements using Pointers
    printf("--- Modifying Array Elements using Pointers ---\n");
    current_ptr = numbers; // Reset to start
    for (int i = 0; i < size; i++) {
        *current_ptr = *current_ptr * 10; // Multiply each element by 10
        current_ptr++;
    }

    printf("Array after modification (elements multiplied by 10): ");
    for (int i = 0; i < size; i++) {
        printf("%d ", numbers[i]); // Print using array indexing to verify
    }
    printf("\n\n");

    return 0; // Indicate successful program execution
}