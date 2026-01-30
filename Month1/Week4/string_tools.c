#include <stdio.h>
#include <string.h> // Essential for string functions

int main() {
    char input[50];
    char secret_command[] = "ANALYSIS";
    
    printf("Enter command: ");
    scanf("%s", input); // Read a single word

    // 1. Check length using strlen
    printf("Your command length is: %zu\n", strlen(input));

    // 2. Compare strings using strcmp
    // strcmp returns 0 if strings are the same
    if (strcmp(input, secret_command) == 0) {
        printf("Access Granted: Starting Agricultural Analysis...\n");
    } else {
        printf("Access Denied: Unknown command '%s'.\n", input);
    }

    // 3. Copying strings
    char copy_buffer[50];
    strcpy(copy_buffer, input);
    printf("Log: Command '%s' has been backed up to buffer.\n", copy_buffer);

    return 0;
}