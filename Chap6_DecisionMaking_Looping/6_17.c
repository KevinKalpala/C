/**
 * ----------------------------------------------------------------------------------------------------------------------------
 * Program written by : Kevin Kalpala
 * Date               : 12 / 12 / 25
 * 
 * Description:
 * 
 * 
 * Input:
 * 
 * 
 * Output:
 * 
 * 
 * Note:
 * 
 * ----------------------------------------------------------------------------------------------------------------------------
 */

#include<stdio.h>
#include<math.h>

#define PI 3.141592653589793

int main()
{
    double x, y;
    
    printf("\n****** Welcome User! ******\n\n");
    
    printf("                                      Y axis --->\n");
    printf("  0---------------------------------------------------------------------------------------------------\n");
    for(double i = 0.0; i <= 180.0; i += 2.5)
    {
        if((int)i % 15 == 0)
        {
            x = ((PI / 180) * i);

            y = sin(x);

            int pos = (int) (y * 50);
            
            if (i == 90) printf("X |");
            else printf("  |");

            for(double j = 0; j < (pos - 1); j++)
                printf("  ");
            printf("*\n");
        }
        else
        {
            printf("  |\n");
            continue;
        }
    }

    
    return 0;
}