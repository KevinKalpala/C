/**
 * ------------------------------------------------------------------------------------------------
 * Program written by : Kevin Kalpala
 * Date               : 02 / 12 / 25
 * 
 * Description:
 *  This program reads the names of electricity consumers along with the number of units consumed.
 *  Based on the consumption, it calculates the bill amount using the following rate structure:
 *  
 *      - First 200 units:  ₹0.80 per unit
 *      - Next 100 units:   ₹0.90 per unit
 *      - Beyond 300 units: ₹1.00 per unit
 *  
 *  A minimum meter charge of ₹100 is applied to all customers. If the final calculated bill amount 
 *  exceeds ₹400, a surcharge of 15% is added.
 * 
 * Input:
 *  - Number of customers
 *  - Each customer's name
 *  - Units consumed by each customer
 * 
 * Output:
 *  Displays the following information for each customer:
 *  - Customer Name
 *  - Units Consumed
 *  - Final Electricity Bill Amount
 * 
 * Note:
 *  Input validation is performed to ensure only valid integers and non-empty names are accepted.
 * ------------------------------------------------------------------------------------------------
 */

#include<stdio.h>
#include<string.h>

#define MIN_CHARGE 100
#define MAX_NAME_LENGTH 21

int getIntData();

void getCustomerDetails(char name[][MAX_NAME_LENGTH], int unit [], int customerNumber);

void getName(char name[], int size);

void getUnit(int* unit);

void calculateBill(char name[][MAX_NAME_LENGTH], int unit[], int customerCount);

int main()
{
    int noOfCustomers;
    
    printf("\n****** Welcome User! ******\n");
    printf("Please enter the number of customers: ");
    noOfCustomers = getIntData();
    
    char names[noOfCustomers][MAX_NAME_LENGTH];
    int units[noOfCustomers];
    
    printf("Please enter the details for the customers:-\n");
    
    getCustomerDetails(names, units, noOfCustomers);
    
    calculateBill(names, units, noOfCustomers);
    
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
            while(getchar() != '\n' && !feof(stdin));
            return data;
            
        }
    }
}

void getCustomerDetails(char name[][MAX_NAME_LENGTH], int unit [], int customerNumber)
{
    for (int i = 0; i < customerNumber; i++)
    {
        printf("Please enter the name of the customer : ");
        getName(name[i], MAX_NAME_LENGTH);
        printf("Please enter the units consumed by the customer: ");
        getUnit(&unit[i]);
    }
}

void getName(char name[], int size)
{
    int c;
    
    // Peak at the first character in the stdin
    c = getchar();
    if (c != EOF && c != '\n')
    {
        ungetc(c, stdin); // Put it back if it's not a leftover newline
    }
    // if c == '\n', it was leftover -> skip it
    else if (c == '\n')
    {
        // do nothing, newline consumed
    }
    
    while(1)
    {
        if (fgets(name, size, stdin) == NULL)
        {
            printf("Error: Could not read input\n");
            continue;
        }
        
        name[strcspn(name, "\n")] = '\0';
        
        break;
    }
}

void getUnit(int* unit)
{
    while(1)
    {
        if (scanf("%d", unit) != 1)
        {
            printf("Error: Value could not be read as an intger\n");
            printf("Please try again.......................\n");
            while(getchar() != '\n' && !feof(stdin));
            continue;
        }
        else if (*unit <= 0)
        {
            printf("Error: Invalid input. Please enter a positive and non-zero value\n");
            continue;
        }
        else
        {
            while(getchar() != '\n' && !feof(stdin));
            break;
        }
    }
}

void calculateBill(char name[][MAX_NAME_LENGTH], int unit[], int customerCount)
{
    for(int i = 0; i < customerCount; i++)
    {
        double cost = MIN_CHARGE;

        if (unit[i] > 0 && unit[i] <= 200)
        {
            cost = MIN_CHARGE + (0.8 * unit[i]);
        }
        else if (unit[i] > 200 && unit[i] <= 300)
        {
            cost = MIN_CHARGE +  (0.8 * 200) + (0.9 * (unit[i] - 200));
        }
        else if (unit[i] > 300)
        {
            cost = MIN_CHARGE + (0.8 * 200) + (0.9 * 100) + (1 * (unit[i] - 300));

        }
        
        if (cost > 400)
        {
            cost += (cost * 0.15);
        }

        printf("\n-----------------------------------\n");
        printf("Name           : %s\n", name[i]);
        printf("Units consumed : %d\n", unit[i]);
        printf("Bill           : %.4lf Rupees\n", cost);
        printf("-----------------------------------\n");
    }
}