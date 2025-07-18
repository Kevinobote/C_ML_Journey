#include <stdio.h> // Standard input/output library

// --- Function Prototypes (Declarations) ---
// These tell the compiler about the function's return type, name, and parameters
// before the function is actually defined. This allows you to call functions
// before their full definition appears in the code (e.g., calling them from main).

void greetUser(char name[]); // Function to greet a user by name
int addNumbers(int num1, int num2); // Function to add two integers and return their sum
void checkEvenOdd(int number); // Function to check if a number is even or odd
void printSeparator(); // Function to print a separator line

// --- main function (Program Execution Starts Here) ---
int main() {
    printf("--- Demonstrating Functions ---\n\n");

    // --- Calling Functions ---

    // Call greetUser function
    greetUser("Obote");
    greetUser("Hineni"); // Call it multiple times with different arguments
    printSeparator();

    // Call addNumbers function and store the result
    int sum = addNumbers(10, 20);
    printf("Sum of 10 and 20: %d\n", sum);

    int a = 5, b = 7;
    int another_sum = addNumbers(a, b); // Pass variables as arguments
    printf("Sum of %d and %d: %d\n", a, b, another_sum);
    printSeparator();

    // Call checkEvenOdd function
    checkEvenOdd(4);
    checkEvenOdd(7);
    printSeparator();

    // Demonstrate pass by value:
    // When 'x' is passed to 'checkEvenOdd', a copy of 'x's value is sent.
    // Any changes to 'number' INSIDE 'checkEvenOdd' do NOT affect 'x' in main.
    int x = 100;
    printf("Before calling checkEvenOdd, x = %d\n", x);
    checkEvenOdd(x); // Pass a copy of 'x's value
    printf("After calling checkEvenOdd, x = %d (still the same)\n", x);
    printSeparator();

    return 0; // Indicate successful program execution
}

// --- Function Definitions (Implementations) ---
// These provide the actual code/logic for each function.

// Function to greet a user
// 'name' is a local copy of the array passed to it.
void greetUser(char name[]) {
    printf("Hello, %s! Welcome to Day 9.\n", name);
}

// Function to add two integers
// 'num1' and 'num2' are local copies of the values passed.
int addNumbers(int num1, int num2) {
    int result = num1 + num2;
    // num1 = 0; // If you uncomment this, it won't affect 'a' in main() due to pass by value
    return result; // Return the sum
}

// Function to check if a number is even or odd
// 'number' is a local copy of the value passed.
void checkEvenOdd(int number) {
    if (number % 2 == 0) {
        printf("%d is an EVEN number.\n", number);
    } else {
        printf("%d is an ODD number.\n", number);
    }
}

// Function to print a separator line (no parameters, no return value)
void printSeparator() {
    printf("-----------------------------------\n");
}