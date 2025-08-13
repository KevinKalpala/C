/**
* Program written by Kevin Kalpala
* Date : 13/08/25
*
* Program to calculate the area of a circle whose diameter is a line joining the points (2,2) & (5,6) 
*
* Note that all the values of lengths used in this program are in centimeters
*/

#include<stdio.h>
#include<math.h>

#define PI 3.14

const int x_p1 = 2;
const int y_p1 = 2;
const int x_p2 = 5;
const int y_p2 = 6;

/**
* Function to compute the distance between two points
* @param xa x coordinate of point one
* @param ya y coordinate of point one
* @param xb x coordinate of point two
* @param yb y coordinate of point two
* @return Result of sqrt((xb - xa) * (xb - xa) + (yb - ya) * (yb - ya))
*/
float calculateDistance(int xa, int ya, int xb, int yb);

/**
* Function to compute the area of a circle
* @param r Radius of the circle
* @return Result of PI * r * r 
*/
float calculateArea(float r);

int main()
{
    // Declare variable to store the values of radius and area
    float radius, area;

    // Initialize the value of radius
    radius = calculateDistance(x_p1, y_p1, x_p2, y_p2) / 2; // Because radius = diameter / 2

    // Calculate the value of area
    area = calculateArea(radius);

    // Display the value of Area
    printf("Area = %.5f cm\u00b2\n",area); //

    return 0;
}

float calculateDistance(int xa, int ya, int xb, int yb)
{
    return sqrt((xb - xa) * (xb - xa) + (yb - ya) * (yb - ya));
}

float calculateArea(float r)
{
    return (PI * r * r);
}