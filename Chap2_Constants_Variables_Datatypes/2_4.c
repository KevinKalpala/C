/**
* Program written by Kevin Kalpala
* Date : 06/09/25
*
* Program to divide two floating point constants and print the result  
*/

#include<stdio.h>

double divide(float f1, float f2);

int main()
{
    // Declare variables to store the floating point constant values and their divison result
    float num1, num2; 
    double div_answer;

    // Read the values from the user
    printf("Enter the first floating point constant:\n");
    scanf("%f", &num1);

    printf("Enter the second floating point constant:\n");
    scanf("%f", &num2);

    if(num2 == 0)
    {
        printf("Error: Division by zero is not allowed.\n");
        return 1;
    }

    // Calculate the division
    div_answer = divide(num1, num2);

    // Display the result
    printf("%.6f / %.6f = %.10f", num1, num2, div_answer);

    return 0;
}

double divide(float f1, float f2)
{
    return f1 / (double)f2;
}