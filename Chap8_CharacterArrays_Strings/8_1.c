/**
 * ------------------------------------------------------------------------------------------------
 * Program written by : Kevin Kalpala
 * Date               : 12 / 02 / 25
 * 
 * Description:
 * This program reads a name from the keyboard and prints the ASCII
 * code value of each character in the given name.
 * 
 * Input:
 * A string (name) entered by the user through standard input.
 * 
 * Output:
 * The ASCII values (in decimal form) corresponding to each character
 * of the entered name.
 * 
 * Note:
 * - The program uses fgets() for safe input.
 * - The newline character added by fgets() is removed using strcspn().
 * - ASCII values are printed using %d format specifier.
 * ------------------------------------------------------------------------------------------------
 */

#include<stdio.h>
#include<string.h>

int main()
{
    char name[50];
    printf("\nPlease enter your name: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';

    printf("Printing the ASCII code value for the given name:-\n");
    for(int i = 0; name[i] != '\0'; i++)
    {
        printf("%d ", name[i]);
    }

    printf("\n");

    return 0;
}