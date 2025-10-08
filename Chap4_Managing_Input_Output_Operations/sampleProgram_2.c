/**
* Program written by Kevin Kalpala
* Date : 08/10/25
*
* Program to print the Reliability graph of an electronic component.
* where Reliability = e^(-lambda*t)
*/

#include <stdio.h>
#include <math.h>

#define LAMBDA 0.001  // Decay constant

int main() {
    double t;
    float r;
    int i, R;

    // Print top border line (54 characters: 27 * "--")
    for (i = 1; i <= 27; ++i) {
        printf("--");
    }
    printf("\n");

    // Loop to print decaying bars
    for (t = 0; t <= 3000; t += 150) {
        r = exp(-LAMBDA * t);             // Calculate exponential decay
        R = (int)(50 * r + 0.5);          // Scale and round to nearest int

        printf("|");                      // Start of the bar
        for (i = 1; i <= R; ++i) {
            printf("*");                  // Print R asterisks
        }
        printf("#\n");                    // End of the bar
    }

    // Print vertical tail bars (graph axis)
    for (i = 1; i < 3; ++i) {
        printf("|\n");
    }

    return 0;
}