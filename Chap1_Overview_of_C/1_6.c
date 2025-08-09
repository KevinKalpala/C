
/*
    Program written by Kevin Kalpala
    Date : 09/08/25

    This program prints the table of 5
*/

#include<stdio.h>

const int NUMBER = 5; // Constant for the number whose table is to be printed

// Function to multiply two variables
int multiply(int x, int y);

int main()
{
    // Declare and Initialize a variable to store the counter value
    int counter = 1;

    // Loop to print the table of number from 1 to 10
    while(counter <= 10)
    {
        // Print the table entry: number * counter = result
        printf("%d X %d = %d\n", NUMBER, counter, multiply(NUMBER, counter));

        // Update the counter value
        counter++;
    }

    return 0;
}

int multiply(int x, int y)
{
    return x * y;
}