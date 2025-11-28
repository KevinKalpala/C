/**
 * ---------------------------------------------------------------------------------------------------------------------------
 * Program written by : Kevin Kalpala
 * Date               : 28 / 11 / 25
 * 
 * Description:
 * 
 * 
 * Input:
 * 
 * 
 * Output:
 * 
 * 
 * Note:
 * 
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
    printf("Please enter the quadratic equation (in form [ax2 + bx + c = 0]): ");
    getValues(&a, &b, &c);

    printf("The equation is %dx2 + %dx + %d = 0\n", a, b, c);
    
    calculateRoots(a, b, c);
    
    return 0;
}

void getValues(int* a, int* b, int* c)
{
    while(1)
    {
        if (scanf("%dx2 +%dx +%d = 0", a, b, c) != 3)
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
    int d = (( pow (b, 2) ) - ( 4 * a * c ));
    if (a == 0 && b == 0)
    {
        printf("No solution exists for this equation because a = 0 and b = 0\n");
    }
    else if (d < 0)
    {
        printf("No real roots exists for this equation\n");
    }
    else
    {
        if (a == 0)
        {
            double x = (( (-1) * c ) / b);
            printf("Only one real root of this equation\n");
            printf("The root is  x = %.2lf", x);
        }
        else
        {
            double x1, x2;
            
            x1 = ((-1) * b) + ((sqrt((double)d)) / (2 * a));
            x2 = ((-1) * b) - ((sqrt((double)d)) / (2 * a));

            printf("Two real roots of this equation exists and are given below\n");
            printf("x1 = %.2lf\n", x1);
            printf("x2 = %.2lf\n", x2);
        }
    }
}