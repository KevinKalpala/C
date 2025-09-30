/**
* Program written by Kevin Kalpala
* Date 30/09/25
*
* Program to read three values from the keyboard and print out the largest of them without using if statement.
*/

#include<stdio.h>

#define MIN_INPUT_VALUE 1

/**
* Program to find the largest number out of three numbers
* @param a Number one
* @param b Number two
* @param c Number three
* @return Largest number between a, b and c
*/
int findLargestNum(int a, int b, int c);

int main()
{
    int isValidInput = 1;
    int num1, num2, num3, lNumber; // lNumber stores the value of largest number

    do
    {
        isValidInput = 1;

        printf("\n****** Welcome User! ******\n");
        printf("Please enter the first number: ");
        if(scanf("%d", &num1) != 1 || num1 < MIN_INPUT_VALUE)
        {
            printf("Error: Please enter a value greater than or equal to %d\n", MIN_INPUT_VALUE);
            printf("Let's try again...\n");
            while(getchar() != '\n'); // Empty the input buffer
            isValidInput = 0;
            continue;
        }

        printf("Please enter the second number: ");
        if(scanf("%d", &num2) != 1 || num2 < MIN_INPUT_VALUE)
        {
            printf("Error: Please enter a value greater than or equal to %d\n", MIN_INPUT_VALUE);
            printf("Let's try again...\n");
            while(getchar() != '\n');
            isValidInput = 0;
            continue;
        }

        printf("Please enter the third number: ");
        if(scanf("%d", &num3) != 1 || num3 < MIN_INPUT_VALUE)
        {
            printf("Error: Please enter a value greater than or equal to %d\n", MIN_INPUT_VALUE);
            printf("Let's try again...\n");
            while(getchar() != '\n');
            isValidInput = 0;
            continue;
        }

        if(num1 == num2 || num2 == num3 || num3 == num1)
        {
            printf("Error: Please enter three distinct positive or non-zero integer values\n");
            printf("Let's try again...\n");
            isValidInput = 0;
            continue;
        }
    }while(!isValidInput);

    lNumber = findLargestNum(num1, num2, num3);

    // Display the results
    printf("Largest number between %d, %d and %d = %d\n", num1, num2, num3, lNumber);

    return 0;
}

int findLargestNum(int a, int b, int c)
{
    int num = ( a > b ) ? ( ( a > c ) ? a : c ) : ( ( b > c ) ? b : c );

    return num;
}