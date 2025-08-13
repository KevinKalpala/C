/**
* Program written by Kevin Kalpala
* Date : 12/08/25
*
* Program to calculate the perimeter and area of a circle whose center is (0,0) & (4,5) is a point on its circumference
*
* Note that all the values of lengths used in this program are in centimeters 
*/

#include<stdio.h>
#include<math.h>

#define PI 3.14

// Below x_center & y_center are center point coordinates of the circle
const int x_center = 0;
const int y_center = 0;
// Below x_p1 & y_p1 are x and y coordinates of the point on its circumference
const int x_p1 = 4;
const int y_p1 = 5;

/**
* Function to calculate the radius
* @param xc x coordinate of center point of circle
* @param yc y coordinate of center point of circle
* @param xa x coordinate of circumference point
* @param ya y coordinate of circumference point
* @return Result of sqrt((xc - xa)^2 + (yc - ya)^2)
*/
float calculateDistance(int xc, int yc, int xa, int ya);

/**
* Function to calculate the perimeter of the circle
* @param r Radius of the circle
* @return Result of 2 * PI * r 
*/
float calculatePerimeter(float r);

/**
* Function to calculate the area of the circle
* @param r Radius of the circle
* @return Result of PI * r * r 
*/
float calculateArea(float r);

int main()
{
    // Declare variables to store radius, perimeter and area of the circle
    float radius, perimeter, area;

    // Calculate the value of radius
    radius = calculateDistance(x_center, y_center, x_p1, y_p1); // Note that here we use the distance between center point and circumference as radius because mathematical they are same

    // Calculate the value of perimeter
    perimeter = calculatePerimeter(radius);
    
    // Calculate the value of area
    area = calculateArea(radius);

    // Display the values of area and perimeter of the circle
    printf("Radius = %.4f centimeters\n", radius);
    printf("Perimeter = %.4f centimeters\n", perimeter);
    printf("Area = %.4f cm\u00b2\n", area);

    return 0;
}

float calculateDistance(int xc, int yc, int xa, int ya)
{
    return (sqrt((xc - xa) * (xc - xa) + (yc - ya) * (yc - ya)));
}

float calculatePerimeter(float r)
{
    return (2 * PI * r);
}

float calculateArea(float r)
{
    return (PI * r * r);
}