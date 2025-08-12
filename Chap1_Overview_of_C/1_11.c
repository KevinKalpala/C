/**
* Program written by Kevin Kalpala
* Date : 12/08/25 
* 
* Program to calculate the distance between two points (x1, y1) & (x2, y2) in 2D using the formula D = sqrt((x2-x1)^2 + (y2-y1)^2)
*/

#include<stdio.h>
#include<math.h>

const int x_one = 1;
const int y_one = 1;
const int x_two = 4;
const int y_two = 4;

/**
* Function to calculate the distance between two points
* @param xa x coordinate of point one
* @param ya y coordinate of point one
* @param xb x coordinate of point two
* @param yb y coordinate of point two
* @return Result of sqrt((xb - xa)^2 + (yb - ya)^2)
*/
float calculateDistance(int xa, int ya, int xb, int yb);

int main()
{
    // Declare a variable to value of calculated distance
    float d;

    // Initialize the value of d
    d = calculateDistance(x_one, y_one, x_two, y_two);

    // Display the value of distance
    printf("Distance = %5.3f (when x1 = %d, y1 = %d, x2 = %d, y2 = %d)", d, x_one, y_one, x_two, y_two);

    return 0;
}

float calculateDistance(int xa, int ya, int xb, int yb)
{
    // Declare a variable to store the result
    float result;
    
    // Calculate distance and initialize the value to result
    result = sqrt(pow((xb - xa), 2) + pow((yb - ya), 2));

    return result;
}