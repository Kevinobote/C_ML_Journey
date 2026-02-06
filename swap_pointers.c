#include <stdio.h>

// Function definition using pointers
void swap(float *a, float *b) {
	float temp;

	temp = *a;  // Store value at adress 'a' in temp
	*a = *b;    // Put value at address 'b' into address 'a'
	*b = temp;  // Put temp value into address 'b'
}

int main() {
	float lr_alpha = 0.01;
	float lr_beta = 0.05;

	printf("Before Swap:\n");
	printf("Alpha: %.2f | Beta: %.2f\n", lr_alpha, lr_beta);

	// Pass the addresses!
	swap(&lr_alpha, &lr_beta);

	printf("\nAfter Swap:\n");
	printf("Alpha: %.2f | Beta: %.2f\n", lr_alpha, lr_beta);

	return 0;
}
