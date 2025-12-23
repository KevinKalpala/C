/**
 * ---------------------------------------------------------------------------------------------------------------------------------------------
 * Program written by : Kevin Kalpala
 * Date               : 23 / 12 / 25
 * 
 * Description:
 * This program generates and prints Pascal's Triangle for a fixed number of rows.
 * Each element of the triangle is calculated using the relation:
 *      p(i,j) = p(i-1,j-1) + p(i-1,j)
 * except for the boundary elements, which are always equal to 1.
 * The triangle is stored in a one-dimensional array for efficient memory usage.
 * 
 * Input:
 * No user input is required.
 * The number of rows to be printed is defined using a macro.
 * 
 * Output:
 * Displays Pascal's Triangle up to 10 rows on the screen.
 * 
 * Note:
 * - The first and last elements of every row are initialized to 1.
 * - Middle elements are computed using values from the previous row.
 * - The total number of elements is calculated using the formula N(N+1)/2.
 * ---------------------------------------------------------------------------------------------------------------------------------------------
 */

#include<stdio.h>

#define ROWS 10
#define SIZE (ROWS * (ROWS + 1)) / 2

int main()
{
    int count1 = 0, count2 = 0;
    int pTriangle[SIZE];

    printf("\n****** Pascal triangle ******\n");

    for(int i = 1; i <= ROWS; i++)
    {
        for(int j = 1; j <= i; j++)
        {
            if (j == 1 || i == j) pTriangle[count1++] = 1;
            else
            {
                pTriangle[count1] = pTriangle[count1-(i)] + pTriangle[count1-(i - 1)];
                count1++;
            }
        }
    }

    for(int i = 1; i <= ROWS; i++)
    {
        for(int j = 1; j <= i; j++)
        {
            printf("%3d ", pTriangle[count2++]);
        }
        printf("\n");
    }

    return 0;
}