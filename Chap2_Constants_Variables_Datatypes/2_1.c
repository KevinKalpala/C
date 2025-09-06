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
* @param n Number of terms in the series
* @return Sum of series
*/
double cal_sum(int n);

int main()
{
    unsigned int n_terms; // Number of terms in the harmonic series
    double sum; // To store the sum of the series

    // Read the value of n_terms from the user
    printf("Enter the number of terms for which you want to calculate the harmonic series sum:\n");
    scanf("%u", &n_terms);

    // Calculate the sum of series
    sum = cal_sum(n_terms);

    // Display the result
    printf("The sum of the harmonic series 1+1/2+.........+1/n for n = %u is %.10f\n", n_terms, sum);

    return 0;
}

double cal_sum(int n)
{
    double result = 0; // To store the sum of series

    for(int i=1; i<=n; i++)
    {
        result = result + 1/(double)i;
    }

    return result;
}