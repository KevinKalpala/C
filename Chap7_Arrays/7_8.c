/**
 * ------------------------------------------------------------------------------------------------------------------------
 * Program written by : Kevin Kalpala
 * Date               : 30 / 12 / 25
 * 
 * Description:
 * This program creates and displays a 5 × 5 matrix based on the following conditions:
 * 1. The upper left triangular portion of the matrix is filled with +1.
 * 2. The lower right triangular portion of the matrix is filled with -1.
 * 3. The right-to-left diagonal elements of the matrix are filled with 0.
 * The matrix is first populated using nested loops and then displayed using
 * formatted output to clearly show signed values.
 * 
 * Input:
 * No user input is required. The matrix size and values are predefined in the program.
 * 
 * Output:
 * Displays a 5 × 5 matrix where:
 * - Elements above the right-to-left diagonal are +1
 * - Elements on the right-to-left diagonal are 0
 * - Elements below the right-to-left diagonal are -1
 * Signed values are displayed using appropriate formatting.
 * 
 * Note:
 * The program uses only two printf statements for displaying the matrix contents,
 * adhering to the given constraint.
 * ------------------------------------------------------------------------------------------------------------------------
 */

#include<stdio.h>

int main()
{
    int arr[5][5] = {0};
    printf("\n****** Welcome User! ******\n");

    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            if ((j+1) == 5 - i) arr[i][j] = 0;
            else if ((j+1) < 5 - i) arr[i][j] = 1;
            else arr[i][j] = -1;
        }
    }

    // printing the array values
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            if (arr[i][j] == 1 || arr[i][j] == -1) printf("%+d ", arr[i][j]);
            else printf(" %d ", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}