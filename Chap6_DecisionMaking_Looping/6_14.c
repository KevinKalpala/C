/**
 * ------------------------------------------------------------------------------------------------------------------------------------
 * Program written by : Kevin Kalpala
 * Date               : 12 / 12 / 25
 * 
 * Description:
 * This program evaluates the following three mathematical functions to 
 * 0.0001% accuracy using infinite series expansions:
 *
 * (a) sin(x) = x - (x^3/3!) + (x^5/5!) - (x^7/7!) + ...
 * (b) cos(x) = 1 - (x^2/2!) + (x^4/4!) - (x^6/6!) + ...
 * (c) SUM    = 1 + (1/2)^2 + (1/3)^3 + (1/4)^4 + ...
 * 
 * The values of sin(x) and cos(x) are calculated using Taylor Series.
 * Each term is generated using recurrence relations for efficient 
 * computation. The input angle x is taken in radians and reduced using
 * fmod() to improve convergence.
 * 
 * For the SUM series, terms of the form (1/n)^n are added until the term
 * becomes smaller than 0.0001% (accuracy = 1e-6). This series converges
 * rapidly because each term decreases exponentially with n.
 *
 * Input:
 * (a) and (b): User provides a value for x in radians.
 * (c) No user input is required for the SUM series.
 * 
 * Output:
 * For each part, the program prints:
 *    → Calculated value
 *    → Actual library value (for sin and cos)
 *    → Percentage error (for sin and cos)
 *    → Number of terms used (for SUM)
 * 
 * Note:
 * Accuracy used:
 *    → sin(x) and cos(x): 0.0001%
 *    → SUM series: 1e-6 (equivalent to 0.0001%)
 * ------------------------------------------------------------------------------------------------------------------------------------
 */

// ******************************       (a) sinx = x - ((x^3)/3!) + ((x^5)/5!) - ((x^7)/7!) +.....................     ************************

// #include <stdio.h>
// #include <math.h>

// #define PI 3.141592653589793
// #define ACCURACY 0.0001   // 0.0001% accuracy

// double getAngle();
// void calculateSin(double x);

// int main()
// {
//     double x;
//     printf("\n****** Welcome User! ******\n");
//     x = getAngle();
//     calculateSin(x);
//     return 0;
// }

// double getAngle()
// {
//     double data;
//     while(1)
//     {
//         printf("Please enter a value for x in radians: ");
//         if (scanf("%lf", &data) != 1)
//         {
//             printf("Error: Value could not be stored as a double. Try again.\n");
//             while(getchar() != '\n' && !feof(stdin)); // clear input buffer
//             continue;
//         }
//         else
//             return data;
//     }
// }

// void calculateSin(double x)
// {
//     x = fmod(x, 2 * PI); // Reduce x to [-2π, 2π] for faster convergence

//     double term = x;     // First term = x
//     double sinX = term;  // Initialize sum
//     int n = 1;           // Counter for term index

//     double actual = sin(x);
//     double percentageError = fabs(actual - sinX) / fabs(actual) * 100;

//     while (percentageError > ACCURACY)
//     {
//         term *= -1 * x * x / ((2 * n) * (2 * n + 1)); // Efficient next term
//         sinX += term;
//         n++;
//         percentageError = fabs(actual - sinX) / (fabs(actual) + 1e-15) * 100; // Add tiny value to avoid division by zero
//     }

//     printf("sin(%.6lf) = %.12lf\n", x, sinX);
//     printf("Actual sin(%.6lf) = %.12lf\n", x, actual);
//     printf("Percentage error = %.8lf%%\n", percentageError);
// }

// **************************************      (b) cosx = 1 - ((x^2)/2!) + ((x^4)/4!) - ((x^6)/6!) + ..............    *********************************

// #include<stdio.h>
// #include<math.h>

// #define ACCURACY 0.0001
// #define PI 3.141592653589793

// double getAngle();

// void calculateCos(double x);

// int main()
// {
//     double x;
    
//     printf("\n****** Welcome User! ******\n");
    
//     x = getAngle();
    
//     calculateCos(x);
    
//     return 0;
// }

// double getAngle()
// {
//     double data;
    
//     while(1)
//     {
//         printf("Please enter a value for x in radians : ");
        
//         if(scanf("%lf", &data) != 1)
//         {
//             printf("Error: Value could not be read as a double\n");
//             printf("Please try again................\n");
//             while(getchar() != '\n' && !feof(stdin));
//             continue;
//         }
//         else
//         {
//             return data;
//         }
//     }
// }

// void calculateCos(double x)
// {
//     x = fmod(x, 2 * PI);

//     double term = 1, cosX = term;
//     int n = 1;

//     double actual = cos(x);
//     double percentageError = fabs(actual - cosX) / fabs(actual) * 100;

//     while(percentageError > ACCURACY)
//     {   
//         term *= (-1) * x * x / (2 * n * (2 * n - 1));
//         cosX += term;
//         n++;
//         percentageError = fabs(actual - cosX) / (fabs(actual) + 1e-15) * 100;
//     }

//     printf("cos(%.6lf) = %.6lf\n", x, cosX);
//     printf("Actual cos(%.6lf) = %.6lf", x, cos(x));
//     printf("Percentage Error = %.6lf", percentageError);
// }

// ************************************    (c)  SUM = 1 + ((1/2)^2) + ((1/3)^3) + ...................    ******************************************

#include<stdio.h>
#include<math.h>

#define ACCURACY 1e-6

int main()
{
    int n = 2;
    double term = 1;
    double sum = term;

    while(1)
    {
        term = (pow((1.0 / n), n));
        sum += term;
        
        if (term < ACCURACY) break;

        n++;
    }

    printf("\nSUM = %.6lf\n", sum);
    printf("Terms used = %d\n", n);

    return 0;
}