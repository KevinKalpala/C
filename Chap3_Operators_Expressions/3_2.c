/**
* Program written by Kevin Kalpala
* Date : 16/09/25
*
* Program to read a floating point number and then display the rightmost digit of its integral part
*/

#include<stdio.h>
#include<stdlib.h>

int getRightDigit(double num);

int main()
{
    double number;
    int result; // To store the result of calculation

    //Read the number from the user
    printf("Enter the value of the floating point number:\n");
    scanf("%lf",&number);

    result = getRightDigit(number);

    // Display the result
    printf("For number = %.2f\nDigit = %d\n", number, result);

    return 0;
}

int getRightDigit(double num)
{
    int r_value;

    r_value = abs((int)num % 10);

    return r_value;
}