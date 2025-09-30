/**
* Program written by Kevin Kalpala
* Date 30/09/25
*
* Program to compute the values of square-roots and squares of the numbers 0 to 100 in steps of 10 and print the output.
*/

#include<stdio.h>
#include<math.h>

int main()
{
    printf("\n-------------------------------------------------------------------------\n");
    printf("%-20s%-20s%-20s\n","Number","Square-root","Square");
    printf("\n-------------------------------------------------------------------------\n");

    for(int i = 0; i <= 100; i += 10)
    {
        int square = i * i;
        double squareRoot = sqrt((double)i);

        printf("%-20d%-20.2lf%-20d\n", i, squareRoot, square);
    }

    return 0;
}