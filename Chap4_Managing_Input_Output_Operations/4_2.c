/**
* Program written by Kevin Kalpala
* Date : 08/10/25
*
* Program to read two values x and y from the terminal and display the results of the following expressions
* (a) (x + y) / (x - y)
* (b) (x + y) / 2
* (c) (x + y) * (x - y)
*/

#include<stdio.h>

void getData(float* n);

float getAddition(float a, float b);

float getSubtraction(float a, float b);

int main()
{
    float x, y, addResult, subResult, resultA, resultB, resultC;

    // Get the data from the user
    getData(&x);
    getData(&y);

    // Complete necessary calculations
    addResult = getAddition(x, y);
    subResult = getSubtraction(x, y);

    // (a) (x + y) / (x - y)
    if (subResult == 0) {
        printf("\n(a) (x + y)/(x - y) is undefined (division by zero)\n\n");
    } else {
        resultA = addResult / subResult;
        printf("\nx + y\n ----- = %.2f\n x - y\n\n", resultA);
    }


    // (b) (x + y) / 2
    resultB = addResult / 2;
    printf("x + y\n----- = %.2f\n  2  \n", resultB);
    printf("\n");

    // (c) (x + y) * (x - y)
    resultC = addResult * subResult;
    printf("(x + y)(x - y) = %.2f\n", resultC);

    return 0;
}

void getData(float* n)
{
    while(1){
        printf("Please enter a number : ");
        if(scanf("%f", n) != 1){
            printf("Error: An unexpected error just occurred.\n");
            printf("Please try again.......................\n");
            while(getchar() != '\n');
            continue;
        }

        if(*n == 0){
            printf("Error: Please enter a positive and non-zero value\n");
            continue;
        }

        break;
    }
}

float getAddition(float a, float b)
{
    return a + b;
}

float getSubtraction(float a, float b)
{
    return a - b;
}