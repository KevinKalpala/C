/**
* Program written by Kevin Kalpala
* Date : 14/10/25
*
* Program that prints the value 10.45678 in exponential format with the following specifications
* (a) correct to two decimal places
* (b) correct to four decimal places
* (c) correct to eight decimal places
*/

#include<stdio.h>

int main()
{
    float num = 10.45678;

    printf("(a) %.2e\n", num);
    printf("(b) %.4e\n", num);
    printf("(c) %.8e\n", num);

    return 0;
}