#include <stdio.h> 

int main () {
	int score; // Declare an integer variable to store the score

	// Prompt the user to enter their score
	printf("Enter the student's score (0-100): ");

	// Read the score from the user
	// The '&' before the 'score' is crucial: it gives scanf the memory address of 'score'
	scanf("%d", &score);

	// --- Using if, else if, and else for grading ---
	
	// First, check for valid input (optional, but good practice for robustness)
	// Logical OR (||): if score is less than 0 OR score is greater than 100
	if (score < 0 || score > 100) {
		printf("Invalid score! Please enter a score between 0 and 100.\n");
	}
	// Check if the score is for an 'A' grade
	// Logical AND (&&): if score is greater than or equal to 9- AND score is less than or equal to 100
	else if (score >= 90 && score <= 100) {
		printf("Grade: A (Excellent!)\n");
	}
	// Check for a 'B' grade
	else if (score >= 80) {
		printf("Grade: B (Very Good)\n");
	}
	// Check for a 'C' grade
	else if (score >= 70) {
		printf("Grade: C (Good)\n");
	}
	// Check for a 'D' grade
	else if (score >= 60) {
		printf("Grade: D (Pass)\n");
	}
	// If none of the above conditions are met, it must be a failing score
	else {
		printf("Grade: F (Fail)\n");
	}

	// Another simple if-else example: Pass of Fail based on threshold
	printf("\n--- Simple Pass/Fail Check ---\n");
	if (score >= 60) { // Relational operator: greater than or equal to 
		printf("Congratulations! You passed.\n");
	} else {
		printf("You did not pass. Keep trying.\n");
	}
	return 0;
}

