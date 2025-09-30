/**
* Program written by Kevin Kalpala
* Date 30/09/25
*
* Program to print the table of sin and cos functions for the interval from 0 to 180 degrees in increments of 15
*/

#include<stdio.h>
#include<math.h>

#define PI 3.14159265358979323846

int main()
{
    printf("\n------------------------------------------------------\n");
    printf("%-20s%-20s%-20s\n","x (degrees)","sin (x)","cos (x)");
    printf("\n------------------------------------------------------\n");

    for(int i = 0; i <= 180; i += 15)
    {
        // Convert degrees into radians
        double rad = i * (PI / 180);
        double sinX, cosX;

        sinX = sin(rad);
        cosX = cos(rad);

        printf("%-20d%-20.2lf%-20.2lf\n", i, sinX, cosX);
    }

    return 0;
}