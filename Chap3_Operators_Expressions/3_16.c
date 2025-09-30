/**
* Program written by Kevin Kalpala
* Date 30/09/25
*
* Program to read customer codes and calls made and print the bill for each customer.
* Note : cost of one type of mobile service is Rs. 250 plus Rs. 1.25 for each call made over and above 100 calls.
*/

#include<stdio.h>

#define BASE_CHARGE 250.00
#define INCLUDED_CALLS 100
#define SURPLUS_VALUE 1.25
#define MAX_CUSTOMER_SIZE 100

int getMode();

int getCustomerCode(int cus[MAX_CUSTOMER_SIZE]);

int getNoOfCalls();

double getBill(int nOfCalls);

void printBill(int cust[MAX_CUSTOMER_SIZE]);

int getYesOrNo(const char* prompt, int yesValue, int noValue);

int main()
{
    int mode, repeat;
    int customer[MAX_CUSTOMER_SIZE];
    for(int i = 0; i < MAX_CUSTOMER_SIZE; i++)
    {
        customer[i] = -1;
    }

    // Pre-loaded customers: customer[code] = number_of_calls
    customer[0] = 200;
    customer[1] = 150;
    customer[2] = 41;
    customer[3] = 99;
    customer[4] = 100;


    while(1)
    {
        printf("\n****** Welcome User ******\n");

        mode = getMode();

        if(mode == 1)
        {
            int customerCode, calls;
            customerCode = getCustomerCode(customer);
            calls = getNoOfCalls();

            customer[customerCode] = calls;
        }

        if(mode == 2)
        {
            printBill(customer);
        }

        repeat = getYesOrNo("Do you want to re-run this program?", 1, 0);

        if(repeat == 0){
            return 0;
        }
    }
}

// Prompts user to choose program mode: Add customer or Print bills
int getMode()
{
    int m;
    while(1)
    {
        printf("What do you want to do?\n");
        printf("1. Add a new customer\n");
        printf("2. Print the bill for each customer\n");
        if(scanf("%d", &m) != 1)
        {
            printf("Error: An unexpected error just occurred\n");
            printf("Please try again....................\n");
            while(getchar() != '\n');
        }else if(m < 1 || m > 2){
            printf("Error: Please enter a valid input\n");
            while(getchar() != '\n');
        }else{
            return m;
        }
    }
}

int getCustomerCode(int cus[MAX_CUSTOMER_SIZE])
{
    int code;
    while(1)
    {
        printf("Please enter a customer code\n");
        if(scanf("%d", &code) != 1)
        {
            printf("Error: An unexpected error just occurred\n");
            while(getchar() != '\n');
        }else if(code < 0 || code >= MAX_CUSTOMER_SIZE)
        {
            printf("Error: Please enter a valid customer code\n");
            printf("The minimum customer code value can be 0 and the maximum customer code value can be %d\n", MAX_CUSTOMER_SIZE - 1);
            while(getchar() != '\n');
        }else if(cus[code] != -1){
            printf("Customer already exists\n");
            printf("Please try again with another customer code\n");
            while(getchar() != '\n');
        }else{
            return code;
        }
    }
}

int getNoOfCalls()
{
    int calls;
    while(1)
    {
        printf("Please enter the number of calls made by the customer: ");
        if(scanf("%d", &calls) != 1)
        {
            printf("Error: An unexpected error just occurred\n");
            printf("Please try again.................\n");
            while(getchar() != '\n');
        }else if(calls < 0)
        {
            printf("Error: Please enter a valid value for number of calls made\n");
            while(getchar() != '\n');
        }else{
            return calls;
        }
    }
}

double getBill(int nOfCalls)
{
    if(nOfCalls <= 100)
    {
        return BASE_CHARGE;
    }else{
        return BASE_CHARGE + ( nOfCalls - INCLUDED_CALLS ) * SURPLUS_VALUE;
    }
}    

void printBill(int cus[MAX_CUSTOMER_SIZE])
{
    int customerFound = 0;

    printf("\n---------------------------------------------------\n");
    printf("\n%-20s%-20s%-16s\n","Customer ID", "No of calls", "Amount");
    printf("\n---------------------------------------------------\n");

    for(int i = 0; i < MAX_CUSTOMER_SIZE; i++){
        if(cus[i] != -1){
            customerFound += 1;
            double bill;
            bill = getBill(cus[i]);
            printf("%-20d%-20d%-20.2lf\n", i, cus[i], bill);
        }
    }

    if(customerFound == 0)
    {
        printf("\n%-20s%-20s%-20s\n", "", "No Customers Found", "");
    }
}

int getYesOrNo(const char* prompt, int yesValue, int noValue)
{
    int num;
    while(1)
    {
        printf("\n%s\n", prompt);
        printf("Press %d for Yes and %d for No\n", yesValue, noValue);
        if(scanf("%d", &num) != 1)
        {
            printf("Error: An unexpected error just occurred\n");
            printf("Please try again.................\n");
            while(getchar() != '\n');
        }else if(num != yesValue && num != noValue){
            printf("Error: Please enter a valid input value\n");
            while(getchar() != '\n');
        }else{
            return num;
        }
    }
}