/**
* ----------------------------------------------------------------
* Program written by : Kevin Kalpala
* Date               : 10 / 11 / 25
* 
* Description:
*    This program calculates the total number of integers greater 
*    than 100 and less than 200 that are divisible by 7 and their 
*    sum.  
*
* Input:
*    None
*
* Output:
*    Display the total integers and sum of those integers that 
*    are greater than 100 and less than 200 that are divisible 
*    by 7.
*
* Note:
*    None
* ----------------------------------------------------------------
*/

#include<stdio.h>

int main()
{
    int sum = 0, numbers = 0;

    for(int i = 101; i < 200; i++)
    {
        if(i % 7 == 0)
        {
            numbers++;
            sum = sum + i;
        }
    }

    printf("Total number of integers greater than 100 and less than 200 that are divisible by 7 is : %d\n", numbers);
    printf("Sum of all integers greater than 100 and less than 200 that are divisible by 7 is : %d\n", sum);

    return 0;
}