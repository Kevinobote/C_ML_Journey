#include <stdio.h>

// Function takes a POINTER to a float
void updateWeight(float *w, float increment) {
    printf("--- Inside Function ---\n");
    printf("Address received: %p\n", (void*)w);
    
    // Modify the value at that address
    *w = *w + increment; 
    
    printf("Value updated at the source.\n");
}

int main() {
    float model_weight = 0.75;

    printf("Before function call: weight = %.2f, address = %p\n", model_weight, (void*)&model_weight);

    // Pass the ADDRESS of model_weight using &
    updateWeight(&model_weight, 0.05);

    printf("\nAfter function call:  weight = %.2f\n", model_weight);

    return 0;
}
