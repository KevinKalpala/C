/**
 * -----------------------------------------------------------------------------------------------------------------------------------------
 * Program written by : Kevin Kalpala
 * Date               : 06 / 01 / 26
 * 
 * Description:
 * This program reads a line of text from the user and counts the number of
 * occurrences of a specified character in the given text.
 * 
 * Input:
 * - A line of text entered by the user.
 * - A single character whose occurrences are to be counted.
 * 
 * Output:
 * - Displays the total number of occurrences of the specified character
 *   in the given text.
 * 
 * Note:
 * - The string is read character by character until a newline is encountered.
 * - Indexing of the string starts from 0.
 * - Maximum string length supported is 1000 characters.
 * -----------------------------------------------------------------------------------------------------------------------------------------
 */

#include<stdio.h>

char getCharacter(char* prompt);

int main()
{
    int strLength = 0, charCount = 0;
    char string[1000];
    
    printf("\n****** Welcome User! ******\n\n");
    
    printf("Please enter the string :-\n");
    for(int i = 0; i < 1000; i++)
    {
        string[i] = getchar();

        if (string[i] != '\n') strLength++;
        else
        {
            string[i] = '\0';
            break;
        }
    }
    
    char c = getCharacter("Please enter the character you want to search : ");

    for(int i = 0; i < strLength; i++)
    {
        if (string[i] == c)
        {
            charCount++;
        }
    }

    printf("\nNo of occurrences of the character : %d\n", charCount);
    
    return 0;
}

char getCharacter(char* prompt)
{
    char ch;

    while(1)
    {
        printf("%s", prompt);
        if (scanf("%c", &ch) != 1)
        {
            printf("Error: Value could not be read as a character\n");
            printf("Please try again..........\n");
            while(getchar() != '\n' && !feof(stdin));
            continue;
        }
        else
        {
            return ch;
        }
    }
}