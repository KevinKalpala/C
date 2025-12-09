/**
 * -------------------------------------------------------------------------------------------------------------------------------
 * Program written by : Kevin Kalpala
 * Date               : 09 / 12 / 25
 * 
 * Description:
 *      This program prints two different patterns using nested for loops.
 *      (a) A number pattern where each row prints the row number repeatedly based on the row count.
 *      (b) A right-aligned star pattern where the number of stars decreases with each row.
 * 
 * Input:
 *      No input is required from the user.
 * 
 * Output:
 *      Pattern (a):
 *          1
 *          2 2
 *          3 3 3
 *          4 4 4 4
 *          5 5 5 5 5
 * 
 *      Pattern (b):
 *          * * * * *
 *            * * * *
 *              * * *
 *                * *
 *                  *
 * 
 * Note:
 *      The program demonstrates the use of nested loops for pattern printing.
 * -------------------------------------------------------------------------------------------------------------------------------
 */

#include<stdio.h>

int main()
{
    printf("\n****** Welcome User! ******\n\n");

    // (a) Printing pattern 1
    for(int i = 1; i <= 5; i++)
    {
        for(int j = 1; j <= i; j++)
        {
            printf("%d ", i);
        }
        printf("\n");
    }

    printf("\n");

    // (b) Printing pattern 2
    for(int i = 0; i < 5; i++)
    {
        for(int k = 0; k < i; k++)
        {
            printf("  ");
        }

        for(int j = (5 - i); j > 0; j--)
        {
            printf("* ");
        }
        printf("\n");
    }

    return 0;
}