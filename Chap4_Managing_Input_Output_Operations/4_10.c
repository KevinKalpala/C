/**
* Program written by Kevin Kalpala
* Date : 14/10/25
*
* Program to read and display the following table of data
* Name          Code            Price
* Fan           67831           1234.50
* Motor         450             5786.70
*/

#include<stdio.h>

void getProductDetails(char productName[], int* productCode, float* productPrice);

int main()
{
    int fanCode, motorCode;
    float fanPrice, motorPrice;
    char fanName[10], motorName[10];
    
    // Get the details from the user
    getProductDetails(fanName, &fanCode, &fanPrice);
    getProductDetails(motorName, &motorCode, &motorPrice);
    
    // Print the inventory details
    printf("\n\n------------------------------------------------------------------------------\n");
    printf("                                 INVENTORY DETAILS                                \n");
    printf("------------------------------------------------------------------------------\n");
    
    printf("%-30s\t%-30s\t%-30s\n", "Name", "Code", "Price");
    
    printf("------------------------------------------------------------------------------\n");
    
    printf("%-30s\t%-30d\t%6.2f\n", fanName, fanCode, fanPrice);
    printf("%-30s\t%-30d\t%6.2f\n", motorName, motorCode, motorPrice);
    
    printf("------------------------------------------------------------------------------\n");
    
    return 0;
}

void getProductDetails(char productName[], int* productCode, float* productPrice)
{
    while(1)
    {
        printf("Please enter the product name: ");
        if(scanf("%s", productName) != 1)
        {
            printf("Error: An unexpected error just occurred\n");
            printf("Please try again...............\n");
            while(getchar() != '\n');
            continue;
        }

        printf("Please enter the product code: ");
        if(scanf("%d", productCode) != 1)
        {
            printf("Error: An unexpected error just occurred\n");
            printf("Please try again...............\n");
            while(getchar() != '\n');
            continue;
        }

        printf("Please enter the product price: ");
        if(scanf("%f", productPrice) != 1)
        {
            printf("Error: An unexpected error just occurred\n");
            printf("Please try again...............\n");
            while(getchar() != '\n');
            continue;
        }else{
            break;
        }
    }
}