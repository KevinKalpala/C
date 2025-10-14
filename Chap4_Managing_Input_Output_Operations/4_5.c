/**
* Program written by Kevin Kalpala
* Date : 14/10/25
*
* An interactive program to demonstrate the process of multiplication. 
*/

#include<stdio.h>

void getData(const char* prompt, int* n);

int main()
{
    int num1, num2;
    int num2UnitsDigit, num2TensDigit;

    getData("\n\n\t\t\t", &num1);
    getData("\t\tX\t", &num2);

    num2UnitsDigit = num2 % 10;
    num2TensDigit = num2 / 10;

    printf("\t\t-----------\n");
    
    printf("%d X %2d is              %3d\n", num2UnitsDigit, num1, (num2UnitsDigit * num1));
    printf("%d X %2d is             %3d\n", num2TensDigit, num1, (num2TensDigit * num1));

    printf("\t\t-----------\n");
    
    printf("Add them              %4d\n", num1 * num2);

    printf("\t\t-----------\n");

    return 0;
}

void getData(const char* prompt, int* n)
{
    while(1)
    {
        printf("%s", prompt);
        if(scanf("%d", n) != 1)
        {
            printf("Error: An unexpected error just occured\n");
            printf("Please try again.................\n");
            while(getchar() != '\n');
            continue;
        }else if(*n < 0)
        {
            printf("Error: Please enter a non-negative value\n");
            continue;
        }else if(*n < 10 || *n > 99)
        {
            printf("Error: Please enter a two-digit value\n");
        }
        else{
            break;
        }  
    }
}