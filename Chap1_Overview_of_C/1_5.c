
// Program written by Kevin Kalpala
// Date : 07/08/25

#include<stdio.h>
#include<math.h>

#define PI 3.14

float calculateAreaOfCircle(float radiusOfCircle);

int main()
{
    // Define and Intialize the radius
    float radius = 5.2; // Predefined radius value

    // Variable to store the computed area
    float result;

    // Calculate area using helper function
    result = calculateAreaOfCircle(radius);

    // Display the Result
    printf("Area of the circle is %0.4f\n",result); 

    return 0;
}

float calculateAreaOfCircle(float r)
{
    float area = PI * (pow(r,2.0));
    return area;
}

// Note to run this program in github terminal you need to run "gcc 1_5.c -o 1_5 -lm" because without -lm it will give error for linking