/**
* Program written by Kevin Kalpala
* Date : 14/10/25
*
* Program to read 4 floating point values from the user and print a horizontal bar chart to represent these values using the character *.
*/

#include<stdio.h>
#include<math.h>

void getData(float* n);

int roundHalfEven(float n);

void printBar(float n);

int main()
{
    float num1, num2, num3, num4;

    // Welcome message for the user
    printf("\n****** Welcome User! ******\n");

    // Get the data from the user
    getData(&num1);
    getData(&num2);
    getData(&num3);
    getData(&num4);

    // Print the pattern
    printBar(num1);
    printf("\n");
    printBar(num2);
    printf("\n");
    printBar(num3);
    printf("\n");
    printBar(num4);

    return 0;
}

void getData(float* n)
{
    while(1)
    {
        printf("\nPlease enter a number: ");
        if(scanf("%f", n) != 1)
        {
            printf("\nError: An unexpected error just occurred.\n");
            printf("Please try again................\n");
            while(getchar() != '\n');
            continue;
        }
        if(*n <= 0)
        {
            printf("Error: Please enter a non-negative or a non-zero value\n");
            continue;
        }

        break;
    }
}

int roundHalfEven(float n)
{
    float floorVal = floorf(n);
    float decimal = n - floorVal;

    if(decimal < 0.5)
    {
        return (int)floorVal;
    }else if(decimal > 0.5)
    {
        return (int)(floorVal + 1);
    }else{
        if((int)floorVal % 2 == 0){
            return (int)floorVal;
        }else{
            return (int)(floorVal + 1);
        }
    }
}

void printBar(float n)
{
    int roundedN = roundHalfEven(n);

    for(int i = 1; i <= 3; i++)
    {
        for(int j = 1; j <= roundedN; j++)
        {
            printf("*\t");
            if(i == 2 && j == roundedN){
                printf("%.2f", n);
            }
        }
        printf("\n");
    }
}