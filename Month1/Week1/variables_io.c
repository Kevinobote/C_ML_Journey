#include <stdio.h> // Required for printf and scanf

int main() {
    // --- Declaring and Initializing Variables ---
    int integer_var = 10;
    float float_var = 20.5f; // 'f' suffix indicates a float literal
    double double_var = 30.123456789;
    char char_var = 'A';
    char string_var[] = "Hello C!"; // A character array for strings (more on this later)

    // --- Using printf with different format specifiers ---
    printf("Integer: %d\n", integer_var); // %d for int
    printf("Float: %f\n", float_var);     // %f for float
    printf("Double: %lf\n", double_var);  // %lf for double (though %f often works too for output)
    printf("Character: %c\n", char_var);  // %c for char
    printf("String: %s\n", string_var);   // %s for string (char array)

    // Limiting decimal places
    printf("Float (2 decimal places): %.2f\n", float_var);
    printf("Double (4 decimal places): %.4lf\n", double_var);

    // --- Taking User Input with scanf ---
    int user_age;
    float user_gpa;
    char user_initial;

    printf("\nEnter your age: ");
    scanf("%d", &user_age); // %d for int, '&' is the address-of operator (crucial for scanf)

    printf("Enter your GPA: ");
    scanf("%f", &user_gpa); // %f for float

    // Important: When reading a char after a number, consume the newline character
    // left by the previous scanf. Use a space before %c.
    printf("Enter your initial: ");
    scanf(" %c", &user_initial); // space before %c to consume leftover newline

    printf("\nYou entered:\n");
    printf("Age: %d\n", user_age);
    printf("GPA: %.2f\n", user_gpa);
    printf("Initial: %c\n", user_initial);

    return 0;
}
