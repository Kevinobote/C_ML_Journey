#include <stdio.h>

int main() {
	float features[] = {0.92, 0.45, 0.77, 0.12, 0.88};
	float *ptr = features; // Start at the beginning

	printf("Walking through the features using ptr++:\n");
	printf("Initial address: %p | Value: %.2f\n", (void*)ptr, *ptr);

	// Using a for loop to move the pointer itself
	for (int i = 0; i < 4; i++) {
		ptr++; // Increment the pointer to the next float (4 bytes ahead)
		printf("Next Adress:  %p | Value: %.2f\n", (void*)ptr, *ptr);

	}

	// Pointer Subtraction: How far are we from the start?
	float *start = features;
	printf("\nDistance from start: %ld elements\n", ptr - start);

	return 0;
}
	
