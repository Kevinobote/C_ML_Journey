#include <stdio.h>

int main() {
    char crop_name[30];
    int length = 0;

    printf("Enter the crop you are researching: ");
    
    // fgets(variable, size, source)
    // stdin means "Standard Input" (your keyboard)
    fgets(crop_name, sizeof(crop_name), stdin);

    // Manually counting characters until we hit the null terminator
    while (crop_name[length] != '\0' && crop_name[length] != '\n') {
        length++;
    }

    printf("The crop name '%s' has %d characters.\n", crop_name, length);

    if (length > 10) {
        printf("Note: That is a long crop name!\n");
    }

    return 0;
}