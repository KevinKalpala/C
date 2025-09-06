/**
* Program written by Kevin Kalpala
* Date : 06/09/25
*
* Program to read the price of an item in rupees and then print it in paise
*/

#include<stdio.h>

int cvrt_to_paise(float amount);

int main()
{
    float amt_rupees; // To store the amount of the item in rupees
    unsigned int amt_paise; // To store the amount of the item in paise

    // Read the amount of the item from user
    printf("Enter the price of the item\n");
    scanf("%f", &amt_rupees);

    // Calculate the value of amount in paise
    amt_paise = cvrt_to_paise(amt_rupees);

    // Display the result
    printf("%.2f Rupees = %u Paise\n", amt_rupees, amt_paise);

    return 0;
}

int cvrt_to_paise(float amount)
{
    // Convert rupees to paise by multiplying by 100; 
    return (int)(amount * 100 + 0.5); // adding 0.5 ensures proper rounding instead of truncation when casting to int
}