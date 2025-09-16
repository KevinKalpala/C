/**
* Program written by Kevin Kalpala
* Date : 16/09/25
*
* Program to read a floating point number and then display the two rightmost digits of its integral part
*/

#include<stdio.h>
#include<stdlib.h>

int getRightTwoDigits(double num);

int main()
{
    double number;
    int result; // To store the result of calculation

    //Read the number from the user
    printf("Enter the value of the floating point number:\n");
    scanf("%lf",&number);

    result = getRightTwoDigits(number);

    // Display the result
    printf("For number = %.2f\nDigits = %02d\n", number, result);

    return 0;
}

int getRightTwoDigits(double num)
{
    int r_value;

    r_value = abs((int)num % 100);

    return r_value;
}