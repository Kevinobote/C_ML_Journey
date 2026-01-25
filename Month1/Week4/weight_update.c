#include <stdio.h>

// 1. Function Prototype
float updateWeiht(float currentWeight, float gradient, float learningRate);

int main() {
    float Weight = 0.5;
    float grad = 0.1;
    float lr = 0.01;

    printf("Initial Weight: %.4f\n", Weight);

    // Call the function and catch the returned value
    Weight = updateWeiht(Weight, grad, lr);

    printf("Updated Weight after 1 step: %.4f\n", Weight);

    return 0;
}
// Function Definition
float updateWeiht(float currentWeight, float gradient, float learningRate) {
    // Simple update rule: weight = weight - learningRate * gradient
    float newWeight = currentWeight - (learningRate * gradient);
    return newWeight;
}