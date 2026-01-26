#include <stdio.h>

int main() {
    // Accurracies for 6 different versions of ypur Agri-ML model
    float accuracies[] = {0.82, 0.91, 0.78, 0.94, 0.88, 0.85};
    int nuum_models = 6;

    float max_val = accuracies[0]; // Start with the first element
    int best_index = 0;            // Keep track of where it is

    for (int i = 1; i < nuum_models; i++) {
        if (accuracies[i] > max_val) {
            max_val = accuracies[i];
            best_index = i;  // Store the index of the new maximum
        }
    }

    printf("Analyzed %d model versions...\n", nuum_models);
    printf("Highest Accuracy: %.2f\n", max_val);
    printf("Best Model Version (Index): %d\n", best_index);

    return 0;
    
}