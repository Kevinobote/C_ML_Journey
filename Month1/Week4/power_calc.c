#include <stdio.h>

// 1. Function Prototype (The Preview)
int calculateSquare(int num);

int main() {
    int myNumber = 5;
    int result;

    printf("Original value before function: %d\n", myNumber);

    // 2. Calling the function
    result = calculateSquare(myNumber);

    printf("Result of square function: %d\n", result);
    printf("Original value after function (remains 5): %d\n", myNumber);

    return 0;
}

// 3. Function Definition
int calculateSquare(int x) {
    x = x * x; // Changing the local copy 'x'
    return x;
}