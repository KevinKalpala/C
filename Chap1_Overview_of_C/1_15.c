/**
* Program written by Kevin Kalpala
* Date : 13/08/25
*
* Program to display a simple arithmetic calculator
*/

#include<stdio.h>

const int x = 16; // Input one for calculator
const int y = 13; // Input two for calculator

/**
* Function to calculate the sum of two variables a & b 
* @param a First variable
* @param b Second variable
* @return Sum of a and b
*/
int add(int a, int b);

/**
* Function to calculate the difference of two variables a & b 
* @param a First variable
* @param b Second variable
* @return a minus b
*/
int subtract(int a, int b);

/**
* Function to calculate the product of two variables a & b 
* @param a First variable
* @param b Second variable
* @return Product of a and b
*/
int multiply(int a, int b);

/**
* Function to calculate the division of two variables a & b 
* @param a First variable
* @param b Second variable
* @return Result of a / b
*/
float divide(int a, int b);

int main()
{
    // Declare variables to store the result of addition, subtraction, multiplication and division operations
    int sum, difference, product;
    float division;

    // Initialize the values of respective mathematical operations
    sum = add(x, y);
    difference = subtract(x, y);
    product = multiply(x, y);
    division = divide(x, y);

    // Display the values
    printf("x = %d          y = %d\n", x, y);
    printf("Sum = %d        Difference = %d\n", sum, difference);
    printf("Product = %d   Division = %.5f\n", product, division);

    return 0;
}

int add(int a, int b)
{
    return a + b;
}

int subtract(int a, int b)
{
    return a - b;
}

int multiply(int a, int b)
{ 
    return a * b;
}

float divide(int a, int b)
{
    return (float)a / b;
}