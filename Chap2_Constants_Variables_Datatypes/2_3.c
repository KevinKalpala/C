/**
* Program written by Kevin Kalpala
* Date : 06/09/25
*
* Program to print the even numbers from 1 to 100
*/

#include<stdio.h>

int main()
{
    unsigned int limit = 100; // Print even numbers upto this limit

    for(unsigned int i = 2; i <= limit; i+=2)
    {
        printf("%u\n", i);
    }

    return 0;
}