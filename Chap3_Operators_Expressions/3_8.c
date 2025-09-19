/**
* Program written by Kevin Kalpala
* Date : 19/09/25
*
* The distance travelled by a vehicle in t seconds is given by
*       distance = u * t + (0.5) * a * (t * t)
*
* Program to calculate the distance travelled by a vehicle at regular intervals of time, given the values of u and a.
* The program should provide the flexibility to user to select his own time intervals and repeat the calculations for different
* values of u and a.
*/

#include<stdio.h>

double calDistance(int time, float u, float a);

int getTime();
float getInitialVelocity();
float getAcceleration();

int main()
{
    // Note the units of measurements used are as follows:
    // time -> seconds
    // distance -> meters
    // velocity -> meter/second
    // acceleration -> meter/second^2

    printf("Welcome User!\n");
    printf("This program calculates the distance travelled by a vehicle\n");
    int mode = 1;// To store the mode of operation(1 --> Default, 2 --> User-Defined) 
    
    while(mode != 0)
    {
        int choice = 1;
        int time, t1 = 0, t2 = 4; // Assuming the initial values of time(t1, t2) to maintain a regular interval(time)
        float u = 2, a = 4; // Default values of initial velocity and acceleration
        double distance = 0;
        printf("Do you want to calculate the distance travelled using default or user defined values?\n");
        printf("Press 1 For Default and 2 For User-defined\n");
        scanf("%d", &choice);
        while(getchar() != '\n');

        if(choice == 2)
        {
            time = getTime();
            u = getInitialVelocity();
            a = getAcceleration();

        } else{
            printf("Entering Default Mode...............\n");
            printf("Note that the default values are t1 = %d, t2 = %d, u = %.2f and a = %.2f\n", t1, t2, u, a);
            time = t2 - t1;
        }
        
        distance = calDistance(time, u, a);

        //Display the result
        printf("Distance Travelled by the vehicle:\n%.2lf meters\n\n", distance);

        printf("Do you want to repeat the calculation?\n");
        printf("Please enter 1 for Yes and 0 for No\n");
        scanf("%d", &mode);
        if(mode == 0)
        {
            printf("Thank you for using the program\n");
        }
    }

    return 0;
}

int getTime()
{
    int tInitial, tFinal;
    do{
        printf("Please enter the initial time(>=0):\n");
        if(scanf("%d", &tInitial) != 1) // scanf returns 1 if it successfully reads an integer, otherwise 0 (invalid input like letters or symbols)
        {
            printf("Invalid input. Please enter an integer value\n");
            while(getchar() != '\n');
            continue;
        }
        if(tInitial < 0)
        {
            printf("Time cannot be negative try again\n");
        }
    }while(tInitial<0);

    do{
        printf("Please enter the final time(>=0):\n");
        if(scanf("%d", &tFinal) != 1) // scanf returns 1 if it successfully reads an integer, otherwise 0 (invalid input like letters or symbols)
        {
            printf("Invalid input. Please enter an integer value\n");
            while(getchar() != '\n');
            continue;
        }
        if(tFinal < 0)
        {
            printf("Time cannot be negative try again\n");
        }
        if(tFinal < tInitial)
        {
            printf("Final time cannot be less than intial time. Please try again.\n");
        }
        if(tFinal == tInitial)
        {
            printf("Final time and initial time cannot be equal. In this case distance travelled will be zero.\n");
        }
    }while(tFinal< tInitial || tFinal < 0 || tFinal == tInitial);

    return tFinal - tInitial;
}

float getInitialVelocity()
{
    float iVelocity;
    
    do{
        printf("Please enter the initial velocity:\n");
        if(scanf("%f", &iVelocity) != 1)
        {
            printf("Invalid input. Please enter a numeric value\n");
            while(getchar() != '\n');
            continue;
        }
        if(iVelocity < 0)
        { 
            printf("Initial velocity cannot be negative. Please try again\n");
        }
    }while(iVelocity<0);

    return iVelocity;
}

float getAcceleration()
{
    float acc;
    
    do{
        printf("Please enter the acceleration:\n");
        if(scanf("%f", &acc) != 1)
        {
            printf("Invalid input. Please enter a numeric value\n");
            while(getchar() != '\n');
            continue;
        }
        if(acc < 0)
        { 
            printf("Acceleration cannot be negative. Please try again\n");
        }
    }while(acc<0);

    return acc;
}

double calDistance(int time, float u, float a)
{
    return u * time + a * (time * time) * 0.5;
}