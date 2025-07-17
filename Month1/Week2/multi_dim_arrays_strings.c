#include <stdio.h> // Standard input/output library
#include <string.h> // Required for string functions like strlen()

int main() {
    // --- PART 1: Two-Dimensional Arrays (Matrices) ---

    // Declaration and Initialization of a 2D Array (3 rows, 4 columns)
    // Think of it as: arrayName[row_index][column_index]
    int matrix[3][4] = {
        {1, 2, 3, 4},    // Row 0
        {5, 6, 7, 8},    // Row 1
        {9, 10, 11, 12}  // Row 2
    };

    printf("--- Two-Dimensional Array (Matrix) --- \n");

    // Accessing individual elements
    printf("Element at matrix[0][0]: %d\n", matrix[0][0]); // Should be 1
    printf("Element at matrix[1][2]: %d\n", matrix[1][2]); // Should be 7
    printf("Element at matrix[2][3]: %d\n", matrix[2][3]); // Should be 12
    printf("\n");

    // Iterating through a 2D array using nested loops
    // Outer loop for rows, inner loop for columns
    printf("--- Printing the Matrix ---\n");
    for (int i = 0; i < 3; i++) { // Loop for rows (0 to 2)
        for (int j = 0; j < 4; j++) { // Loop for columns (0 to 3)
            printf("%4d ", matrix[i][j]); // Print element with 4 spaces padding for alignment
        }
        printf("\n"); // Move to the next line after each row
    }
    printf("\n");

    // Example: Sum of all elements in the matrix
    int total_sum = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            total_sum += matrix[i][j];
        }
    }
    printf("Sum of all elements in the matrix: %d\n", total_sum);
    printf("\n");

    // --- PART 2: Strings as Character Arrays ---

    // Declaration and Initialization of strings
    // Method 1: Using a character array (compiler adds null terminator '\0')
    char greeting[] = "Hello"; // Size will be 6 ('H', 'e', 'l', 'l', 'o', '\0')

    // Method 2: Explicitly specifying size and null terminator
    char city[5] = {'N', 'a', 'i', 'r', '\0'}; // Size 5 for "Nair" + null terminator

    // Method 3: Declaring an empty array and using string copy (from string.h)
    char name[20]; // Array to hold up to 19 characters + null terminator
    // strcpy(name, "Obote"); // We will cover strcpy later; for now, let's stick to direct initialization

    printf("--- Strings as Character Arrays ---\n");
    printf("Greeting: %s\n", greeting); // %s format specifier for strings
    printf("City: %s\n", city);
    // printf("Name: %s\n", name); // This would print garbage unless strcpy was used

    // Accessing individual characters in a string
    printf("First character of greeting: %c\n", greeting[0]); // 'H'
    printf("Third character of city: %c\n", city[2]);     // 'i'
    printf("The null terminator character: %d (ASCII value)\n", greeting[5]); // Should be 0 for '\0'

    // Iterating through a string (until the null terminator)
    printf("Greeting character by character: ");
    for (int i = 0; greeting[i] != '\0'; i++) { // Loop until the null terminator is found
        printf("%c", greeting[i]);
    }
    printf("\n");

    // Using strlen() to get string length (from <string.h>)
    // strlen() counts characters UP TO the null terminator, not including it.
    printf("Length of greeting '%s': %lu\n", greeting, strlen(greeting)); // Expected: 5
    printf("Length of city '%s': %lu\n", city, strlen(city));         // Expected: 4
    printf("\n");

    // String input (using scanf) - BE CAREFUL with scanf for strings!
    // scanf reads until whitespace, can cause buffer overflow if input is too long for array.
    char favorite_color[15]; // Array to hold up to 14 chars + null terminator
    printf("Enter your favorite color (single word): ");
    scanf("%s", favorite_color); // No '&' needed for arrays when passing to scanf for strings!
                                 // (The array name itself acts as a pointer to its first element)
    printf("Your favorite color is: %s\n", favorite_color);

    return 0; // Indicate successful program execution
}
