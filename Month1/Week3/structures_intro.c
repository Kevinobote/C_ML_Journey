#include <stdio.h>   // For printf, scanf
#include <string.h>  // For strcpy (to copy strings into char arrays)

// --- 1. Defining a Structure ---
// Syntax:
// struct StructureName {
//     dataType member1;
//     dataType member2;
//     // ...
// }; (Semicolon is required here!)

// Define a structure for a student's date of birth
struct DateOfBirth {
    int day;
    int month;
    int year;
}; // Don't forget the semicolon!

// Define a structure for a student
struct Student {
    int studentId;
    char firstName[50]; // Character array for string
    char lastName[50];
    float gpa;
    struct DateOfBirth dob; // Nested structure: A struct inside another struct
}; // Don't forget the semicolon!

// --- main function ---
int main() {
    printf("--- Structures: Custom Data Types ---\n\n");

    // --- 2. Declaring Structure Variables ---
    // Syntax: struct StructureName variableName;

    struct Student student1; // Declare a variable of type 'struct Student'

    // --- 3. Accessing Members of a Structure (Dot Operator '.') ---
    // Syntax: structVariable.memberName

    // Assign values to student1's members
    student1.studentId = 1001;
    // For char arrays (strings), you must use strcpy to assign values,
    // you cannot use '=' directly like: student1.firstName = "Alice";
    strcpy(student1.firstName, "Alice");
    strcpy(student1.lastName, "Smith");
    student1.gpa = 3.85f; // 'f' suffix for float literal

    // Accessing members of a nested structure
    student1.dob.day = 15;
    student1.dob.month = 6;
    student1.dob.year = 2003;

    printf("--- Student 1 Details ---\n");
    printf("ID: %d\n", student1.studentId);
    printf("Name: %s %s\n", student1.firstName, student1.lastName);
    printf("GPA: %.2f\n", student1.gpa);
    printf("Date of Birth: %d/%d/%d\n", student1.dob.day, student1.dob.month, student1.dob.year);
    printf("\n");

    // --- 4. Initializing Structures at Declaration ---
    // You can initialize members directly when declaring the variable.
    struct Student student2 = {
        1002,
        "Bob",
        "Johnson",
        3.20f,
        {10, 1, 2002} // Initialize nested struct members
    };

    printf("--- Student 2 Details (Initialized at Declaration) ---\n");
    printf("ID: %d\n", student2.studentId);
    printf("Name: %s %s\n", student2.firstName, student2.lastName);
    printf("GPA: %.2f\n", student2.gpa);
    printf("Date of Birth: %d/%d/%d\n", student2.dob.day, student2.dob.month, student2.dob.year);
    printf("\n");

    // --- Array of Structures ---
    // You can also create arrays where each element is a struct.
    struct Student class_students[3]; // An array to hold 3 Student structures

    // Populate the first student in the array
    class_students[0].studentId = 1003;
    strcpy(class_students[0].firstName, "Charlie");
    strcpy(class_students[0].lastName, "Brown");
    class_students[0].gpa = 3.99f;
    class_students[0].dob.day = 1;
    class_students[0].dob.month = 1;
    class_students[0].dob.year = 2004;

    printf("--- Class Students (Array of Structures) ---\n");
    printf("Student 1 in array: %s %s (ID: %d)\n",
           class_students[0].firstName, class_students[0].lastName, class_students[0].studentId);
    printf("\n");

    // --- Pointers to Structures (Preview for Day 16) ---
    // You can have pointers to structures.
    struct Student *student_ptr;
    student_ptr = &student1; // student_ptr now points to student1

    // Access members using the arrow operator (->) with pointers to structures
    printf("--- Accessing Student 1 via Pointer ---\n");
    printf("ID (via pointer): %d\n", student_ptr->studentId);
    printf("Name (via pointer): %s %s\n", student_ptr->firstName, student_ptr->lastName);
    printf("\n");

    return 0; // Indicate successful program execution
}