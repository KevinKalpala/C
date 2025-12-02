/**
 * ------------------------------------------------------------------------------------------------
 * Program written by : Kevin Kalpala
 * Date               : 02 / 12 / 25
 * 
 * Description:
 *  This program computes and displays all integers between 0 and 100 that are divisible by 6 
 *  but not divisible by 4. It also counts and displays the number of such integers along 
 *  with their total sum.
 * 
 * Input:
 *  No input is required from the user. The program uses the range 0 to 100 by default.
 * 
 * Output:
 *  - List of numbers divisible by 6 but not divisible by 4 within the given range.
 *  - The total number of such values.
 *  - The sum of all these values.
 * 
 * Note:
 *  The range can be modified if needed by changing the value of 'minValue' and 'maxValue'.
 * ------------------------------------------------------------------------------------------------
 */

#include<stdio.h>

int main()
{
    int minValue = 0, maxValue = 100;
    int count = 0, sum = 0;

    printf("\nNumbers between %d and %d that are divisible by 6 but not divisible by 4 are given below:-\n", minValue, maxValue);
    for (int i = minValue; i <= maxValue; i++)
    {
        if(i % 6 == 0 && i % 4 != 0)
        {
            count++;
            sum += i;
            printf(" %d,", i);
        }
    }

    printf("\nTotal numbers : %d\n", count);
    printf("Sum           : %d\n", sum);

    return 0;
}