/**
 * ---------------------------------------------------------------------------------------------------------------------------
 * Program Written By : Kevin Kalpala
 * Date               : 01 / 12 / 25
 *
 * Description:
 *      This program calculates the real roots of a quadratic equation of the form:
 *                      ax^2 + bx + c = 0
 *      The program takes input from the user for the coefficients a, b, and c.
 *      Based on the input values, the program determines whether:
 *          - No solution exists (if both a and b are zero)
 *          - Only one real root exists (if a = 0)
 *          - No real roots exist (if the discriminant is negative)
 *          - Two real roots exist (if the discriminant is zero or positive)
 *
 * Input:
 *      Integer values of a, b, and c entered by the user.
 *
 * Output:
 *      Displays one of the following based on the input:
 *          - "No solution exists"
 *          - One real root (linear equation)
 *          - "No real roots exist"
 *          - Two real roots (quadratic equation)
 *
 * Note:
 *      Input validation is included to prevent invalid data entry.
 * ---------------------------------------------------------------------------------------------------------------------------
 */

#include<stdio.h>
#include<math.h>

void getValues(int* a, int* b, int* c);

void calculateRoots(int a, int b, int c);

int main()
{
    int a, b, c;
    double x1, x2;
    
    printf("\n****** Welcome User! ******\n");
    printf("Please enter the values of a, b and c : ");
    getValues(&a, &b, &c);

    printf("The equation is %dx^2 + %dx + %d = 0\n", a, b, c);
    
    calculateRoots(a, b, c);
    
    return 0;
}

void getValues(int* a, int* b, int* c)
{
    while(1)
    {
        if (scanf("%d %d %d", a, b, c) != 3)
        {
            printf("Error: Invalid input. Please try again...........\n");
            while(getchar() != '\n' && !feof(stdin));
            continue;
        }
        else
        {
            break;
        }
    }
}

void calculateRoots(int a, int b, int c)
{
    double d = (( pow (b, 2) ) - ( 4 * (double)a * c ));
    if (a == 0 && b == 0)
    {
        printf("No solution exists for this equation because a = 0 and b = 0\n");
    }
    else if (a == 0)
    {
        double x = (( (-1) * c ) / b);
        printf("Only one real root of this equation\n");
        printf("The root is  x = %.2lf", x);
    }
    else if (d < 0)
    {
        printf("No real roots exists for this equation\n");
    }
    else
    {
        double x1, x2;
        
        x1 = ((-1 * b) + (sqrt(d))) / (2 * a);
        x2 = ((-1 * b) - (sqrt(d))) / (2 * a);

        printf("Two real roots of this equation exists and are given below\n");
        printf("x1 = %.2lf\n", x1);
        printf("x2 = %.2lf\n", x2);
    }
}