/**
* Program written By Kevin Kalpala
* Date : 12/08/25
*
* Program to calculate the result of the mathematical operation a/(b-c) where a, b and c are given
*/

#include<stdio.h>

/**
* Function to calculate a/(b-c)
* @param a First variable
* @param b Second variable
* @param c Third variable
* @return Result of a/(b-c)
*/
float cal_result(int a, int b, int c);

int main()
{
    // Declare and Initialize a, b and c
    // For (a) a = 250, b = 85 and c = 25
    // int a = 250, b = 85, c = 25;

    // For (b) a = 300, b = 70 and c = 70
    // Note that the case (b) will give runtime dividing by zero error in normal IDE but not in github because github prints it as inf I
    int a = 300, b = 70, c = 70;

    // Declare x variable to store the result and Initialize its value
    float x = cal_result(a, b, c);

    // Display the value of x
    printf("X = %5.3f (when a = %d, b = %d and c = %d)\n",x,a,b,c);

    return 0;
}

float cal_result(int a, int b, int c)
{
    return (float)(a)/(b-c);
}