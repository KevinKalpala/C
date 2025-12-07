/**
 * --------------------------------------------------------------------------------------------------------
 * Program written by : Kevin Kalpala
 * Date               : 07 / 12 / 25
 * 
 * Description:
 * This program evaluates the mathematical expression y = x^n, where 'x' is a real number and 
 * 'n' is a positive non-zero integer. The value is calculated using a for loop instead of 
 * built-in library functions. The result is stored in a variable and displayed with formatted output.
 * 
 * Input:
 * - A real number 'x' representing the base value.
 * - A positive non-zero integer 'n' representing the exponent.
 *   (Note: The program does not allow zero or negative values for either input.)
 * 
 * Output:
 * Displays the computed result of x raised to the power n in the format:
 *     x = <base>; n = <exponent>; x to power n = <result>
 * 
 * Note:
 * - Input validation is included to ensure only valid numerical values are accepted.
 * - The calculation is performed iteratively using multiplication inside a for loop.
 * 
 * --------------------------------------------------------------------------------------------------------
 */

#include<stdio.h>

int getIntData();

double getDoubleData();

int main()
{
    int n;
    double x, y = 1;
    
    printf("\n****** Welcome User! ******\n");
    
    printf("Please enter the value of x : ");
    x = getDoubleData();
    
    printf("Please enter the value of n : ");
    n = getIntData();

    for(int i = 0; i < n; i++)
    {
        y = y * x;
    }
    
    printf("x = %.4lf; n = %d; x to power n = %.6lf\n", x, n, y);

    return 0;
}

int getIntData()
{
    int data;
    
    while(1)
    {
        if (scanf("%d", &data) != 1)
        {
            printf("Error: Value could not be read as an integer\n");
            printf("Please try again...............\n");
            while(getchar() != '\n' && !feof(stdin));
            continue;
        }
        else if (data <= 0)
        {
            printf("Error: Invalid input. Please enter a positive and non-zero value\n");
            while(getchar() != '\n' && !feof(stdin));
            continue;
        }
        else
        {
            return data;
        }
    }
}

double getDoubleData()
{
    double data;

    while(1)
    {
        if (scanf("%lf", &data) != 1)
        {
            printf("Error: Value could not be read as a double value\n");
            printf("Please try again....................\n");
            while(getchar() != '\n' && !feof(stdin));
            continue;
        }
        else if (data <= 0.0)
        {
            printf("Error: Invalid input. Please enter a positive and non-zero value\n");
            while(getchar() != '\n' && !feof(stdin));
            continue;
        }
        else
        {
            return data;
        }
    }
}