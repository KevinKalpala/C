/**
* Program written by Kevin Kalpala
* Date : 14/10/25
*
* Program that prints the value 345.6789 in fixed-point format with the following specifications
* (a) correct to two decimal places
* (b) correct to five decimal places
* (c) correct to zero decimal places
*/

#include<stdio.h>

int main()
{
    float num = 345.6789;

    printf("(a) %.2f\n", num);
    printf("(b) %.5f\n", num);
    printf("(c) %.0f\n", num);

    return 0;
}