/**
* Program written by Kevin Kalpala
* Date 30/09/25
*
* Program to print the size of various data types in c.
*/

#include<stdio.h>

int main()
{
    printf("\n****** Character Datatype ******\n");
    printf("Size of normal character = %zu bytes\n", sizeof(char));

    printf("\n****** Integer Datatype ******\n");
    printf("Size of short Integer = %zu bytes\n", sizeof(short int));
    printf("Size of normal Integer = %zu bytes\n", sizeof(int));
    printf("Size of long Integer = %zu bytes\n", sizeof(long int));

    printf("\n****** Floating point Datatype ******\n");
    printf("Size of normal floating point number = %zu bytes\n", sizeof(float));
    printf("Size of long floating point number / Double precision floating point number = %zu bytes\n", sizeof(double));
    printf("Size of long long floating point number / Long double precision floating point number = %zu bytes\n", sizeof(long double));

    printf("\n****** Void Datatype ******\n");
    printf("Size of void Datatype = Not applicable (incomplete type)\n\n");

    return 0;
}