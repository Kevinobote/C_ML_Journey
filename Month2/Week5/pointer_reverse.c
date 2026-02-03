#include <stdio.h>

int main() {
	float features[] = {10.1, 20.2, 30.3, 40.4, 50.5};
	int n = 5;

	// Start by pointing to the very last element
	// features + 4 points to &features[4]
	float *ptr = features + (n - 1);

	printf("--- Reversing Array via Pointers ---\n");

	for (int i = 0; i < n; i++) {
		printf("Index %d | Address: %p | Value: %.1f\n", (n - 1 - i), (void*)ptr, *ptr);
		
		// Move the pointer to the PREVIOUS memory location
		ptr--;
	}
	return 0;
}
