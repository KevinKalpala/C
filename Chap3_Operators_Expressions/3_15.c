/**
* Program written by Kevin Kalpala
* Date 30/09/25
*
* Program to read three values using scanf statement and print the following results:
* (a) Sum of the values
* (b) Average of the three values
* (c) Largest of the three
* (d) Smallest of the three
*/

#include<stdio.h>

#define MIN_INT_VALUE 1

int getValidInt(const char* prompt);

int getSum(int a, int b, int c);

double getAverage(int a, int b, int c);

int getLargestValue(int a, int b, int c);

int getSmallestValue(int a, int b, int c);

int main()
{
    int num1, num2, num3;
    int sum, largest, smallest;
    double average;

    printf("\n****** Welcome User! ******\n");

    num1 = getValidInt("Please enter the first number: ");
    num2 = getValidInt("Please enter the second number: ");
    num3 = getValidInt("Please enter the third number: ");

    sum = getSum(num1, num2, num3);
    average = getAverage(num1, num2, num3);
    largest = getLargestValue(num1, num2, num3);
    smallest = getSmallestValue(num1, num2, num3);

    // Display the results
    printf("\n****** Results ******\n");
    printf("(a) Sum of the values (i.e. %d + %d + %d) = %d\n", num1, num2, num3, sum);
    printf("(b) Average of the three values = %.2lf\n", average);
    printf("(c) Largest of the three (i.e. largest out of %d, %d and %d) = %d\n", num1, num2, num3, largest);
    printf("(d) Smallest of the three (i.e. smallest out of %d, %d and %d) = %d\n", num1, num2, num3, smallest);

    return 0;
}

int getValidInt(const char* prompt)
{
    int num;
    while(1){
        printf("%s", prompt);
        if(scanf("%d", &num) != 1)
        {
            printf("Error: An unexpected error just occurred.\n");
            printf("Please try again.....................\n");
            while(getchar() != '\n');
        }else if(num < MIN_INT_VALUE){
            printf("Error: Please enter a positive or non-zero integer value.\n");
            while(getchar() != '\n');
        }
        else{
            return num;
        }
    }
}

int getSum(int a, int b, int c)
{
    return a + b + c;
}

double getAverage(int a, int b, int c)
{
    return (a + b + c) / 3.0;
}

int getLargestValue(int a, int b, int c)
{
    return ( a > b ) ? ( ( a > c ) ? a : c ) : ( ( b > c ) ? b : c );
}

int getSmallestValue(int a, int b, int c)
{
    return ( a < b ) ? ( ( a < c ) ? a : c ) : ( ( b < c ) ? b : c );
}