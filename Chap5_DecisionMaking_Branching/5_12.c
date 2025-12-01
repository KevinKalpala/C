/**
 * --------------------------------------------------------------------------------------------------------------------------
 * Program written by : Kevin Kalpala
 * Date               : 01 / 12 / 25
 * 
 * Description:
 * 
 * 
 * Input:
 * 
 * 
 * Output:
 * 
 * 
 * Note:
 * 
 * --------------------------------------------------------------------------------------------------------------------------
 */

#include<stdio.h>

#define MIN_CHARGE 100

int getIntData();

void getCustomerDetails(char name[][10], int unit [], int customerNumber);

int main()
{
    int noOfCustomers;
    
    printf("\n****** Welcome User! ******\n");
    printf("Please enter the number of customers: ");
    noOfCustomers = getIntData();
    
    char names[noOfCustomers][10];
    int units[noOfCustomers];
    
    printf("Please enter the customer details for the customers:-\n");
    
    getCustomerDetails(names, units, noOfCustomers);
    
    return 0;
}

int getIntData()
{
    int data;
    
    while(1)
    {
        if (scanf("%d", &data) != 1)
        {
            printf("Error: Value could not be stored as an integer\n");
            printf("Please try again............\n");
            while(getchar() != '\n' && !feof(stdin));
            continue;
        }
        else
        {
            return data;
        }
    }
}

void getCustomerDetails(char name[][10], int unit [], int customerNumber)
{
    for (int i = 0; i < customerNumber; i++)
    {
        printf("Name : ");
        name[i][j]getName();
    }
}