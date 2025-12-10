/**
 * ------------------------------------------------------------------------------------------------------------------------------------
 * Program written by : Kevin Kalpala
 * Date               : 10 / 12 / 25
 * 
 * Description:
 *      This program prints the capital letter 'S' inside a grid of 15 rows and 19 columns.
 *      The pattern is created using nested for-loops and ONLY if statements, as required.
 *      Each row and column is checked with specific conditions to determine whether to print
 *      '-', '*', or a blank space to form the correct shape of the letter S.
 * 
 * Input:
 *      No input is required from the user. The program directly prints the pattern.
 * 
 * Output:
 *      A 15 × 19 grid displayed on the screen, showing the capital letter 'S' constructed
 *      using symbols (‘-’, ‘*’, and spaces) exactly as required in the given assignment.
 * 
 * Note:
 *      The program uses only 'if' statements (no else or switch), fulfilling the problem requirement.
 *      Variables i and j represent the row and column positions of the grid.
 * 
 * ------------------------------------------------------------------------------------------------------------------------------------
 */

#include<stdio.h>

int main()
{
    for(int i = 0; i < 15; i++)
    {
        for(int j = 0; j < 19; j++)
        {
            int printStatus = 0;
            if(i == 1 && (j >= 2 && j <= 16))
            {
                printf("- ");
                printStatus = 1;
            }

            if (i == 2 && (j >= 9 && j <= 16))
            {
                printf("- ");
                printStatus = 1;
            }

            if (((i >= 3 && i <= 5) && (j >= 4)) || ((i >= 9 && i <= 11) && (j < 15)))
            {
                printf("  ");
                printStatus = 1;
            }
            if ((i == 6 && (j >= 5 && j <= 14)) || (i == 7 && j < 15) || (i == 8 && j < 15))
            {
                printf("- ");
                printStatus = 1;
            }
            if ((i == 12 && (j >= 4 && j < 15)) || (i == 13 && (j >= 3 && j < 15)) || (i == 14 && (j >= 2 && j < 15)))
            {
                printf("- ");
                printStatus = 1;
            }
            if (printStatus == 0)
            {
                printf("* ");
            }
        }
        printf("\n");
    }

    return 0;
}