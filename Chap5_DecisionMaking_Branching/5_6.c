// /**
//  * ---------------------------------------------------------------------------------------------------------------------------------
//  * Program written by : Kevin Kalpala
//  * Date               : 20 / 11 / 25
//  * 
//  * Description:
//  * 
//  * 
//  * Input:
//  * 
//  * 
//  * Output:
//  * 
//  * 
//  * Note:
//  * 
//  * ---------------------------------------------------------------------------------------------------------------------------------
//  */

// #include<stdio.h>
// #include<math.h>

// #define YMIN 0.0
// #define YMAX 0.9

// float getFloatData();

// void printTable(float xValue, float yValue, float xmin, float xmax, float ymin, float ymax);

// int main()
// {
//     float x, y, xMin, xMax;

//     printf("\n****** Welcome User! ******\n");
//     printf("\nPlease enter the following details for the table to be shown:-\n");
//     printf("Please enter the minimum value for x: ");
//     xMin = getFloatData();
//     printf("Please enter the maximum value for x: ");
//     xMax = getFloatData();

//     printf("Please enter the value for x: ");
//     x = getFloatData();
//     printf("Please enter the value for y: ");
//     y = getFloatData();

//     printTable(x, y, xMin, xMax, YMIN, YMAX);

//     return 0;
// }

// float getFloatData()
// {
//     float temp;
//     while(1)
//     {
//         if (scanf("%f", &temp) != 1)
//         {
//             printf("Error: An unexpected error just occurred\n");
//             printf("Please try again......................\n");
//             while(getchar() != '\n');
//             continue;
//         }
//         else if (temp < 0)
//         {
//             printf("Error: Invalid input. Please enter a positive value or 0\n");
//             continue;
//         }
//         else
//         {
//             break;
//         }
//     }
//     return temp;
// }

// void printTable(float xValue, float yValue, float xmin, float xmax, float ymin, float ymax)
// {
//     float xSteps = (xmax - xmin) / xmax;
//     float ySteps = 0.1;
//     float xIndex1 = (int)xValue, xIndex2 = (int)yValue, yIndex1 = (xValue - (int)xValue), yIndex2 = (yValue - (int)yValue);

//     printf("\n                                    Square Toot Table                                     \n\n");
//     printf("--------------------------------------------------------------------------------------------\n");
//     printf("|  Number  |");
//     for (float i = ymin; i <= ymax+0.1; i+=ySteps)
//     {
//         if(i == yIndex1 || i == yIndex2)
//         {
//             printf("|  %2.1f  |", i);
//         }
//         else if (i == ymax+0.1)
//         {
//             printf("   %2.1f  |", i);
//         }
//         else
//         {
//             printf("   %2.1f   ", i);
//         }
//     }
//     printf("\n");
//     printf("--------------------------------------------------------------------------------------------\n");
//     for (float i = xmin; i <=xmax; i+=xSteps)
//     {
//         if (i == xIndex1 || i == xIndex2)
//         {
//             printf("--------------------------------------------------------------------------------------------\n");
//             printf("|   %2.1f   |", i);
//         }
//         if (i != xIndex1 && i != xIndex2)
//         {
//             printf("|   %2.1f   |", i);
//         }


//         for (float j = ymin; j <= ymax+0.1; j+=ySteps)
//         {
//             if(j == yIndex1 || j == yIndex2)
//             {
//                 printf("|  %2.1f  |", sqrt(i+j));
//             }
//             else if (j == ymax)
//             {
//                 printf("   %2.1f  |", sqrt(i+j));
//             }
//             else
//             {
//                 printf("   %2.1f   ", sqrt(i+j));
//             }
//         }
        
        
//         if (i == xIndex1 || i == xIndex2)
//         {
//             printf("\n--------------------------------------------------------------------------------------------");
//         }
//         printf("\n");
//     }
// }

#include<stdio.h>
#include<math.h>

#define EPS 1e-9
#define SAME(a, b) (fabs((a) - (b)) < EPS)

void getDoubleData(double* val);

void printTable(double x, double y);

int main()
{
    double x, y;

    printf("\n****** Welcome User! ******\n");
    printf("\nPlease enter the value of x: ");
    getDoubleData(&x);
    printf("Please enter the value of y: ");
    getDoubleData(&y);

    printTable(x, y);

}

void getDoubleData(double* val)
{
    while (1)
    {
        if (scanf("%lf", val) != 1)
        {
            printf("Error: An unexpected error just occurred\n");
            printf("Please try again...................\n");
            while(getchar() != '\n');
            continue;
        }
        else if (*val < 0.0)
        {
            printf("Error: Invalid Input. Please enter a positive value or 0\n");
            continue;
        }
        else
        {
            break;
        }
    }
}

void printTable(double x, double y)
{
    double xFractionalPart = x - (int)x;
    double yFractionalPart = y - (int)y;

    // printf("%2.1f\n", xFractionalPart);
    // printf("%2.1f\n", yFractionalPart);

    printf("\n\n                                       Square Root Table\n");
    printf("\n-------------------------------------------------------------------------------------------------------\n");
    printf("|  Number  |");
    for (double i = 0.0; i<=0.9; i+=0.1)
    {
        if (SAME(i, xFractionalPart) || SAME(i, yFractionalPart))
        {
            printf("|  %2.1lf  |", i);
        }
        else if (!(SAME(i, xFractionalPart) || SAME(i, yFractionalPart)) && SAME(i, 0.9))
        {
            printf("    %2.1lf  |", i);
        }
        else
        {
            printf("   %2.1lf   ", i);
        }
    }
    printf("\n-------------------------------------------------------------------------------------------------------\n");
    for (double i = 0.0; i <= 9.0; i+=1.0)
    {
        if (SAME(i, (int)x) || SAME(i, (int)y))
        {
            printf("-------------------------------------------------------------------------------------------------------\n");
        }
        
        printf("|    %2.1f   |", i);
        // for (double j = 0.0)
        
        
        if (SAME(i, (int)x) || SAME(i, (int)y))
        {
            printf("\n-------------------------------------------------------------------------------------------------------");
        }

        printf("\n");
    }
}