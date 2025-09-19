/**
* Program written by Kevin Kalpala
* Date : 19/09/25
* 
* Program to calculate the salvage value of an item when the purchase price, years of service and the annual-
* depreciation are given
*
* Note that the straight-line method of computing the yearly depreciation of the value of an item is given by
*
* Depreciation = (Purchase price - Salvage value) / Years of service
*
* So by rearranging the formula, we get:
* 
* Salvage Value = Purchase price - (Depreciation * Years of service)
*/

#include<stdio.h>

/**
* Program to calculate the Salvage value of an item
* @param price Purchase price
* @param years Years of service
* @param depreciation Depreciation in the value
* @return Result of (Purchase price - (Depreciation * Years of service))
*/
double calSalvageValue(double price, double years, double depreciation);

int main()
{
    double purchasePrice = 0, yearsOfService = 0, depreciationValue = 0, salvageValue = 0;

    // Read the values of purchase price, depreciation and years of service from the user
    printf("Enter the Purchase price of the item:\n");
    scanf("%lf", &purchasePrice);

    printf("Enter the years of service:\n");
    scanf("%lf", &yearsOfService);

    printf("Enter the Depreciation:\n");
    scanf("%lf", &depreciationValue);

    if(purchasePrice < 0 || yearsOfService < 0 || depreciationValue < 0)
    {
        printf("Invalid input. Please enter positive values\n");
        return 1;
    }else{
        // Calculate the Salvage value
        salvageValue = calSalvageValue(purchasePrice, yearsOfService, depreciationValue);

        // Display the Salvage value
        printf("Salvage value:\n%.2lf\n", salvageValue);
    }

    return 0;
}

double calSalvageValue(double price, double years, double depreciation)
{
    return price - (depreciation * years);
}