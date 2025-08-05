#include <stdio.h> // For printf

// Function declarations for our simple operations
int add(int a, int b);
int subtract(int a, int b);

// --- The main concept: A function that takes a function pointer ---
// This function takes two integers and a function pointer as arguments.
// The function pointer `operation` must point to a function that takes two ints and returns an int.
int calculate(int x, int y, int (*operation)(int, int)) {
    // The `operation` pointer "points" to the function we want to call.
    // The `(*operation)` part dereferences the pointer to get the function itself,
    // and then we pass x and y as arguments.
    // The parentheses around `*operation` are essential due to operator precedence.
    return (*operation)(x, y);
}

// --- main function ---
int main() {
    printf("--- Function Pointers ---\n\n");

    // 1. Declare a function pointer
    // Syntax: return_type (*pointer_name)(parameter_types);
    int (*op_ptr)(int, int);

    // 2. Initialize the function pointer
    // Assign the address of the `add` function to the pointer.
    // The function name itself (without parentheses) acts as a pointer to the function.
    op_ptr = &add; // '&' is optional but explicit and can improve clarity

    printf("Using function pointer to call 'add':\n");
    // 3. Call the function through the pointer
    int result_add = (*op_ptr)(10, 5);
    // You can also call it without dereferencing, which is a common shortcut:
    // int result_add = op_ptr(10, 5);
    printf("Result of 10 + 5 = %d\n", result_add);
    printf("\n");

    // Re-initialize the same function pointer to point to a different function
    printf("Using the same function pointer to call 'subtract':\n");
    op_ptr = &subtract; // Now op_ptr points to the subtract function

    // Call the new function through the same pointer variable
    int result_subtract = (*op_ptr)(20, 8);
    printf("Result of 20 - 8 = %d\n", result_subtract);
    printf("\n");

    // --- Using the 'calculate' function with our function pointers ---
    printf("--- Using Function Pointers as Function Parameters ---\n");

    // Pass the 'add' function's address to our `calculate` function
    int final_add_result = calculate(50, 25, &add);
    printf("50 + 25 = %d\n", final_add_result);

    // Pass the 'subtract' function's address to the same `calculate` function
    int final_subtract_result = calculate(100, 30, &subtract);
    printf("100 - 30 = %d\n", final_subtract_result);
    printf("\n");

    return 0; // Indicate successful program execution
}


// --- Function Definitions ---

int add(int a, int b) {
    printf("  [Inside add function]\n");
    return a + b;
}

int subtract(int a, int b) {
    printf("  [Inside subtract function]\n");
    return a - b;
}