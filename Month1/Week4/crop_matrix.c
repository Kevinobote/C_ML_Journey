#include <stdio.h>

int main() {
    // 3 plots, 2 features each: {Temp, Humidity}
    float plots[3][2] = {
        {28.5, 60.2},  // Plot 1
        {30.1, 55.8},  // Plot 2
        {27.9, 62.4}   // Plot 3
    };

    printf("Plot ID\tTemp\tHumidity\n");
    printf("-------------------------\n");

    //Nested loops are required to traverse 2D arrays
    for (int i = 0; i < 3; i++) { // Loop through the rows (plots)
        printf("Plot %d\t", i);

        for (int j = 0; j < 2; j++) { // Loop through the columns (features)
            printf("%.1f\t", plots[i][j]);
        }
        printf("\n");
    }

    return 0;
}