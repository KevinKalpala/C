/**
* Program written by Kevin Kalpala
* Date: 07/09/25
*
* This program reads two floating-point numbers from the user,
* adds them, assigns the sum to an integer variable (demonstrating truncation),
* and then prints all three values.
*/

#include<stdio.h>

int main()
{
    float num1, num2;
    int num3;

    printf("Enter the first floating point value:\n");
    scanf("%f", &num1);   
    
    printf("Enter the second floating point value:\n");
    scanf("%f", &num2);
    
    // cast sum to int to demonstrate truncation
    num3 = (int)(num1 + num2); // this can also work without (int), but it is only here for clarity

    printf("num1 = %.6f, num2 = %.6f and num3 = %d\n", num1, num2, num3);

    return 0;
}