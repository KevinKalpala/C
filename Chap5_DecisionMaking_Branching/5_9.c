/**
 * Description:
 *     This program reads a floating-point value x from the user and evaluates a
 *     simple piecewise function defined as:
 *
 *         y = -1   if x < 0
 *         y =  0   if x = 0
 *         y =  1   if x > 0
 *
 *     The evaluation is demonstrated in three different ways:
 *         (a) Using nested if statements
 *         (b) Using else-if statements
 *         (c) Using the conditional (?:) operator
 *
 *     Floating-point equality is handled safely using an EPS-based comparison
 *     macro to avoid precision issues. User input is validated to ensure that
 *     only numeric values are accepted.
 */

#include<stdio.h>
#include<math.h>

#define EPS 1e-9
#define SAME(a, b) (fabs((a) - (b)) < EPS)

double getDoubleData();

int calculateY(double val);

int main()
{
    int y;
    double x;
    
    printf("\n****** Welcome User! ******\n");
    printf("Please enter the value of x: ");
    x = getDoubleData();
    
    y = calculateY(x);

    printf("When x = %.2lf\ny = %d\n", x, y);
    
    return 0;
}

double getDoubleData()
{
    double data;
    
    while(1)
    {
        if(scanf("%lf", &data) != 1)
        {
            printf("Error: Input could not read as an floating-point number\n");
            while(getchar() != '\n' && !feof(stdin));
            continue;
        }
        
        else return data;
    }
}

int calculateY(double val)
{
    int data;

    // // (a) using nested if statements
    // if (val < 0.0) data = -1;
    // else
    // {
    //     if (SAME(val, 0.0)) data = 0;
    //     else data = 1;
    // }

    // // (b) using else if statements
    // if (val < 0.0) data = -1;
    // else if (SAME(val, 0.0)) data = 0;
    // else data = 1;

    // (c) using conditional operator ?:
    data = (val < 0) ? -1 : (SAME(val, 0.0) ? 0 : 1);

    return data;
}