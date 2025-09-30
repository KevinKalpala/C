/**
* Program written by Kevin Kalpala
* Date 30/09/25
*
* Program to read a four digit integer and print the sum of it digits.
*/

#include<stdio.h>

/**
* Program to print the sum of the digits of a four digit integer
* @param num Number whose sum of digits is to be printed
*/
void printSum(int num);

/**
* Main function to read input and call digit sum function
*/
int main()
{
    int isValidInput = 1;
    int number;

    do
    {
        isValidInput = 1;
        // Read the number from the user
        printf("\nPlease enter a four digit number:\n");
        if(scanf("%d", &number) != 1 || number < 1000 || number >= 10000) 
        {
            printf("Error: Please enter a four-digit positive and non-zero value.\n");
            while(getchar() != '\n');
            isValidInput = 0;
        }
    }while(!isValidInput);

    printSum(number);

    return 0;
}

void printSum(int num)
{
    int sum = 0;

    for(int i = num; i > 0; i /= 10)
    {
        sum += (i % 10);
    }

    printf("Sum of digits of %4d = %d\n", num, sum);
}