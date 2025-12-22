/**
 * ----------------------------------------------------------------------------------------------------------------------------------
 * Program written by : Kevin Kalpala
 * Date               : 22 / 12 / 25
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
 * ----------------------------------------------------------------------------------------------------------------------------------
 */

#include<stdio.h>

int getNumberOfPoints(char* prompt);

void getPoints(char* prompt, int arr[][2], int n, long int* x, long int* y, long int* xy, long int* x2);

double calculateM(int size, long int x, long int y, long int xy, long int x2);

double calculateC(int size, double calM, long int x, long int y);

int main()
{
    int n;
    long int sumX = 0, sumY = 0, sumXY = 0, sumX2 = 0;
    double m, c;
    
    printf("\n****** Welcome User! *****\n");
    
    n = getNumberOfPoints("Please enter the number of points n : ");
    
    int points[n][2];
    
    getPoints("Please enter the points :- \n", points, n, &sumX, &sumY, &sumXY, &sumX2);
    
    m = calculateM(n, sumX, sumY, sumXY, sumX2);
    c = calculateC(n, m, sumX, sumY);
    
    printf("The equation of the line is : y = %.2lfx + %.2lf\n", m, c);
    
    printf("All points which were used were : ");
    for(int i = 0; i < n; i++)
    {
        printf("(");
        for(int j = 0; j < 2; j++)
        {
            if(j == 0)
            {
                printf("%d, ", points[i][j]);
            }
            else printf("%d) ", points[i][j]);
        }
    }

    printf("\n");

    return 0;
}

int getNumberOfPoints(char* prompt)
{
    int data;
    
    while(1)
    {
        printf("%s", prompt);
        if (scanf("%d", &data) != 1)
        {
            printf("Error : Value could not be read as an integer\n");
            printf("Please try again.....................\n");
            while(getchar() != '\n' && !feof(stdin));
            continue;
        }
        
        else if (data <= 1)
        {
            printf("Error : Invalid input. Please enter a value > 1\n");
            while(getchar() != '\n' && !feof(stdin));
            continue;
        }
        
        else
        {
            return data;
        }
    }
}

void getPoints(char* prompt, int arr[][2], int size, long int* x, long int* y, long int* xy, long int* x2)
{
    int value = 0;
    
    printf("%s", prompt);
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < 2; j++)
        {
            while(1)
            {
                if (scanf("%d", &value) != 1)
                {
                    printf("Error: Value could not be stored as an integer\n");
                    printf("Please try again.........................\n");
                    while(getchar() != '\n' && !feof(stdin));
                    continue;
                }
                else
                {
                    arr[i][j] = value;
                    break;
                }
            }
        }
        
        *x += arr[i][0];
        *y += arr[i][1];
        *xy += (arr[i][0] * arr[i][1]);
        *x2 += (arr[i][0] * arr[i][0]);
    }
}   

double calculateM(int size, long int x, long int y, long int xy, long int x2)
{
    double result;
    double denominator = (double)(size * x2 - x * x);
    
    if (denominator == 0)
    {
        printf("No such line exists.\nPlease try again............\n");
        result = 0;
    }
    else
    {
        result = (size * xy - x * y) / denominator;
    }
    
    return result;
}

double calculateC(int size, double calM, long int x, long int y)
{
    double result;
    
    result = (1.0 / size) * (y - calM * x);

    return result;
}