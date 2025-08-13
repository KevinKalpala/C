/**
* Program written by Kevin Kalpala
* Date : 13/08/25
*
* Program to print the equation of a line in the form ax + by = c 
* Note that a = 5, b = 8 and c = 18
*/

#include<stdio.h>

const int a = 5; // x coefficient
const int b = 8; // y coefficient
const int c = 18; // constant

int main()
{
    // Display the equation of the line
    printf("%dx + %dy = %d (when a = %d, b = %d and c = %d)\n", a, b, c, a, b, c);    

    return 0;
}