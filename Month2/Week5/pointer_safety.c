#include <stdio.h>

int main () {
	int sensor_reading = 24;

	// 1. Initialize a pointer to NULL (Safety first!)
	int *ptr = NULL;

	printf("Pointer initialized to: %p\n", (void*)ptr);

	// 2. Defensive check: Only use if not NULL
	if (ptr != NULL) {
		printf("Value: %d\n", *ptr);

	} else {
		printf("Warning: Pointer is NULL. Assigning address now ...\n");
	}
	// 3. Assign the address to our variable
	ptr = &sensor_reading;

	if (ptr != NULL) {
		printf("Success! Pointer now points to address %p\n", (void*)ptr);
		printf("Dereferenced Value (Sensor Reading): %d\n\n", *ptr);
	}

	return 0;
}
