/**
 * ----------------------------------------------------------------------------------------------------------------------------
 * Program Name      : Investment Growth Table Generator
 * Program Written by: Kevin Kalpala
 * Date              : 09 / 12 / 25
 * 
 * Description:
 * This program calculates and displays the investment value over time using the compound
 * interest formula V = P(1 + r). The value (V) is recalculated each year, and the new value
 * becomes the principal for the next year's calculation. The program prints formatted tables 
 * showing the growth of investment for various combinations of principal amounts, interest 
 * rates, and years.
 * 
 * Input:
 * No user input is required. The program automatically generates:
 * - Principal amounts from 1000 to 10000 (increment of 1000)
 * - Interest rates from 0.10 to 0.20 (increment of 0.01)
 * - Number of years from 1 to 10
 * 
 * Output:
 * The program displays a formatted table for each combination of principal amount and interest 
 * rate. Each table shows:
 * - Principal amount
 * - Interest rate
 * - Number of years
 * - Calculated value after compounding
 *
 * Example Output Snippet:
 * 
 * For P = 1000.00 and R = 0.10
 * --------------------------------------------------------------
 * | Principal      | Rate           | Years          | Value   |
 * --------------------------------------------------------------
 * | 1000.00        | 0.10           | 1              | 1100.00 |
 * | 1100.00        | 0.10           | 2              | 1210.00 |
 * ...
 * 
 * Note:
 * - The principal value is updated each year, demonstrating compound growth.
 * - No external input or file handling is performed.
 * ----------------------------------------------------------------------------------------------------------------------------
 */

#include<stdio.h>
#include<math.h>

#define principalAmtLimit 10000
#define yearsLimit 10
#define rateOfInterestLimit 0.20

void calculateValue(int p, double r, int n);

int main()
{
    int principalAmt = 1000, years = 1;
    double rateOfInterest = 0.10;
    
    calculateValue(principalAmt, rateOfInterest, years);
    
    return 0;
}

void calculateValue(int p, double r, int n)
{
    double j = r;
    for (int i = p; (i <= principalAmtLimit && j <= (rateOfInterestLimit + 0.01)) ; i += 1000, j += 0.01)
    {
        double value = i;

        double result;
    
        printf("\nFor P = %.2lf and R = %.2lf\n", value, j);
    
        printf("\n---------------------------------------------------------------------\n");
        printf("| %-15s| %-15s| %-15s| %-15s|\n", "Principal", "Rate", "Years", "Value");
        
        for(int k = n; k <= yearsLimit; k++)
        {
            printf("---------------------------------------------------------------------\n");
            result = value * (1 + j);
            printf("| %-15.2lf| %-15.2lf| %-15d| %-15.2lf|\n", value, j, k, result);
            value = result;
        }
        printf("---------------------------------------------------------------------\n");
    }
}