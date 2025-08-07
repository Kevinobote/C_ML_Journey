#include <stdio.h>

int main() {
    printf("--- Pointers and Arrays: A Deeper Dive ---\n\n");

    int numbers[] = {10, 20, 30, 40, 50};
    int size = sizeof(numbers) / sizeof(numbers[0]);

    // 1. An Array Name is a Pointer to the First Element
    // The array name 'numbers' holds the memory address of its first element.
    printf("Address of the array: %p\n", numbers);
    printf("Address of the first element: %p\n", &numbers[0]);
    printf("Value of the first element: %d\n\n", *numbers); // Dereferencing the array name

    // 2. Accessing Elements with Array Indexing (the familiar way)
    printf("Accessing elements with array indexing:\n");
    for (int i = 0; i < size; i++) {
        printf("Element at index %d: %d\n", i, numbers[i]);
    }
    printf("\n");

    // 3. Accessing Elements with Pointer Arithmetic
    // We can use a pointer to iterate through the array.
    printf("Accessing elements with pointer arithmetic:\n");
    int *ptr = numbers; // 'ptr' now points to the first element (numbers[0])

    for (int i = 0; i < size; i++) {
        // 'ptr + i' calculates the address of the i-th element.
        // It's not just a simple addition; the compiler multiplies 'i' by sizeof(int).
        printf("Element at address %p: %d\n", (ptr + i), *(ptr + i));
    }
    printf("\n");
    
    // 4. Using the array name itself with pointer arithmetic
    printf("Using array name with pointer arithmetic:\n");
    for (int i = 0; i < size; i++) {
        printf("Element at index %d: %d\n", i, *(numbers + i));
    }
    printf("\n");

    // 5. The Key Difference: Array Name vs. Pointer Variable
    // An array name is a constant pointer. You cannot change what it points to.
    // A pointer variable is a regular variable. You can change what it points to.

    // This is allowed:
    int *p = numbers;
    p++; // The pointer 'p' now points to numbers[1]
    printf("Pointer 'p' now points to: %d\n", *p);

    // This is NOT allowed and would cause a compile-time error:
    // numbers++; // You cannot reassign the array name 'numbers'

    return 0;
}