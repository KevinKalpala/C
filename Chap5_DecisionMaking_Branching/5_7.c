/**
 * -----------------------------------------------------------------------------------------------------------------------------
 * Program written by : Kevin Kalpala
 * Date               : 21 / 11 / 25
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
 * -----------------------------------------------------------------------------------------------------------------------------
 */

#include<stdio.h>

int main()
{
    // (a) Original Floyd's triangle
    int count = 1;
    int nextStartValue = 1;
    for(int i = 1; i <= 91; i++)
    {
        int lastColValue = 0;
        for(int col = 0; col < count; col++)
        {
            printf("%d", nextStartValue+col);
            lastColValue = col;
        }
        printf("\n");

        nextStartValue += lastColValue;
        count++;

        if(nextStartValue > 91)
        {
            break;
        }
    }

    return 0;
}