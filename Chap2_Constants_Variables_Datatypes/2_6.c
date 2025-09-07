/**
* Program written by Kevin Kalpala
* Date : 06/09/25
*
* Program to count and print the number of positive and negative numbers in a given set of numbers until 0 is encountered.
*/

#include<stdio.h>

int checkNumber(int num);

int main()
{
    int pos = 0, neg = 0; // To count the frequency of positive and negative numbers respectively
    int number; // To store the number entered by the user

    while(1)
    {
        int result;

        printf("Enter the number:\n");
        scanf("%d", &number);

        if(number == 0)
        {
            printf("Zero is encountered.....\n");
            printf("Positive numbers = %d\n", pos);
            printf("Negative numbers = %d\n", neg);
            printf("Terminating the reading.....\n");
            printf("Thank you for using the program.\n");
            return 0;
        }

        result = checkNumber(number);
        if(result == 1)
            pos++;
        else
            neg++;
    }

    return 0;
}

int checkNumber(int num)
{
    if(num > 0)
        return 1;
    else
        return -1;
}