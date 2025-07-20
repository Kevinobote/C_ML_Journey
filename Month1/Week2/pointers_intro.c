#include <stdio.h> // Standard input/output library

// Function prototype for pass by reference example
// It takes a pointer to an integer as a parameter
void incrementValue(int *ptr);

int main() {
    printf("--- Pointers: Introduction ---\n\n");

    // 1. Declaring and Initializing Variables
    int my_age = 30;
    int your_score = 95;

    printf("Original values:\n");
    printf("my_age = %d\n", my_age);
    printf("your_score = %d\n", your_score);
    printf("\n");

    // 2. The Address-Of Operator (&)
    // The '&' operator gives you the memory address of a variable.
    // "%p" is the format specifier for printing memory addresses (pointers).
    printf("Memory Addresses:\n");
    printf("Address of my_age: %p\n", (void *)&my_age); // Cast to (void *) for consistent printing
    printf("Address of your_score: %p\n", (void *)&your_score);
    printf("\n");

    // 3. Declaring Pointer Variables
    // Syntax: dataType *pointerName;
    // A pointer variable stores a memory address of a variable of that dataType.
    int *age_ptr;     // Declares a pointer to an integer
    float *gpa_ptr;   // Declares a pointer to a float (not used, just for example)

    // 4. Initializing Pointers
    // Assign the address of 'my_age' to 'age_ptr'
    age_ptr = &my_age;

    printf("Pointer Values:\n");
    printf("Value of age_ptr (address it holds): %p\n", (void *)age_ptr); // Should be same as address of my_age
    printf("\n");

    // 5. The Dereference Operator (*)
    // The '*' operator, when used with a pointer, gives you the VALUE at the memory address
    // that the pointer is holding. It "dereferences" the pointer.
    printf("Dereferencing Pointers:\n");
    printf("Value at address pointed to by age_ptr (*age_ptr): %d\n", *age_ptr); // Should be 30 (value of my_age)
    printf("\n");

    // 6. Modifying Variable Values Using Pointers
    printf("Modifying value via pointer:\n");
    printf("my_age before modification: %d\n", my_age);
    *age_ptr = 31; // Change the value at the address age_ptr points to
                   // This directly changes 'my_age'
    printf("my_age after modification via pointer: %d\n", my_age);
    printf("Value at address pointed to by age_ptr (*age_ptr): %d\n", *age_ptr); // Still 31
    printf("\n");

    // 7. Null Pointers
    // A null pointer points to nothing. It's good practice to initialize pointers to NULL
    // if they are not pointing to a valid memory location yet.
    int *null_ptr = NULL;
    printf("Null pointer value: %p\n", (void *)null_ptr);
    // printf("Attempting to dereference a NULL pointer: %d\n", *null_ptr); // !!! DANGEROUS: Will cause a segmentation fault (crash) !!!
    printf("Warning: Dereferencing a NULL pointer leads to a crash.\n");
    printf("Always check if a pointer is NULL before dereferencing if unsure.\n");
    printf("\n");


    // 8. Pointers and Functions (Pass by Reference)
    // Recall Day 9: pass by value. Here, we pass the ADDRESS of a variable.
    int count = 5;
    printf("Before incrementValue function: count = %d\n", count);
    incrementValue(&count); // Pass the ADDRESS of 'count'
    printf("After incrementValue function: count = %d\n", count); // 'count' has changed!
    printf("\n");

    return 0; // Indicate successful program execution
}

// Function definition for incrementValue
// 'ptr' receives the memory address of the integer passed from main.
void incrementValue(int *ptr) {
    printf("  Inside incrementValue: Value pointed to by ptr (*ptr) = %d\n", *ptr);
    (*ptr)++; // Dereference ptr, then increment the value at that address
              // Parentheses are important: *ptr++ would increment ptr (the address), then dereference
    printf("  Inside incrementValue: Value pointed to by ptr (*ptr) after increment = %d\n", *ptr);
}