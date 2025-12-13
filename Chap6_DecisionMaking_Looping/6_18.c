/**
 * ------------------------------------------------------------------------------------------------------------------------------------------------
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
 * ------------------------------------------------------------------------------------------------------------------------------------------------
 */

#include<stdio.h>

int main()
{
    int count = 0;
    printf("\n****** Welcome User! ******\n");

    printf("\nIntegers divisible by either 2 or 3 and lie between 1 and 100 : ");
    for(int i = 1; i <= 100; i++)
    {
        if((i % 2 == 0) || (i % 3 == 0)) 
        {
            if(i < 100)
            {
                printf("%d, ", i);
            }
            else
            {
                printf("%d\n", i);
            }
            count++;
        }
    }

    printf("Total count of such integers : %d\n", count);

    return 0;
}