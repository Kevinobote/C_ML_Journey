#include <stdio.h>

int main() {
	int data[] = {10, 20, 30, 40, 50};
	int *ptr = data; // Same as writing ptr = &data[0]

	printf("Array Address: %p\n", (void*)data);
	printf("Pointer Value: %p\n\n", (void*)ptr);

	// 1. Accessing via standard index
	printf("Using Indexing: data[2] = %d\n", data[2]);

	// Accessing via Pointer (Dereferencing with offset)
	// *(ptr + 2) means : Go to ptr, move 2 spaces, then get the value
	printf("Using Pointers: *(ptr + 2) = %d\n", *(ptr +2));

	// 3. Printing all elements using ONLY the pointer
	for (int i = 0; i < 5; i++) {
		printf("Adress: %p | Values: %d\n", (void*)(ptr + i), *(ptr + i));
	}
	
	return 0;
}
