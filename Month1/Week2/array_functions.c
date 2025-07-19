#include <stdio.h>

// --- Function Prototypes ---
// Notice how array parameters are declared: type arrayName[] or type *arrayName
// It's good practice to also pass the size of the array, as C functions
// don't inherently know the size of an array passed to them.

void printArray(int arr[], int size); // Function to print integer array elements
int sumArray(int arr[], int size);    // Function to calculate sum of array elements
float averageArray(int arr[], int size); // Function to calculate average of array elements
void modifyArray(int arr[], int size); // Function to modify array elements

// --- main function ---
int main() {
    int myNumbers[] = {10, 20, 30, 40, 50};
    int size = sizeof(myNumbers) / sizeof(myNumbers[0]); // Calculate size dynamically

    printf("--- Original Array ---\n");
    printArray(myNumbers, size); // Pass the array and its size

    printf("\n--- Sum and Average ---\n");
    int totalSum = sumArray(myNumbers, size);
    printf("Sum of array elements: %d\n", totalSum);

    float avg = averageArray(myNumbers, size);
    printf("Average of array elements: %.2f\n", avg);

    printf("\n--- Modifying Array in a Function ---\n");
    printf("Array before modification:\n");
    printArray(myNumbers, size);

    modifyArray(myNumbers, size); // Call function that modifies the array
    printf("Array after modification (elements doubled):\n");
    printArray(myNumbers, size); // Notice the original array in main has changed!

    printf("\n");

    // Example with another array
    int scores[] = {75, 80, 95};
    int scores_size = sizeof(scores) / sizeof(scores[0]);

    printf("--- Another Array (Scores) ---\n");
    printArray(scores, scores_size);
    printf("Sum of scores: %d\n", sumArray(scores, scores_size));

    return 0;
}

// --- Function Definitions ---

// Function to print array elements
// When an array is passed as a parameter, what's actually passed is the MEMORY ADDRESS
// of its first element. So 'arr' here is a pointer to the first element of the original array.
void printArray(int arr[], int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i < size - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

// Function to calculate the sum of array elements
int sumArray(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}

// Function to calculate the average of array elements
float averageArray(int arr[], int size) {
    if (size == 0) { // Avoid division by zero
        return 0.0f;
    }
    int sum = sumArray(arr, size); // Reuse sumArray function
    return (float)sum / size;
}

// Function to modify array elements
// Since 'arr' is essentially a pointer to the original array,
// modifications made inside this function WILL affect the original array in main.
void modifyArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = arr[i] * 2; // Double each element
    }
}