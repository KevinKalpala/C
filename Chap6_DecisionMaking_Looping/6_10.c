/**
 * --------------------------------------------------------------------------------------------------------------------------------------
 * Program written by : Kevin Kalpala
 * Date               : 10 / 12 / 25
 * 
 * Description:
 *   This program prints a neatly formatted table of values for the function:
 *        Y = exp(-X)
 *   It evaluates Y for X ranging from 0.0 to 9.9 in increments of 0.1.
 *   The table displays X values across rows and the corresponding exponential values
 *   across columns for each 0.1 step.
 * 
 * Input:
 *   The program does not take any input from the user.
 *   It internally generates values of X by combining:
 *      - Integer part (i) from 0 to 9
 *      - Decimal part (j) from 0.0 to 0.9 in steps of 0.1
 * 
 * Output:
 *   A well-formatted table with:
 *     - X values listed horizontally from 0.0 to 0.9
 *     - Y = exp(-X) values printed for each row (X = i + j)
 *   The output allows clear visualization of exponential decay across a range of X.
 * 
 * Note:
 *   The exp() function from <math.h> is used.
 *   The table format is designed to be wide for readability.
 * --------------------------------------------------------------------------------------------------------------------------------------
 */

#include<stdio.h>
#include<math.h>

int main()
{
    float i, j, y, x;

    printf("\n****** Welcome User! ******\n\n");
    
    printf("                                                  Table for Y = EXP(-X)\n");
    printf("---------------------------------------------------------------------------------------------------------------------------------\n");
    printf("     x  ");
    for(i = 0.0; i < 1; i += 0.1)
        printf("       %.1lf  ", i);
        printf("\n---------------------------------------------------------------------------------------------------------------------------------\n");
        
        for(i = 0.0; i < 10; i += 1.0)
        {
            printf("    %.1lf   ", i);
            
            for(j = 0.0; j < 1; j += 0.1)
            {
                x = i + j;
                y = exp(-x);
                printf("    %.3lf   ", y);
            }
            printf("\n");
        }
        printf("---------------------------------------------------------------------------------------------------------------------------------\n");
        
        return 0;
}