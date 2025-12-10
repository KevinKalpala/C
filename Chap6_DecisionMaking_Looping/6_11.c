/**
 * -------------------------------------------------------------------------------------------------------------------------------------
 * Program written by : Kevin Kalpala
 * Date               : 10 / 12 / 25
 * 
 * Description:
 * This program reads a positive integer from the user and converts it into its binary
 * representation. The binary digits (bits) are calculated by repeatedly dividing the
 * number by 2 and storing the remainders. Finally, the stored bits are printed in
 * reverse order to display the correct binary equivalent.
 * 
 * Input:
 * A single positive integer entered by the user.
 * 
 * Output:
 * The binary equivalent of the entered integer, printed bit by bit.
 * 
 * Note:
 * - The program uses an integer array to store the binary digits.
 * - Input validation is performed to ensure the user enters a valid positive integer.
 * - The maximum number of bits stored is 30, which is sufficient for common integers.
 * -------------------------------------------------------------------------------------------------------------------------------------
 */

#include<stdio.h>

int getNumber();

int main()
{
    int number, i = 0;
    int binary[30];
    
    printf("\n****** Welcome User! ******\n");
    printf("Please enter a positive integer : ");
    number = getNumber();
    
    int temp = number;
    do
    {
        binary[i++] = temp % 2;
        temp /= 2;

    }while(temp > 0);

    printf("Binary equivalent : ");
    for(i = i - 1; i >= 0; i--)
    {
        printf("%d ", binary[i]);
    }
    
    printf("\n");
    
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
            printf("Please try again..................\n");
            while(getchar() != '\n' && !feof(stdin));
            continue;
        }
        else if (data <= 0)
        {
            printf("Error: Invalid input. Please enter a positive integer\n");
            while(getchar() != '\n' && !feof(stdin));
            continue;
        }
        else
        {
            return data;
        }
    }
}