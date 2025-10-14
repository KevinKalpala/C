/**
* Program written by Kevin Kalpala
* Date : 14/10/25
*
* Program to read three integers from the keyboard using one scanf statement and output them on one line using
* (a) three printf statements
* (b) only one printf statement with conversion specifiers
* (c) only one printf statement without conversion specifiers
*/

#include<stdio.h>
#include<ctype.h>

void getData(int* n1, int* n2, int* n3);

int main()
{
    int num1, num2, num3;

    // Get the data from the user
    getData(&num1, &num2, &num3);

    // (a) three printf statements
    printf("%d ", num1);
    printf("%d ", num2);
    printf("%d", num3);

    printf("\n\n");

    // (b) only one printf with conversion specifiers
    printf("%d %d %d", num1, num2, num3);

    // (c) only one printf without conversion specifiers
    char combined[100];
    sprintf(combined, "%d %d %d", num1, num2, num3);
    printf(combined);  // No format specifier used in printf
    // The above line might not work but this is the logic that was used by the writer

    return 0;
}

void getData(int* n1, int* n2, int* n3)
{
    while(1)
    {
        printf("Please enter three integer values: ");
        if(scanf("%d %d %d", n1, n2, n3) != 3)
        {
            printf("Error: An unexpected error just occurred\n");
            printf("Please try again..................\n");
            while(getchar() != '\n');
            continue;
        }else{
            break;
        }
    }
}