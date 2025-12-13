/**
 * ------------------------------------------------------------------------------------------------------------------------------------------
 * Program written by : Kevin Kalpala
 * Date               : 12 / 12 / 25
 * 
 * Description:
 * This program prints a 5 × 5 pattern using nested `for` loops.  
 * The pattern consists of the character 'S' printed at all positions
 * except the center of the matrix, where the character 'O' is printed.
 * The decision to print 'O' or 'S' is made using an `if` statement.
 * 
 * Input:
 * No input is required from the user. The size of the pattern
 * and the position of the special character are fixed in the program.
 * 
 * Output:
 * A 5 × 5 grid of characters is displayed on the screen.
 * The center position (row 3, column 3) contains 'O', while
 * all other positions contain 'S'.
 * 
 * Note:
 * - The indices `i == 2` and `j == 2` represent the center of the 5 × 5 grid
 *   because array indexing starts from 0.
 * - Nested loops are used to generate rows and columns of the pattern.
 * - The program demonstrates the use of conditional statements
 *   inside loops for pattern printing.
 * 
 * ------------------------------------------------------------------------------------------------------------------------------------------
 */

#include<stdio.h>

int main()
{
    printf("\n****** Welcome User! ******\n\n");
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            if(i == 2 && j == 2)
                printf("O ");
            else
                printf("S ");
        }
        printf("\n");
    }

    return 0;
}