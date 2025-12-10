/**
 * -------------------------------------------------------------------------------------------------------------------------------
 * Program written by : Kevin Kalpala
 * Date               : 10 / 12 / 25
 * 
 * Description:
 *   This program prints a horizontal 2D ASCII graph of two exponential functions:
 *   y1 = 50 * e^(-a*x)
 *   y2 = 50 * e^(-(a*x*x)/2)
 *   It compares both values at each x-step and prints a visual representation 
 *   using different characters (#, *, 0, -) to show their relative positions.
 * 
 * Input:
 *   No input is taken from the user. The program uses:
 *     - a = 0.4
 *     - x ranges from 0 to 5 in steps of 0.25
 * 
 * Output:
 *   A horizontally plotted ASCII graph where:
 *     - "#" marks the point where y1 and y2 overlap
 *     - "*" marks y2 and "0" marks y1 when they differ
 *     - "-" is used to draw the gap between the two function values
 * 
 * Note:
 *   The graph displays Y-values horizontally and X-values vertically.
 *   The x = 2.5 position is marked on the graph with an "X" indicator.
 * -------------------------------------------------------------------------------------------------------------------------------
 */

#include<stdio.h>
#include<math.h>

int main()
{
    int i;
    float a, x, y1, y2;
    a = 0.4;
    
    printf("                                      Y ---->\n");
    printf("   0 -----------------------------------------------------------------------------------\n");

    for(x = 0; x < 5; x += 0.25)
    {
        y1 = (int) ( 50 * exp(-a * x) + 0.5);
        y2 = (int) ( 50 * exp(-a * x * x / 2) + 0.5);

        if (y1 == y2)
        {
            if (x == 2.5)
                printf(" X | ");
            else
                printf("   |  ");
            
            for(i = 1; i <= y1 - 1; ++i)
                printf(" ");
            printf("#\n");
        }
        
        else if (y1 > y2)
        {
            if (x == 2.5)
                printf(" X | ");
            else
                printf("   |  ");
            
            for(i = 1; i <= y2 - 1; ++i)
                printf(" ");
            printf("*");
            
            for(i = 1; i <= (y1 - y2 - 1); ++i)
                printf("-");
            printf("0\n");
        }
            
        else
        {
            if (x == 2.5)
                printf(" X | ");
            else
                printf("   |  ");
        
            for(i = 1; i <= y1 - 1; ++i)
                printf(" ");
            printf("0");
            
            for(i = 1; i <= (y2 - y1 - 1); ++i)
                printf("-");
            printf("*\n");
        }
    }

    return 0;
}