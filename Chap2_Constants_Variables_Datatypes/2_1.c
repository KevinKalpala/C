/**
* Program written by Kevin Kalpala
* Date : 05/09/25
*
* Program to determine and print the sum of the harmonic series given below
* 1 + 1/2 + 1/3 +.............+ 1/n
*/

#include<stdio.h>

/**
* Function to calculate the sum of harmonic series 1+1/2+....+1/n for some value of n
* @param n No of digits of series
* @return Sum of series
*/
float cal_sum(int n);

int main()
{
    int n_digits; // To store the value of the no of digits
    float sum; // To store the sum of the series

    // Read the value of n_digits from the user
    printf("Enter the no of digits till which you want to calculate the sum of series\n");
    scanf("%d",&n_digits);

    // Calculate the sum of series
    sum = cal_sum(n_digits);

    // Display the result
    printf("The sum of the harmonic series 1+1/2+.........+1/n for n = %d is %f\n",n_digits,sum);

    return 0;
}

float cal_sum(int n)
{
    float result = 0; // To store the sum of series

    for(int i=1; i<=n; i++)
    {
        result = result + 1/i;
    }

    return result;
}