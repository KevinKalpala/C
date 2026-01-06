/**
 * ------------------------------------------------------------------------------------------------------------------------------------
 * Program written by : Kevin Kalpala
 * Date               : 06 / 01 / 26
 * 
 * Description:
 * This program reads a character string from the user and computes the length of the string
 * without using any built-in string handling functions. The length is calculated by counting
 * the number of characters entered until the newline character is encountered.
 * 
 * Input:
 * A character string entered by the user through standard input.
 * 
 * Output:
 * Displays the length of the entered character string and prints the string itself.
 * 
 * Note:
 * - The string input is terminated when the Enter key is pressed.
 * - The newline character is not included in the length calculation.
 * - Maximum string length supported is 99 characters.
 * 
 * ------------------------------------------------------------------------------------------------------------------------------------
 */

#include<stdio.h>

int main()
{
    int strLength = 0;
    char string[100];
    printf("\n****** Welcome User! ******\n\n");

    printf("Please enter the character string :-\n");
    for(int i = 0; i < 100; i++)
    {
        string[i] = getchar();
        if (string[i] != '\n') strLength++;
        else 
        {
            string[i] = '\0';
            break;
        }
    }


    printf("\nString length = %d\n", strLength);

    printf("The given string was :-\n");
    for(int i = 0; i < strLength; i++)
    {
        printf("%c", string[i]);
    }
    printf("\n");

    return 0;
}