#include <stdio.h>

int main() {
	// --- Declaring an array ---
	// Syntax: dataType arrayName[size];
	int scores[5]; 

	// ---Initializing array elements ---
	// You can initialize at declaration:
	// int ages[] = {23, 30, 22, 28} 
	// int temperature[3] = {98, 100} // Remaining elements (temperature[2] will be iinitialized to 0

	// Assigning values to individual elements (using index)
	// Array indices start from 0!
	scores[0] = 85;
	scores[1] = 92;
	scores[2] = 78;
	scores[3] = 65;
	scores[4] = 90;

	// --- Accessing array elements ---
	printf("--- Accessing Array Elements ---\n");
	printf("Score at index 0: %d\n", scores[0]);
	printf("Score at index 3: %d\n", scores[3]);
	printf("\n");

	// --- Iterating through an array using a for loop ---
	printf("--- All stores in the array ---\n");
	for (int i = 0; i < 5; i++) { // Loop from index 0 upto (but not including ) 5
		printf("Score at index %d: %d\n", i, scores[i]);
	}
	printf("\n");

	// --- Calculating Sum and Average of Array Elements ---
	printf("--- Calculating Sum and Average ---");
	int sum = 0;
	int num_elements = sizeof(scores) / sizeof(scores[0]);  // Calculate number of  elements dynamically
	
	for (int i = 0; i < num_elements; i++) {
		sum += scores[i];
	}

	// Calculate average. Use float casting to ensure floating-point division
	float average = (float)sum / num_elements;

	printf("Total sum of scores: %d\n", sum);
	printf("Number of scores: %d\n", num_elements);
	printf("Average score: %.2f\n", average);
	printf("\n");

	// --- Taking user input into array ---
	printf("--- Enter 3 new scores ---\n");
	int user_scores[3]; // Declare an array for user input

	for (int i = 0; i < 3; i++) {
		printf("Enter score for student %d: ", i + 1); // User friendly prompt (1 based count)
		scanf("%d", &user_scores[i]); // Read into the current array element's address
	}

	printf("\n--- User Entered Scores ---\n");
	for (int i = 0; i < 3; i++) {
		printf("Student %d score: %d\n", i + 1, user_scores[i]);
	}
	printf("\n");

	return 0;
}
