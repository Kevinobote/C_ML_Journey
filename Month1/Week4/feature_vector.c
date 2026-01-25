#include <stdio.h>

int main() {
    // 1. Declare and initialize an array of features
    float features[5] = {1.2, 3.4, 0.5, 2.2, 1.8};
    float sum = 0.0;

    printf("Feature Vector: [ ");
    
    // 2. Accessing elements using a for loop
    for (int i = 0; i < 5; i++) {
        printf("%.1f ", features[i]);
        sum += features[i]; // Accumulating the sum
    }
    
    printf("]\n");

    // 3. Calculating and printing the average
    float average = sum / 5;
    printf("Total Sum of Features: %.2f\n", sum);
    printf("Average Feature Value: %.2f\n", average);

    return 0;
}
