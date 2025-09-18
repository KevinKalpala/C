/**
* Program written by Kevin Kalpala
* Date : 18/09/25
*
* Program to read length and width of a rectangle from the user and compute its area and
* perimeter.
*/

#include<stdio.h>

double cal_area(double l, double w);
double cal_perimeter(double l, double w);

int main()
{
    double length, width, area, perimeter;

    // Read the values of length and width from the user
    printf("Enter the length of the rectangle(in meters):\n");
    scanf("%lf", &length);

    printf("Enter the width of the rectangle(in meters):\n");
    scanf("%lf", &width);

    // Calculate the value of area and perimeter
    perimeter = cal_perimeter(length, width);
    area = cal_area(length, width);

    // Display the results
    printf("When length = %f meters and width = %f meters\n", length, width);
    printf("Perimeter = %f meters\n", perimeter);
    printf("Area = %f square meters\n", area);

    return 0;
}

double cal_perimeter(double l, double w)
{
    return 2 * (l + w);
}

double cal_area(double l, double w)
{
    return l * w;
}