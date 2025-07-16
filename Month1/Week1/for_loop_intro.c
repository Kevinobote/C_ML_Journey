#include <stdio.h> // Standard input/output library

int main() {
    // --- Example 1: Simple Counting from 1 to 5 ---
    printf("--- Counting from 1 to 5 ---\n");
    for (int i = 1; i <= 5; i++) {
        printf("Count: %d\n", i);
    }
    printf("\n"); // Add a newline for better readability between examples

    // --- Example 2: Counting Down from 10 to 1 ---
    printf("--- Counting Down from 10 to 1 ---\n");
    for (int j = 10; j >= 1; j--) {
        printf("Countdown: %d\n", j);
    }
    printf("\n");

    // --- Example 3: Counting Even Numbers from 0 to 10 ---
    printf("--- Even Numbers from 0 to 10 ---\n");
    for (int k = 0; k <= 10; k += 2) { // Increment by 2 each time
        printf("Even: %d\n", k);
    }
    printf("\n");

    // --- Example 4: Sum of numbers from 1 to 10 ---
    printf("--- Sum of numbers from 1 to 10 ---\n");
    int sum = 0; // Initialize sum to 0
    for (int num = 1; num <= 10; num++) {
        sum += num; // Equivalent to: sum = sum + num;
    }
    printf("The sum is: %d\n", sum); // Expected output: 55
    printf("\n");

    // --- Example 5: Loop with user input for range ---
    printf("--- Sum of numbers in a user-defined range ---\n");
    int start, end, total_sum = 0;

    printf("Enter the starting number: ");
    scanf("%d", &start);

    printf("Enter the ending number: ");
    scanf("%d", &end);

    // Basic input validation
    if (start > end) {
        printf("Error: Starting number cannot be greater than ending number.\n");
    } else {
        for (int i = start; i <= end; i++) {
            total_sum += i;
        }
        printf("The sum from %d to %d is: %d\n", start, end, total_sum);
    }

    return 0; // Indicate successful program execution
}