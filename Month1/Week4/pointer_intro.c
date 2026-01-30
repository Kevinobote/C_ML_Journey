#include <stdio.h>

int main() {
    int score = 95;      // A regular integer
    int *ptr = &score;   // A pointer storing the address of score

    printf("--- Day 31: Pointer Exploration ---\n");
    printf("1. Value of score: %d\n", score);
    
    // %p is the format specifier for a memory address (Pointer)
    printf("2. Memory address of score (&score): %p\n", (void*)&score);
    printf("3. Value stored in ptr: %p\n", (void*)ptr);

    // DEREFERENCING: Using the pointer to change the original variable
    *ptr = 100; 

    printf("\n4. New value of score (after *ptr = 100): %d\n", score);

    return 0;
}