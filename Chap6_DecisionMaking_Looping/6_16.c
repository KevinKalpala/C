/**
 * ------------------------------------------------------------------------------------------------------------------------------------
 * Program written by : Kevin Kalpala
 * Date               : 12 / 12 / 25
 * 
 * Description:
 * This program prints two different 5×5 patterns using nested for loops.
 * 
 * Pattern (a): A solid square where every position is filled with the character 'S'.
 * Pattern (b): A hollow square where only the border positions contain 'S'
 *              and the inner positions are left blank.
 * 
 * Input:
 * This program does not take any input from the user. All patterns are printed 
 * using fixed loop ranges and conditions.
 * 
 * Output:
 * (a) A 5x5 solid block of 'S'
 * (b) A 5x5 hollow square made of 'S'
 * 
 * Note:
 * - Nested loops are used to control rows and columns.
 * - Conditional statements are used in Pattern (b) to determine border positions.
 * ------------------------------------------------------------------------------------------------------------------------------------
 */

#include<stdio.h>

int main()
{
    // **********************   Pattern A   **************************
    
    printf("(a) Pattern 1\n\n");
    for(int i = 1; i <= 5; i++)
    {
        for(int j = 1; j <= 5; j++)
        {
            printf("S ");
        }
        printf("\n");
    }
    
    // **********************   Pattern B   **************************
    
    printf("\n(b) Pattern 2\n\n");
    for(int i = 1; i <= 5; i++)
    {
        for(int j = 1; j <= 5; j++)
        {
            if(i == 1 || i == 5 || j == 1 || j == 5)
            {
                printf("S ");
            }
            else
            {
                printf("  ");
            }
        }

        printf("\n");
    }

    return 0;

}