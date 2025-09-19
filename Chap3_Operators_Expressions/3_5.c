/**
* Program written by Kevin Kalpala
* Date : 19/09/25
*
* Program that displays the number as follows:
* 
* First Line : all digits
* Second Line : all except first digit
* Third Line : all except first two digits
* .........
* Last Line : The last digit
*/

#include<stdio.h>

/**
* Program to find the integer power
* @param base Base integer
* @param exp Exponent integer
* @return Result of (base)^exp
*/
unsigned long int power10(unsigned int exp);

/**
* Program to find the number of digits in a number
* @param num Number whose length is to calculated
* @return Length of a number
*/
unsigned int findLength(unsigned long int num);

/**
* Program to display the number as mentioned in the problem
* @param num Number to be printed
*/
void displayNumber(unsigned long int num);

int main()
{
    unsigned long int number;
    
    // Read the number from the user
    printf("Enter a number:\n");
    scanf("%lu", &number);

    displayNumber(number);

    return 0;
}

unsigned long int power10(unsigned int exp)
{
    int base = 10;
    unsigned long int result = 1;

    for(int i = 0; i < exp; i++)
    {   
        result *= base;
    }

    return result;
}

unsigned int findLength(unsigned long int num)
{
    unsigned int count = 0;

    while(num != 0)
    {
        num = num / 10;
        count++;
    }
    
    return count;
}

void displayNumber(unsigned long int num)
{
    unsigned int length = findLength(num);

    printf("Printing the pattern.....\n\n");

    if(num == 0)
    {
        printf("0\n");
    } else{
        while(num != 0)
        {
            printf("%lu\n", num);

            num = num - ((num / (power10(length - 1))) * (power10(length - 1)));
            length--; 
        }
    }
}