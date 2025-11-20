/**
 * ---------------------------------------------------------------------------------------------------------------------------------
 * Program written by : Kevin Kalpala
 * Date               : 20 / 11 / 25
 * 
 * Description:
 * 
 * 
 * Input:
 * 
 * 
 * Output:
 * 
 * 
 * Note:
 * 
 * ---------------------------------------------------------------------------------------------------------------------------------
 */

#include<stdio.h>
#include<math.h>

#define YMIN 0.0
#define YMAX 0.9

float getFloatData();

void printTable(float xValue, float yValue, float xmin, float xmax, float ymin, float ymax);

int main()
{
    float x, y, xMin, xMax;

    printf("\n****** Welcome User! ******\n");
    printf("\nPlease enter the following details for the table to be shown:-\n");
    printf("Please enter the minimum value for x: ");
    xMin = getFloatData();
    printf("Please enter the maximum value for x: ");
    xMax = getFloatData();

    printf("Please enter the value for x: ");
    x = getFloatData();
    printf("Please enter the value for y: ");
    y = getFloatData();

    printTable(x, y, xMin, xMax, YMIN, YMAX);

    return 0;
}

float getFloatData()
{
    float temp;
    while(1)
    {
        if (scanf("%f", &temp) != 1)
        {
            printf("Error: An unexpected error just occurred\n");
            printf("Please try again......................\n");
            while(getchar() != '\n');
            continue;
        }
        else if (temp < 0)
        {
            printf("Error: Invalid input. Please enter a positive value or 0\n");
            continue;
        }
        else
        {
            break;
        }
    }
    return temp;
}

void printTable(float xValue, float yValue, float xmin, float xmax, float ymin, float ymax)
{
    float xSteps = (xmax - xmin) / xmax;
    float ySteps = 0.1;
    float xIndex1 = (int)xValue, xIndex2 = (int)yValue, yIndex1 = (xValue - (int)xValue), yIndex2 = (yValue - (int)yValue);

    printf("\n                                    Square Toot Table                                     \n\n");
    printf("--------------------------------------------------------------------------------------------\n");
    printf("|  Number  |");
    for (float i = ymin; i <= ymax+0.1; i+=ySteps)
    {
        if(i == yIndex1 || i == yIndex2)
        {
            printf("|  %2.1f  |", i);
        }
        else if (i == ymax+0.1)
        {
            printf("   %2.1f  |", i);
        }
        else
        {
            printf("   %2.1f   ", i);
        }
    }
    printf("\n");
    printf("--------------------------------------------------------------------------------------------\n");
    for (float i = xmin; i <=xmax; i+=xSteps)
    {
        if (i == xIndex1 || i == xIndex2)
        {
            printf("--------------------------------------------------------------------------------------------\n");
            printf("|   %2.1f   |", i);
        }
        if (i != xIndex1 && i != xIndex2)
        {
            printf("|   %2.1f   |", i);
        }


        for (float j = ymin; j <= ymax+0.1; j+=ySteps)
        {
            if(j == yIndex1 || j == yIndex2)
            {
                printf("|  %2.1f  |", sqrt(i+j));
            }
            else if (j == ymax)
            {
                printf("   %2.1f  |", sqrt(i+j));
            }
            else
            {
                printf("   %2.1f   ", sqrt(i+j));
            }
        }
        
        
        if (i == xIndex1 || i == xIndex2)
        {
            printf("\n--------------------------------------------------------------------------------------------");
        }
        printf("\n");
    }
}