#include <stdio.h> // Preprocessor directive: Includes standard input/output library functions

// main function: The entry point of every C program
int main() {
    // This is a single-line comment.
    /*
     * This is a multi-line comment.
     * It explains blocks of code.
     */

    // Variable declaration and initialization
    int age = 25;
    float height = 1.75;
    char initial = 'J';

    // Print statements using format specifiers
    printf("My age is %d.\n", age); // %d for integer
    printf("My height is %.2f meters.\n", height); // %.2f for float with 2 decimal places
    printf("My initial is %c.\n", initial); // %c for character

    // Return 0 indicates successful execution
    return 0;
}
