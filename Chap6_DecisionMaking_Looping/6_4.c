/**
 * --------------------------------------------------------------------------------------------------------
 * Program written by : Kevin Kalpala
 * Date               : 07 / 12 / 25
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
 * --------------------------------------------------------------------------------------------------------
 */

#include<stdio.h>

int getIntData();

void printSeries(int n);

int main()
{
    int terms;
    
    printf("\n****** Welcome User! ******\n");
    printf("This program prints the fibonacci series till m terms\n\n");
    
    printf("Please enter the value of m : ");
    terms = getIntData();
    
    printSeries(terms);
    
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
            printf("Please try again.........................\n");
            while(getchar() != '\n' && !feof(stdin));
            continue;
        }
        else if (data <= 0)
        {
            printf("Error: Invalid input. Please enter a value positive and non-zero value\n");
            while(getchar() != '\n' && !feof(stdin));
            continue;
        }
        else
        {
            return data;
        }
    }
}

void printSeries(int n)
{
    int lastTerm = 1, secondLastTerm = 0;
    int term;
    int i = 2;

    printf("Fibonacci series : %d %d ", secondLastTerm, lastTerm);

    do
    {
        term = lastTerm + secondLastTerm;
        secondLastTerm = lastTerm;
        lastTerm = term;

        printf("%d ", term);

        i++;

    }while(i < n);

    printf("\n");
}