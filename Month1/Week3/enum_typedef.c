#include <stdio.h> // For printf

// --- 1. Enumerations (enum) ---
// An enum is a user-defined data type that consists of a set of named integer constants.
// By default, the first enumerator has the value 0, and subsequent enumerators
// increment by 1. You can also assign explicit values.

// Define an enumeration for days of the week
enum DayOfWeek {
    SUNDAY = 1, // Explicitly assign 1 to SUNDAY
    MONDAY,     // MONDAY will be 2 (SUNDAY + 1)
    TUESDAY,    // TUESDAY will be 3
    WEDNESDAY,  // WEDNESDAY will be 4
    THURSDAY,   // THURSDAY will be 5
    FRIDAY,     // FRIDAY will be 6
    SATURDAY    // SATURDAY will be 7
};

// Another enum example with default values
enum Status {
    SUCCESS, // Default value is 0
    FAILURE, // Default value is 1
    PENDING  // Default value is 2
};

// --- 2. Typedef ---
// typedef is used to give a new name (an alias) to an existing data type.
// It makes code more readable and can simplify complex declarations.

// a) Typedef for basic data types
typedef int Age;
typedef float Price;

// b) Typedef for structures
// Traditional way:
// struct Person {
//     char name[50];
//     Age age; // Using our custom Age typedef
// };

// Using typedef with struct for cleaner declaration later:
typedef struct {
    char name[50];
    Age age;       // Using our custom Age typedef
    enum Status current_status; // Using our enum
} Person; // 'Person' is now an alias for 'struct { ... }'

// c) Typedef for pointers to structures
typedef Person *PersonPtr; // PersonPtr is now an alias for 'struct Person *' or 'Person *'

// d) Typedef for function pointers (more advanced, preview only)
// typedef int (*CompareFunc)(const void *, const void *);


// --- main function ---
int main() {
    printf("--- Enumerations (enum) & Typedef ---\n\n");

    // --- Using Enums ---
    enum DayOfWeek today = WEDNESDAY;
    enum DayOfWeek holiday = SATURDAY;
    enum Status operation_status = SUCCESS;

    printf("Today is day number: %d\n", today); // Prints 4
    printf("Holiday is day number: %d\n", holiday); // Prints 7

    if (today == WEDNESDAY) {
        printf("It's hump day!\n");
    }

    if (operation_status == SUCCESS) {
        printf("Operation completed with status: SUCCESS (%d)\n", operation_status);
    } else if (operation_status == FAILURE) {
        printf("Operation completed with status: FAILURE (%d)\n", operation_status);
    }
    printf("\n");

    // --- Using Typedef ---

    // Using typedef for basic types
    Age myAge = 30; // Instead of int myAge = 30;
    Price itemPrice = 25.50f; // Instead of float itemPrice = 25.50f;
    printf("My age: %d\n", myAge);
    printf("Item price: %.2f\n", itemPrice);
    printf("\n");

    // Using typedef for structures
    Person p1; // Instead of struct Person p1;
    snprintf(p1.name, sizeof(p1.name), "John Doe"); // Safer string copy
    p1.age = 25;
    p1.current_status = PENDING;

    printf("Person 1 Name: %s\n", p1.name);
    printf("Person 1 Age: %d\n", p1.age);
    printf("Person 1 Status: %d\n", p1.current_status); // Prints 2 for PENDING
    printf("\n");

    // Using typedef for pointers to structures
    PersonPtr p1_ptr = &p1; // Instead of Person *p1_ptr = &p1; or struct Person *p1_ptr = &p1;

    printf("Person 1 Name (via PersonPtr): %s\n", p1_ptr->name);
    printf("Person 1 Age (via PersonPtr): %d\n", p1_ptr->age);
    printf("\n");

    return 0; // Indicate successful program execution
}