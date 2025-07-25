#include <stdio.h>   // For printf, scanf
#include <string.h>  // For strcpy
#include <stdlib.h>  // For malloc, free

// Define a structure for a student
struct Student {
    int studentId;
    char firstName[50];
    char lastName[50];
    float gpa;
}; // Don't forget the semicolon!

// --- Function Prototypes ---

// Function that takes a struct by value (makes a copy)
void printStudentInfoByValue(struct Student s);

// Function that takes a struct by pointer (pass by reference)
// This allows the function to modify the original struct and is more efficient
void printStudentInfoByPointer(const struct Student *s_ptr); // const to prevent modification
void updateStudentGPA(struct Student *s_ptr, float new_gpa);
void initializeStudent(struct Student *s_ptr, int id, const char *fname, const char *lname, float gpa_val);


// --- main function ---
int main() {
    printf("--- Pointers to Structures & The Arrow Operator ---\n\n");

    // 1. Declare a struct variable
    struct Student s1;

    // 2. Declare a pointer to a struct
    struct Student *s1_ptr;

    // 3. Initialize the pointer to point to s1
    s1_ptr = &s1;

    // 4. Accessing Members via Pointer using the Arrow Operator (->)
    // The arrow operator (->) is used to access members of a structure when you have a POINTER to the structure.
    // It's equivalent to (*s1_ptr).member
    printf("--- Accessing members via pointer (->) ---\n");
    s1_ptr->studentId = 1001;
    strcpy(s1_ptr->firstName, "Alice");
    strcpy(s1_ptr->lastName, "Wonderland");
    s1_ptr->gpa = 3.9f;

    printf("Student ID: %d\n", s1_ptr->studentId);
    printf("Student Name: %s %s\n", s1_ptr->firstName, s1_ptr->lastName);
    printf("Student GPA: %.2f\n", s1_ptr->gpa);
    printf("\n");

    // Verify s1 itself was modified
    printf("--- Verifying s1 (the original variable) ---\n");
    printf("s1.studentId: %d\n", s1.studentId);
    printf("s1.firstName: %s\n", s1.firstName);
    printf("\n");

    // 5. Passing Structures to Functions by Pointer (Pass by Reference)
    printf("--- Passing Structures by Pointer to Functions ---\n");

    // Initialize s2 using a function that takes a pointer
    struct Student s2;
    initializeStudent(&s2, 1002, "Bob", "Builder", 3.0f);
    printf("s2 after initialization function:\n");
    printStudentInfoByPointer(&s2);
    printf("\n");

    // Update s2's GPA using a function that takes a pointer
    printf("Updating s2's GPA to 3.5...\n");
    updateStudentGPA(&s2, 3.5f); // Pass address of s2
    printf("s2 after GPA update function:\n");
    printStudentInfoByPointer(&s2);
    printf("\n");

    // Compare with passing by value (demonstrates copy is made)
    printf("--- Passing Structure by Value to Function ---\n");
    printf("Initial s1 GPA: %.2f\n", s1.gpa);
    printStudentInfoByValue(s1); // Passes a copy of s1
    printf("s1 GPA after printStudentInfoByValue (still original): %.2f\n", s1.gpa);
    printf("\n");

    // 6. Dynamic Allocation of Structures
    printf("--- Dynamic Allocation of Structures ---\n");
    struct Student *new_student_ptr = (struct Student *)malloc(sizeof(struct Student));

    if (new_student_ptr == NULL) {
        printf("Failed to allocate memory for new student!\n");
        return 1;
    }

    // Initialize dynamically allocated struct using the pointer
    new_student_ptr->studentId = 1003;
    strcpy(new_student_ptr->firstName, "Charlie");
    strcpy(new_student_ptr->lastName, "Chaplin");
    new_student_ptr->gpa = 4.0f;

    printf("Dynamically allocated student:\n");
    printStudentInfoByPointer(new_student_ptr);
    printf("\n");

    // 7. Freeing dynamically allocated structure memory
    printf("Freeing dynamically allocated memory...\n");
    free(new_student_ptr);
    new_student_ptr = NULL; // Good practice to prevent dangling pointer
    printf("Memory freed.\n\n");

    return 0; // Indicate successful program execution
}

// --- Function Definitions ---

// Function taking a struct by value (a copy is made)
void printStudentInfoByValue(struct Student s) {
    printf("  (By Value) Student ID: %d\n", s.studentId);
    printf("  (By Value) Student Name: %s %s\n", s.firstName, s.lastName);
    printf("  (By Value) Student GPA: %.2f\n", s.gpa);
    // s.gpa = 0.0f; // If uncommented, this would NOT affect s1 in main
}

// Function taking a struct by pointer (efficient, allows modification of original)
void printStudentInfoByPointer(const struct Student *s_ptr) {
    // Using 'const' in the parameter means we promise not to modify the struct pointed to.
    // This is good practice for functions that only read data.
    printf("  (By Pointer) Student ID: %d\n", s_ptr->studentId);
    printf("  (By Pointer) Student Name: %s %s\n", s_ptr->firstName, s_ptr->lastName);
    printf("  (By Pointer) Student GPA: %.2f\n", s_ptr->gpa);
    // s_ptr->gpa = 0.0f; // This would cause a compile-time error due to 'const'
}

// Function to update GPA using a pointer (allows modification)
void updateStudentGPA(struct Student *s_ptr, float new_gpa) {
    s_ptr->gpa = new_gpa; // Modify the original struct's GPA
    printf("  GPA updated inside function for student ID %d\n", s_ptr->studentId);
}

// Function to initialize student struct using a pointer
void initializeStudent(struct Student *s_ptr, int id, const char *fname, const char *lname, float gpa_val) {
    s_ptr->studentId = id;
    strcpy(s_ptr->firstName, fname);
    strcpy(s_ptr->lastName, lname);
    s_ptr->gpa = gpa_val;
    printf("  Student ID %d initialized by function.\n", id);
}