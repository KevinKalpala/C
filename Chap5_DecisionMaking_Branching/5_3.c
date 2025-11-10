/**
* -----------------------------------------------------------------------------------
* Program written by : Kevin Kalpala
* Date               : 10 / 11 / 25
*
* Description:
*     This program calculates the roots x1 and x2 for a set of two linear equations
*     given below :-
*         ax1 + bx2 = m
*         cx1 + dx2 = n
*
* Input:
*     Positive integer values for a, b, c, d, m and n (including zero)
*
* Output:
*     Displays real floating point values of x1 and x2
*
* Note:
*     The formula used here to calculate the roots is given below:-
*         denominator = ( a * d - c * b )
*         x1 = ( ( m * d - b * n ) / denominator)
*         x2 = ( ( n * a - m * c ) / denominator)
* -----------------------------------------------------------------------------------
*/

#include<stdio.h>

#define TRUE 1

void getValues(int* a, int* b, int* c, int* d, int* m, int* n);

void calculateX1andX2(int a, int b, int c, int d, int m, int n, float* x1, float* x2, int* repeat);

void displayValues(float x, float y);

int main()
{
    while(TRUE)
    {
        int a = 0, b = 0, c = 0, d = 0, m = 0, n = 0, repeatProgram = 0;
        float x1 = 0, x2 = 0;
        
        while(TRUE)
        {
            printf("\n******* Welcome User! ******\n");
            
            getValues(&a, &b, &c, &d, &m, &n);
            
            calculateX1andX2(a, b, c, d, m, n, &x1, &x2, &repeatProgram);
            
            if(repeatProgram == 1)
            {
                continue;
            }
            else
            {
                break;
            }
        }
        
        displayValues(x1, x2);

        while(TRUE)
        {
            printf("Do you want re-run this program?\n");
            printf("Press 1 for YES and 0 for NO\n");
            if(scanf("%d", &repeatProgram) != 1)
            {
                printf("Error: An unexpected error just occurred\n");
                printf("Please try again.........................\n");
                while(getchar() != '\n');
                continue;
            }
            else
            {
                break;
            }
        }

        if(repeatProgram == 1)
        {
            continue;
        }
        else
        {
            break;
        }
    }
    
    return 0;
}

void getValues(int* a, int* b, int* c, int* d, int* m, int* n)
{
    
    printf("\nPlease enter the following details for equation 1:-\n");
    while(TRUE)
    {
        printf("\nPlease enter the value of a: ");
        if(scanf("%d", a) != 1)
        {
            printf("Error: An unexpected error just occurred\n");
            printf("Please try again................\n");
            while(getchar() != '\n');
            continue;
        }
        else
        {
            printf("Please enter the value of b: ");
            if(scanf("%d", b) != 1)
            {
                printf("Error: An unexpected error just occurred\n");
                printf("Please try again................\n");
                while(getchar() != '\n');
                continue;
            }
            else
            {
                printf("Please enter the value of m: ");
                if(scanf("%d", m) != 1)
                {
                    printf("Error: An unexpected error just occurred\n");
                    printf("Please try again................\n");
                    while(getchar() != '\n');
                    continue;
                }
                else
                {
                    break;
                }
            }
        }    
    }

    printf("\nPlease enter the following details for equation 2:-\n");
    while(TRUE)
    {
        printf("\nPlease enter the value of c: ");
        if(scanf("%d", c) != 1)
        {
            printf("Error: An unexpected error just occurred\n");
            printf("Please try again................\n");
            while(getchar() != '\n');
            continue;
        }
        else
        {
            printf("Please enter the value of d: ");
            if(scanf("%d", d) != 1)
            {
                printf("Error: An unexpected error just occurred\n");
                printf("Please try again................\n");
                while(getchar() != '\n');
                continue;
            }
            else
            {
                printf("Please enter the value of n: ");
                if(scanf("%d", n) != 1)
                {
                    printf("Error: An unexpected error just occurred\n");
                    printf("Please try again................\n");
                    while(getchar() != '\n');
                    continue;
                }
                else
                {
                    break;
                }
            }
        }
    }
}

void calculateX1andX2(int a, int b, int c, int d, int m, int n, float* x1, float* x2, int* repeat)
{
    int denominator = ( a * d - c * b );
    
    if(denominator == 0)
    {
        printf("The value of denominator (( a * d - c * b )) is equal to zero\n");
        printf("Therefore the roots cannot be calculated\n");
        printf("The given equations are either parallel or identical.\n");

        
        while(TRUE)
        {
            printf("Do you want to repeat the program for different set of values?\n");
            printf("Press 1 for yes and any other number for No\n");
            if(scanf("%d", repeat) != 1)
            {
                printf("Error: An unexpected error just occurred\n");
                printf("We are very sorry for the inconvenience. Please re-enter choice\n");
                while(getchar() != '\n');
                continue;
            }
            else
            {
                break;
            }
        }
    }
    else
    {
        *x1 = (( m * d - b * n ) / (float)denominator);
        *x2 = (( n * a - m * c ) / (float)denominator);
        *repeat = 0;
    }
}

void displayValues(float x, float y)
{
    printf("\nThe values of x1 and x2 are given below:-\n");
    printf("x1 = %.2f\n", x);
    printf("x2 = %.2f\n", y);
}