/**
 * -------------------------------------------------------------------------------------------------------------------------------
 * Program written by : Kevin Kalpala
 * Date               : 29 / 12 / 25
 * 
 * Description:
 * This program demonstrates the merging and sorting of two pre-defined integer arrays.
 * It takes two arrays, A and B, each containing 5 elements, and merges them into a 
 * third array, C, such that elements from both arrays are combined in sorted order 
 * in pairs. The smaller element of each pair is placed first, followed by the larger 
 * element.
 * 
 * Input:
 * - No user input is required. Arrays A and B are initialized within the program.
 * 
 * Output:
 * - A merged array C containing elements from arrays A and B, displayed in a partially 
 *   sorted manner (smallest element of each corresponding pair first, followed by the largest).
 * 
 * Note:
 * - Arrays A and B are assumed to have exactly 5 meaningful elements each, 
 *   although the arrays are declared with size 10.
 * - Array C is of size 10 to accommodate all elements from A and B.
 * - The program uses the ternary operator to compare elements and merge them accordingly.
 * 
 * -------------------------------------------------------------------------------------------------------------------------------
 */

#include<stdio.h>

int main()
{
    int a[10] = {1, 3, 5, 7, 9};
    int b[10] = {2, 4, 6, 8, 10};
    int c[10];

    printf("\n****** Welcome User! ******\n");

    printf("Sorting and Merging arrays A and B into C...................\n");

    for(int i = 0, k = 0; i < 5; i++)
    {
        c[k++] = (a[i] < b[i]) ? a[i] : b[i];
        c[k++] = (a[i] > b[i]) ? a[i] : b[i];
    }

    printf("\n****** Array C ******\n");
    for(int i = 0; i < 10; i++)
    {
        printf("%d ", c[i]);
    }
    printf("\n");

    return 0;
}