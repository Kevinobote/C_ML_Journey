#include <stdio.h>  // For printf, scanf
#include <stdlib.h> // For malloc, realloc, free, exit

int main() {
    printf("--- Dynamic Memory Resizing with realloc() ---\n\n");

    int *my_dynamic_array = NULL; // Initialize pointer to NULL
    int current_size = 0;
    int new_elements_to_add;

    // 1. Initial allocation
    printf("Initially allocating memory for 3 integers...\n");
    my_dynamic_array = (int *)malloc(3 * sizeof(int));
    if (my_dynamic_array == NULL) {
        printf("Initial allocation failed!\n");
        return 1;
    }
    current_size = 3;

    // Populate initial array
    for (int i = 0; i < current_size; i++) {
        my_dynamic_array[i] = (i + 1) * 10;
    }
    printf("Initial array elements: ");
    for (int i = 0; i < current_size; i++) {
        printf("%d ", my_dynamic_array[i]);
    }
    printf("\n\n");

    // 2. Resizing with realloc()
    printf("How many *new* integers do you want to add to the array? ");
    scanf("%d", &new_elements_to_add);

    if (new_elements_to_add <= 0) {
        printf("No new elements to add. Skipping realloc.\n");
    } else {
        int new_total_size = current_size + new_elements_to_add;
        int *temp_ptr = (int *)realloc(my_dynamic_array, new_total_size * sizeof(int));

        // CRITICAL: Always check the return value of realloc
        if (temp_ptr == NULL) {
            printf("Reallocation failed! Original array content is preserved.\n");
            // my_dynamic_array still points to the old block, which is still valid.
            // You should still free my_dynamic_array here if you can't proceed.
            free(my_dynamic_array);
            return 1;
        } else {
            my_dynamic_array = temp_ptr; // Update original pointer to new block
            printf("Memory successfully reallocated to %d integers.\n", new_total_size);

            // Initialize new elements (old elements retain their values)
            for (int i = current_size; i < new_total_size; i++) {
                my_dynamic_array[i] = (i + 1) * 100; // Assign new values
            }
            current_size = new_total_size; // Update current size

            printf("Array after reallocation and adding new elements: ");
            for (int i = 0; i < current_size; i++) {
                printf("%d ", my_dynamic_array[i]);
            }
            printf("\n\n");
        }
    }

    // 3. Free the dynamically allocated memory
    if (my_dynamic_array != NULL) {
        printf("Freeing dynamically allocated memory...\n");
        free(my_dynamic_array);
        my_dynamic_array = NULL; // Prevent dangling pointer
        printf("Memory freed.\n\n");
    }

    // --- The 'const' Keyword ---
    printf("--- The 'const' Keyword ---\n\n");

    // a) Constant variables
    const int MAX_VALUE = 100;
    // MAX_VALUE = 200; // This would cause a compile-time error!
    printf("MAX_VALUE: %d\n", MAX_VALUE);

    // b) Pointers to constants (data pointed to is constant)
    const int fixed_data = 50;
    const int *ptr_to_const_data = &fixed_data; // Pointer to a const int
    printf("Value pointed to by ptr_to_const_data: %d\n", *ptr_to_const_data);
    // *ptr_to_const_data = 60; // This would cause a compile-time error! (Cannot modify constant data)

    // FIX START: Declare 'my_age' here
    int my_age = 42; // Example value
    // FIX END

    ptr_to_const_data = &my_age; // This IS allowed. The pointer itself is not constant.
                                // It can point to another const int or non-const int.

    int non_const_var = 70;
    ptr_to_const_data = &non_const_var; // Allowed: can point to non-const, but treats it as const via pointer
    printf("Value pointed to by ptr_to_const_data (now pointing to non_const_var): %d\n", *ptr_to_const_data);
    // *ptr_to_const_data = 80; // Still compile-time error!

    // c) Constant pointers (pointer itself is constant, cannot be reassigned)
    int value = 10;
    int *const const_ptr = &value; // Constant pointer to an int
    printf("Value pointed to by const_ptr: %d\n", *const_ptr);
    *const_ptr = 11; // Allowed: The value pointed to can be modified
    printf("Value pointed to by const_ptr after modification: %d\n", *const_ptr);
    // const_ptr = &non_const_var; // This would cause a compile-time error! (Cannot reassign the pointer itself)

    // d) Constant pointer to constant data
    const int another_fixed_data = 90;
    const int *const all_const_ptr = &another_fixed_data;
    printf("Value pointed to by all_const_ptr: %d\n", *all_const_ptr);
    // *all_const_ptr = 95; // Compile-time error!
    // all_const_ptr = &value; // Compile-time error!

    printf("\nUnderstanding 'const' helps prevent accidental modifications and improves code safety.\n");

    return 0; // Indicate successful program execution
}