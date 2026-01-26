#include <stdio.h>

int main() {
    float data[] = {-1.5, 2.0, -0.2, 3.5, 0.0};
    int n = 5;

    printf("Original Data: ");
    for(int i = 0; i < n; i++) printf("%.1f ", data[i]);
    printf("\n");

    // Task 1: Multiply all elements by 2 (Scalar Scaling)
    for(int i = 0; i < n; i++) {
        data[i] = data[i] * 2.0;
    }

    // Task 2: Apply Threshold (ReLU)
    // If element is less than 0, set it to 0
    for(int i = 0; i < n; i++) {
        if(data[i] < 0) {
            data[i] = 0;
        }
    }

    printf("Transformed Data: ");
    for(int i = 0; i < n; i++) printf("%.1f ", data[i]);
    printf("\n");

    return 0;
}