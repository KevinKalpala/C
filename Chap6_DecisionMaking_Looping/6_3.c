/**
 * -----------------------------------------------------------------------------------------------------------------------------------
 * Program written by : Kevin Kalpala
 * Date               : 06 / 12 / 25
 * 
 * Description:
 * This program takes a non-negative integer as input from the user and calculates the sum of its digits.
 * The calculation is performed using a separate function which extracts each digit and accumulates the total.
 * 
 * Input:
 * A single non-negative integer entered by the user.
 * 
 * Output:
 * The sum of all digits of the entered number.
 * 
 * Note:
 * - The program validates user input to ensure only integers >= 0 are accepted.
 * - The digit sum is computed using modulus (%) and division operations in a loop.
 * -----------------------------------------------------------------------------------------------------------------------------------
 */

#include<stdio.h>

int getIntData();

long int calculateSumOfDigits(int n);

int main()
{
    int number;
    long int sum = 0;
    
    printf("\n******* Welcome User! ******\n");
    
    printf("Please enter a number : ");
    number = getIntData();
    
    sum = calculateSumOfDigits(number);
    
    printf("Sum of digits : %ld\n", sum);
    
    return 0;
}

int getIntData()
{
    int data;
    
    while(1)
    {
        if (scanf("%d", &data) != 1)
        {
            printf("Error: Value could not be read as an integer\n");
            printf("Please try again..................\n");
            while(getchar() != '\n' && !feof(stdin));
            continue;
        }
        else if (data < 0)
        {
            printf("Error: Invalid input. Please enter a value >= 0");
            while(getchar() != '\n' && !feof(stdin));
            continue;
        }
        else
        {
            return data;
        }
    }
}

long int calculateSumOfDigits(int n)
{
    long int result = 0;

    if(n >= 0 && n <= 9) result = n;
    else
    {
        while(n > 0)
        {
            result += (n % 10);
            n = n / 10;
        }
    }

    return result;
}