/**
 * -------------------------------------------------------------------------------------------------------------------------------
 * Program written by : Kevin Kalpala
 * Date               : 12 / 12 / 25
 * 
 * Description:
 *   Program to compute sin(x) using the Taylor series:
 *   sin(x) = x - x^3/3! + x^5/5! - x^7/7! + ...
 *   The calculation continues until the percentage error is <= 0.0001%.
 * 
 * Input:
 *   Value of x in radians (double)
 * 
 * Output:
 *   sin(x) computed using Taylor series
 * 
 * Note:
 *   Efficient term-by-term computation is used to avoid recalculating factorials.
 * -------------------------------------------------------------------------------------------------------------------------------
 */

#include <stdio.h>
#include <math.h>

#define PI 3.141592653589793
#define ACCURACY 0.0001   // 0.0001% accuracy

double getAngle();
void calculateSin(double x);

int main()
{
    double x;
    printf("\n****** Welcome User! ******\n");
    x = getAngle();
    calculateSin(x);
    return 0;
}

double getAngle()
{
    double data;
    while(1)
    {
        printf("Please enter a value for x in radians: ");
        if (scanf("%lf", &data) != 1)
        {
            printf("Error: Value could not be stored as a double. Try again.\n");
            while(getchar() != '\n' && !feof(stdin)); // clear input buffer
            continue;
        }
        else
            return data;
    }
}

void calculateSin(double x)
{
    x = fmod(x, 2 * PI); // Reduce x to [-2π, 2π] for faster convergence

    double term = x;     // First term = x
    double sinX = term;  // Initialize sum
    int n = 1;           // Counter for term index

    double actual = sin(x);
    double percentageError = fabs(actual - sinX) / fabs(actual) * 100;

    while (percentageError > ACCURACY)
    {
        term *= -1 * x * x / ((2 * n) * (2 * n + 1)); // Efficient next term
        sinX += term;
        n++;
        percentageError = fabs(actual - sinX) / (fabs(actual) + 1e-15) * 100; // Add tiny value to avoid division by zero
    }

    printf("sin(%.6lf) = %.12lf\n", x, sinX);
    printf("Actual sin(%.6lf) = %.12lf\n", x, actual);
    printf("Percentage error = %.8lf%%\n", percentageError);
}
