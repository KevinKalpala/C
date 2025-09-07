/**
* Program written by Kevin Kalpala
* Date : 07/09/25
*
* Program to illustrate the use of typedef declaration in a program
*/

#include<stdio.h>

// typedef declarations outside to get wider scope
typedef int itemNo;
typedef float price;

int main()
{
    // Declare variables using typedef aliases
    itemNo i = 121;
    price p1 = 23.155;

    // Print item number
    printf("ItemNo = %d\n", i);

    // Print price with two decimal places (common for currency)
    printf("Price = %.2f\n", p1);

    return 0;
}