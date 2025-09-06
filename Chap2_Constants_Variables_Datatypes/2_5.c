/**
* Program written by Kevin Kalpala
* Date : 06/09/25
*
* Program to read value of 1kg rice and 1kg sugar is rupees and print it in the given format
*/

#include<stdio.h>

void print_prices(float p1, int p2);

int main()
{
    // Declare variables to store the prices of rice and sugar
    int pr_sugar;
    float pr_rice; 

    // Read the value from the user
    printf("Enter the price of 1Kg Rice:\n");
    scanf("%f", &pr_rice);

    printf("Enter the price of 1Kg Sugar:\n");
    scanf("%d", &pr_sugar);

    // Display the values
    print_prices(pr_rice, pr_sugar);

    return 0;
}

void print_prices(float p1, int p2)
{
    printf("*** LIST OF ITEMS ***\n");
    printf("Item\tPrice\n");
    printf("Rice\tRs %.2f\n", p1);
    printf("Sugar\tRs %.2f\n", (float)p2);
}