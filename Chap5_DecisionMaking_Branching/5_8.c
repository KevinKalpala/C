/**
 * -----------------------------------------------------------------------------------------
 * Program written by : Kevin Kalpala
 * Date               : 26 / 11 / 2025
 * 
 * Description:
 *      This program computes the net amount to be paid by a customer based on the seasonal
 *      discount policy of a cloth showroom. The store provides different discount rates for 
 *      two categories of items:
 *          1. Mill cloth
 *          2. Handloom items
 * 
 *      The discount percentage depends on the purchase amount slab. The program first takes 
 *      the purchase amounts for both categories, validates the input, then:
 *          - Determines the correct discount slab using if–else statements
 *          - Applies the appropriate discount using a switch statement
 *          - Computes and displays the final net amount to be paid
 * 
 * Input:
 *      - Purchase amount for mill cloth (floating-point number, >= 0)
 *      - Purchase amount for handloom items (floating-point number, >= 0)
 * 
 * Output:
 *      - Detailed bill summary including:
 *          * Mill cloth purchase amount and discount
 *          * Handloom items purchase amount and discount
 *          * Final net payable amount
 * 
 * Note:
 *      - All inputs are validated to ensure the user enters valid floating-point values.
 *      - The program strictly uses both IF and SWITCH statements as required by the question.
 * -----------------------------------------------------------------------------------------
 */

#include <stdio.h>

double getDoubleData(double minLimit);
void calculateNetAmt(double millAmt, double handloomAmt);

int main()
{
    double millClothAmt, handloomItemsAmt;
    
    printf("\n****** Welcome User! ******\n");
    printf("Please enter the purchase amount of mill cloth: ");
    millClothAmt = getDoubleData(0.0);

    printf("Please enter the purchase amount of handloom items: ");
    handloomItemsAmt = getDoubleData(0.0);
    
    calculateNetAmt(millClothAmt, handloomItemsAmt);
    
    return 0;
}

double getDoubleData(double minLimit)
{
    double data;

    while (1)
    {
        if (scanf("%lf", &data) != 1)
        {
            printf("Error: Input value could not be read as a floating point number\n");
            while (getchar() != '\n' && !feof(stdin));
            continue;
        }
        
        else if (data < minLimit)
        {
            printf("Please enter a floating point value >= %.2lf\n", minLimit);
            continue;
        }
        
        else
        {
            return data;
        }
    }
}

void calculateNetAmt(double millAmt, double handloomAmt)
{
    int choice;
    double millDiscount = 0.0, handloomDiscount = 0.0;
    double netAmt;

    /* ---------- Calculate mill cloth discount ---------- */
    // Categorize into slabs for switch
    if (millAmt <= 100) choice = 1;
    else if (millAmt <= 200) choice = 2;
    else if (millAmt <= 300) choice = 3;
    else choice = 4;

    switch (choice)
    {
        case 1: millDiscount = millAmt * 0.0;   break;
        case 2: millDiscount = millAmt * 0.05;  break;
        case 3: millDiscount = millAmt * 0.075; break;
        case 4: millDiscount = millAmt * 0.10;  break;
    }

    /* ---------- Calculate handloom items discount ---------- */
    if (handloomAmt <= 100) choice = 1;
    else if (handloomAmt <= 200) choice = 2;
    else if (handloomAmt <= 300) choice = 3;
    else choice = 4;

    switch (choice)
    {
        case 1: handloomDiscount = handloomAmt * 0.05;  break;
        case 2: handloomDiscount = handloomAmt * 0.075; break;
        case 3: handloomDiscount = handloomAmt * 0.10;  break;
        case 4: handloomDiscount = handloomAmt * 0.15;  break;
    }

    /* ---------- Calculate net amount ---------- */
    netAmt = (millAmt - millDiscount) + (handloomAmt - handloomDiscount);

    printf("\n--------- BILL SUMMARY ---------\n");
    printf("Mill cloth purchase amount       : %.2lf\n", millAmt);
    printf("Mill cloth discount              : %.2lf\n\n", millDiscount);

    printf("Handloom items purchase amount   : %.2lf\n", handloomAmt);
    printf("Handloom items discount          : %.2lf\n\n", handloomDiscount);

    printf("Net amount to be paid            : %.2lf\n", netAmt);
}