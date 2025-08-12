/**
* Program written by Kevin Kalpala
* Date : 12/08/25
*
* Program to calculate the perimeter and area of a circle whose center is (0,0) & (4,5) is a point on its circumference
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

// Note that here below we use the distance between center point and circumference as radius because mathematical they are same
/**
* Function to calculate the radius
* @param xc x coordinate of center point of circle
* @param yc y coordinate of center point of circle
* @param xa x coordinate of circumference point
* @param ya y coordinate of circumference point
* @return Result of sqrt((xc - xa)^2 + (yc - ya)^2)
*/
float calculateRadius(int xc, int yc, int xa, int ya);

int main()
{
    return 0;
}