/**
 * -----------------------------------------------------------------------------------------------------------------------------------
 * Program written by : Kevin Kalpala
 * Date               : 05 / 12 / 25
 * 
 * Description:
 * This program accepts a non-negative integer from the user and prints a table of factorials from 0 up to the entered value.
 * The factorial for each number is calculated using a function and displayed in a formatted table style.
 * 
 * Input:
 * A single non-negative integer (m) entered by the user.
 * 
 * Output:
 * A table displaying the factorial values from 0! to m!.
 * 
 * Note:
 * - The program validates user input and only accepts integer values >= 0.
 * - Factorials are stored using the 'long int' data type, but very large values may still overflow.
 * -----------------------------------------------------------------------------------------------------------------------------------
 */

#include<stdio.h>

int getIntData();

long int getFactorial(int n);

int main()
{
    int m;
    
    printf("\n****** Welcome User! ******\n");
    
    printf("Please enter a number : ");
    m = getIntData();
    

    printf("Printing factorials............................\n");
    
    for(int i = 0; i <= m; i++)
    {
        long int fact = 0;
        fact = getFactorial(i);

        printf("%d! = %ld\n", i, fact);
    }
    
    
    return 0;
}

int getIntData()
{
    int data;
    
    while(1)
    {
        if (scanf("%d", &data) != 1)
        {
            printf("Error: Value could not be read as an integer.\n");
            printf("Please try again.............\n");
            while(getchar() != '\n' && !feof(stdin));
            continue;
        }
        else if (data < 0)
        {
            printf("Error: Invalid input. Please enter a value >= 0\n");
            while(getchar() != '\n' && !feof(stdin));
            continue;
        }
        else
        {
            return data;
        }
    }
}

long int getFactorial(int n)
{
    long int data = 1;

    if (n == 0 || n == 1)
    {
        ;
    }
    else
    {
        for (int i = 2  ; i <= n; i++)
        {
            data *= i;
        }
    }

    return data;
}