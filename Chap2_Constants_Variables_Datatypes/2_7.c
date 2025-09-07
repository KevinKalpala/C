/**
* Program written by Kevin Kalpala
* Date : 07/09/25
*
* Program to do the following tasks
* 1. Declare x and y as integer variables and z as a short integer variable
* 2. Assign two 6 digit numbers to x and y
* 3. Assign the sum of x and y to z
* 4. Output the values of x,y and z
* Also comment on the output
*/

#include<stdio.h>
#include<limits.h> // C library for checking limits of datatypes

int main()
{
    int x, y;
    short int z;

    x = 111111;
    y = 222222;
    z = x + y;

    printf("x = %d, y = %d and z = %d\n", x, y, z);
    
    printf("****** COMMENTS ******\n");
    printf("Overflow case\n");
    printf("Actual sum of x and y = %d\n", x + y);
    printf("But since z is a short int, it overflows and stores: %d\n", z);
    
    printf("Short int:\n");
    printf("  Minimum value: %d\n", SHRT_MIN);
    printf("  Maximum value: %d\n", SHRT_MAX);

    printf("Int:\n");
    printf("  Minimum value: %d\n", INT_MIN);
    printf("  Maximum value: %d\n", INT_MAX);

    printf("Long int:\n");
    printf("  Minimum value: %ld\n", LONG_MIN);
    printf("  Maximum value: %ld\n", LONG_MAX);

    printf("Long long int:\n");
    printf("  Minimum value: %lld\n", LLONG_MIN);
    printf("  Maximum value: %lld\n", LLONG_MAX);

    return 0;
}