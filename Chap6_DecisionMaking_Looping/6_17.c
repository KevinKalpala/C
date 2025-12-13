/**
 * -------------------------------------------------------------------------------------------------------------------------------
 * Program written by : Kevin Kalpala
 * Date               : 13 / 12 / 25
 *
 * Description:
 * This program graphs the trigonometric function y = sin(x) using character plotting.
 * The graph is drawn for angles from 0 degrees to 360 degrees in steps of 15 degrees.
 * The sine values are scaled and rounded to obtain proper horizontal positions
 * and are displayed using ASCII characters.
 *
 * Input:
 * No user input is required.
 *
 * Output:
 * An ASCII-based graphical representation of y = sin(x) with a fixed vertical axis
 * and scaled sine values plotted using '*' characters.
 *
 * Note:
 * - Degrees are converted to radians before calculating sine.
 * - Scaling and rounding are used to improve graph accuracy.
 * - The program demonstrates the use of loops, math functions, and formatted output.
 * -------------------------------------------------------------------------------------------------------------------------------
 */

#include<stdio.h>
#include<math.h>

#define PI 3.141592653589793

int main()
{
    double x, y;
    
    printf("\n****** Welcome User! ******\n\n");
    
    printf("                                                    <--- Y axis --->\n");
    printf("------------------------------------------------------------0------------------------------------------------------------\n");
    for(int i = 0; i <= 360; i += 15)
    {
        x = ((PI / 180) * i);

        y = sin(x);

        int pos = (int) (y * 40 + 0.5);

        if(pos >= 0)
        {
            if(pos == 0)
            {
                for(int j = 0; j < 60; j++)
                    printf(" ");
                printf("*\n");
            }
            else
            {
                for(int j = 0; j < 60; j++)
                    printf(" ");
                printf("|");
                
                for(double j = 0; j < pos; j++)
                    printf(" ");
                printf("*\n");
            }
        }

        else
        {
            for(int j = 0; j < 60 + pos; j++)
                printf(" ");
            printf("*");

            for(int j = 0; j < ((-pos) - 1); j++)
                printf(" ");
            printf("|\n");
        }
    }

    return 0;
}