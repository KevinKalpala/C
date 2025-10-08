/**
* Program written by Kevin Kalpala
* Date : 7/10/25
*
* Program to print the inventory report table of the ABC Electric Company manufactures four consumer products.
*/

#include<stdio.h>

#define MAXITEMS 4

int main()
{
    int i, quantity[5];
    float rate[5], value[5], totalValue;
    char code[5][5];

    i = 1;
    while(i <= MAXITEMS){
        printf("Please enter the item code, quantity and rate\n");
        scanf("%s %d %f", code[i], &quantity[i], &rate[i]);
        i++;
    }
    
    printf("----------------------------------------------------------------------\n");
    printf("                        INVENTORY REPORT                              \n");
    printf("----------------------------------------------------------------------\n"); 
    printf("%-15s\t%-15s\t%-15s\t%-15s\n", "Code", "Quantity", "Rate", "Value");
    printf("----------------------------------------------------------------------\n");
    
    totalValue = 0;
    i = 1;
    while(i <= MAXITEMS){
        value[i] = rate[i] * quantity[i];
        printf("%-15s\t%-15d\t%-15f\t%-e\n", code[i], quantity[i], rate[i], value[i]);
        totalValue += value[i];
        i++;
    }


    printf("----------------------------------------------------------------------\n");
    printf("                                  Total Value:  ");
    printf("%5e\n", totalValue);
    printf("----------------------------------------------------------------------\n");

    return 0;
}   