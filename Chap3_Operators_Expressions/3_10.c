/**
* Program written by Kevin Kalpala
* Date 29/09/25
*
* Program to calculate the natural frequency for an electrical circuit for different values of Capacitance starting from 0.01
* to 0.1 in steps of 0.01
*
* Note : Frequency = sqrt( (1 / (L * C)) - (R^2 / (4 * C^2)) )
*        where L -> Inductance
*              C -> Capacitance
*              R -> Resistance
*/

#include<stdio.h>
#include<math.h>

const double capacitance = 0.01; // Unit of capacitance is faraday

/**
* Program to calculate the natural frequency in an electrical circuit
* @param l Inductance
* @param c Capacitance
* @param r Resistance
*/
void calFrequency(double l, double c, double r);

int main()
{
    int status = 0;
    double resistance, inductance;

    do
    {
        status = 0;

        printf("****** Welcome to the program to calculate the natural frequency of an electrical circuit ******\n");
        printf("Note: This program calculates the frequency for different values of C starting from 0.01 to 0.1 in steps of 0.01\n");
        printf("Please enter the following details:-\n");
        printf("Enter Resistance R (Ohms): ");
        if(scanf("%lf", &resistance) != 1 || resistance <= 0)
        {
            printf("Error: Please enter a positive or non-zero value of Resistance\n");
            while(getchar() != '\n');
            status = 1;
        }
        printf("Enter Inductance L (Henries): ");
        if(scanf("%lf", &inductance) != 1 || inductance <= 0)
        {
            printf("Error: Please enter a positive or non-zero value of Inductance\n");
            while(getchar() != '\n');
            status = 1;
        }
    }while(status);

    calFrequency(inductance, capacitance, resistance);

    return 0;
}

void calFrequency(double l, double c, double r)
{
    double inside;

    printf("\n%-16s%-20s\n", "Capacitance (F)", "Frequency (rad/s)");
    printf("----------------------------------------------------\n");

    for(int i = 1; i <= 10; i++)
    {
        double cap = c * i;

        inside = ( 1 / ( l * cap ) ) - ( ( r * r ) / ( 4 * cap * cap ) );
        if(inside <= 0)
        {
            printf("%-16.2lf\t\tImaginary result (skipped)\n", cap);
        }else{
            double result = sqrt(inside);
            printf("%-16.2lf%-20.2lf\n", cap, result);
        }

    }
}