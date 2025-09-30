/**
* Program written by Kevin Kalpala
* Date 30/09/25
*
* Program to illustrate the use of cast operator in a real life situation
*/

#include<stdio.h>

//Program to illustrate the use of cast operator by calculating the efficieny of a fuel
int main()
{
    int distance = 300; // kilometers
    int fuel = 7; // liters

    // Note: Using double ensures higher precision than float
    double calEfficiency1 = distance / fuel;
    double calEfficiency2 = (double)distance / fuel;

    printf("For Fuel = %d and Distance = %d\n", fuel, distance);
    printf("Calculated Efficiency (non-accurate) = %.2lf\n", calEfficiency1);
    printf("Calculated Efficiency (accurate) = %.2lf\n", calEfficiency2);
    printf("Note: In the first case, the cast operator is NOT used, so integer division occurs.\n");
    printf("In the second case, the cast operator IS used, resulting in a more accurate calculation.\n");

    return 0;
}