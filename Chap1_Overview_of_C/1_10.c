/**
* Program written by Kevin Kalpala
* Date : 12/08/25
* 
* Program to calculate the area of a triangle using the formula Area = sqrt(S*(S-a)*(S-b)*(S-c)) where a, b and c are sides of    * triangle and S = (a + b + c) / 2. Also the values of a, b and c are given
* 
*/

#include<stdio.h>
#include<math.h>

// Note all the below given side lengths are in centimeters
const float a = 3.2;
const float b = 4.5;
const float c = 7.5;

/**
* Function to calculate S
* @param a Value of side1
* @param b Value of side2
* @param c Value of side3
* @return Result of (a + b + c) / 2 
*/
float calculate_S(float a, float b, float c);

/**
* Function to calculate Area of the triangle
* @param a Value of side1
* @param b Value of side2
* @param c Value of side3
* @param s Value of S
* @return Result of sqrt(S * (S - a) * (S - b) * (S - c))
*/
float calculateArea(float a,float b, float c, float s);

int main()
{
    // Declare two variables: 1. To store the value of Area and 2. To store the value of S
    float s, area;

    // Initialize the values of S and Area
    s = calculate_S(a, b, c);
    area = calculateArea(a, b, c, s);

    // Display the value Area
    printf("Area of the triangle = %5.7f cm2 (when a = %5.3f, b = %5.3f, c = %5.3f)\n",area, a, b, c);

    return 0;
}

float calculate_S(float a, float b, float c)
{
    return (a + b + c) / 2;
}

float calculateArea(float a, float b, float c, float s)
{
    return (sqrt(s * (s - a) * (s - b) * (s - c)));
}