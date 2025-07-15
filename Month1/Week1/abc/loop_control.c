#include <stdio.h> // Standard input/output library

int main() {
    //---Example 1: Baic while loop ---
    printf("--- Basic While Loop Example (Count from 1 to 5) ---\n");
    int i = 1; // Initialize counter
    while (i <= 5) { // Loop condition
        printf("Count: %d\n", i);
        i++; // Increment counter
    }
    printf("\n");

    // --- Example 2: do-while loop (Guaranteed to run at least once) ---
    printf("--- Do-While Loop Example (Users enters positive number) ---\n");
    int positive_number;
    do {
        printf("Enter a positive number: ");
        scanf("%d", &positive_number);
    } while (positive_number <= 0); // Conditioned checked after the first iteration
    printf("You entered: %d\n", positive_number);
    printf("\n");

    //---Example 3: Using 'break' in for loop ---
    printf("---Using 'break' (Stop at 3) ---\n");
    for (int j = 1; j <= 5; j++) {
        if (j == 3) {
            printf("Breaking the loop at count: %d\n", j);
            break; // Exit the loop when j equals 3
        }
        printf("j:: %d\n", j);
    }
    printf("Loop finished after break.\n");
    printf("\n");

    //---Example 4: Using 'continue' in for loop ---
    printf("---Using 'continue' (Skip 3) ---\n");
    for (int k = 1; k <= 5; k++) {
        if (k == 3) {
            printf("Skipping %d\n", k);
            continue; // Skip the rest of the loop body when k equals 3
        }
        printf("k:: %d\n", k);
    }
    printf("Loop finished after continue.\n");
    printf("\n");

    //--- Example 5: Combining loops and condionals for a ssimple menu ---
    printf("--- Simple Menu ---\n");
    int choice;
    do {
        printf("1. Say Hello\n");
        printf("2. Say Goodbye\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Hello there!\n");
                break;
            case 2:
                printf("Goodbye for now!\n");
                break;
            case 3:
                printf("Exiting the menu.\n");
                break; //Break from switch, not do-while loop
            default:
                printf("Invalid choice, please try again.\n");
        }
        printf("\n");
    } while (choice != 3); // Continue until user chooses to exit

    return 0;
} // End of main function