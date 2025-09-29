/**
* Program written by Kevin Kalpala
* Date 29/09/25
*
* Program to calculate the Economic Order Quantity (EOQ) and the optimal Time Between Orders (TBO) for items in an inventory.
* Note : EOQ = sqrt((2 * demand rate * setup costs) / (holding cost per item per unit time))
*        TBO = sqrt((2 * setup costs) / (demand rate * holding cost per item per unit time))
*/

#include<stdio.h>
#include<math.h>

/**
* Program to calculate the Economic Order Quantity(EOQ)
* @param demand Demand rate (items per unit time)
* @param setupCosts Setup costs (per order)
* @param holdingCost Holding cost (per item per unit time)
* @return Value of sqrt( 2 * demand * setupCosts / holdingCost )
*/
double calculateEOQ(double demand, double setupCosts, double holdingCost);

/**
* Program to calculate the optimal Time Between Orders(TBO)
* @param demand Demand rate (items per unit time)
* @param setupCosts Setup costs (per order)
* @param holdingCost Holding cost (per item per unit time)
* @return Value of sqrt( 2 * setupCosts / (demand * holdingCost) )
*/
double calculateTBO(double demand, double setupCosts, double holdingCost);

int main()
{
    int status = 0;
    double demandRate, setupCosts, holdingCost;
    double eoq, tbo;

    do
    {
        status = 0;

        // Get the details for the item from the user
        printf("****** Welcome to the Program to calculate EOQ and TBO ******\n");
        printf("Please enter the following details:-\n");
        printf("Demand rate (items per unit time):\n");
        if(scanf("%lf", &demandRate) != 1 || demandRate <= 0)
        {
            while(getchar() != '\n');
            status = 1;
        }
        printf("Setup costs (per order):\n");
        if(scanf("%lf", &setupCosts) != 1 || setupCosts <= 0)
        {
            while(getchar() != '\n');
            status = 1;
        }
        printf("Holding cost (per item per unit time):\n");
        if(scanf("%lf", &holdingCost) != 1 || holdingCost <= 0)
        {
            while(getchar() != '\n');
            status = 1;
        }

        if(status == 1)
        {
            printf("Error: Please enter positive and non-zero values for all inputs\n");
        }

    }while(status == 1);

    // Calculate EOQ and TBO
    eoq = calculateEOQ(demandRate, setupCosts, holdingCost);
    tbo = calculateTBO(demandRate, setupCosts, holdingCost);

    // Display the results
    printf("Economic Order Quantity = %.2lf\n", eoq);
    printf("Optimal Time Between Orders = %.2lf\n", tbo);

    return 0;
}

double calculateEOQ(double demand, double setupCosts, double holdingCost)
{
    double result;

    result = sqrt( 2 * demand * setupCosts / holdingCost );

    return result;
}

double calculateTBO(double demand, double setupCosts, double holdingCost)
{
    double result;

    result = sqrt( 2 * setupCosts / (demand * holdingCost) );

    return result;
}