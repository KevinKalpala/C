/**
 * -----------------------------------------------------------------------------------------------------------------------------------
 * Program written by : Kevin Kalpala
 * Date               : 05 / 12 / 25
 * 
 * Description:
 * This program takes a positive integer from the user and reverses its digits using a while loop.
 * It demonstrates number manipulation using modulus and division operations.
 *
 * Input:
 * A positive non-zero integer value entered by the user.
 *
 * Output:
 * The reversed form of the entered number.
 *
 * Note:
 * - The program validates user input to ensure only positive integers are accepted.
 * - No floating-point or negative values are allowed.
 * -----------------------------------------------------------------------------------------------------------------------------------
 */

#include<stdio.h>

int getIntData();

void printValue(int num);

int main()
{
    int number;
    
    printf("\n****** Welcome User! ******\n");
    printf("Please enter a number : ");
    number = getIntData();
    
    printValue(number);
    
    return 0;
}

int getIntData()
{   
    int data;
    
    while (1)
    {
        if (scanf("%d", &data) != 1)
        {
            printf("Error: Value could not be stored as an integer\n");
            printf("Please try again.............................\n");
            while(getchar() != '\n' && !feof(stdin));
            continue;
        }
        else if (data < 0)
        {
            printf("Error: Invalid input. Please enter a positive and non-zero value\n");
            while(getchar() != '\n' && !feof(stdin));
            continue;
        }
        else
        {
            return data;
        }
    }
}

void printValue(int num)
{
    int reverseNumber = 0;

    printf("The number : %d\n", num);

    printf("Printing..................\n");

    printf("Reversed Number : ");
    
    while(num != 0)
    {
        int digits = ( num % 10 );
        printf("%d", digits);
        num = num / 10;
        reverseNumber = reverseNumber * 10 + digits;
    }

    printf("\n");
}