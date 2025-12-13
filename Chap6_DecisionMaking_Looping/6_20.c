/**
 * ---------------------------------------------------------------------------------------------------------------------------------------------------
 * Program written by : Kevin Kalpala
 * Date               : 12 / 12 / 25
 * 
 * Description:
 * This program reads a set of up to 10 two-digit integers (both positive and negative)
 * using a `for` loop and computes the sum of all positive values entered.
 * The program terminates input early if the running sum exceeds 999.
 * Input validation is performed to ensure that only valid two-digit integers
 * are accepted.
 * 
 * Input:
 * Up to 10 two-digit integers entered by the user through the keyboard.
 * The values may be positive or negative. Invalid inputs are rejected and
 * the user is prompted again until a valid two-digit integer is entered.
 * 
 * Output:
 * The program displays:
 * 1. The number of positive values added.
 * 2. The sum of all positive two-digit integers entered.
 * 
 * Note:
 * - Only positive two-digit integers are included in the sum.
 * - Input reading stops if the sum of positive values exceeds 999,
 *   even if fewer than 10 numbers have been entered.
 * - The program uses `scanf` for input and does not use the `goto` statement.
 * - A separate function is used to validate and read two-digit integers.
 * 
 * ---------------------------------------------------------------------------------------------------------------------------------------------------
 */

#include<stdio.h>

int getNumber();

int main()
{
    int number, count = 0, sum = 0;

    printf("\n****** Welcome User! ******\n\n");
    
    printf("Please enter 10 two-digit numbers :-\n");
    for(int i = 0; i < 10; i++)
    {
        number = getNumber(); 
        
        if (number > 0)
        {
            sum += number;
            count++;

            // If sum exceeds 999 then terminate reading values
            if (sum > 999) break;
        }
        else
        {
            continue;
        }
    }

    printf("\nNumbers added : %d\n", count);
    printf("Sum = %d\n", sum);
    
    return 0;
}

int getNumber()
{
    int data;

    while(1)
    {
        if (scanf("%d", &data) != 1)
        {
            printf("Error: Value could not be read as an integer\n");
            printf("Please try again........................\n");
            while(getchar() != '\n' && !feof(stdin));
            continue;
        }
        else if ((data < (-100) || data >= 100) || (data < 10 && data >= (-9)))
        {
            printf("Invalid input. Please enter a two-digit number\n");
            while(getchar() != '\n' && !feof(stdin));
            continue;
        }
        else
        {
            return data;
        }
    }
}