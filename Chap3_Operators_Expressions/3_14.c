/**
* Program written by Kevin Kalpala
* Date 30/09/25
*
* Program to read two integers m and n and to decide whether m is a multiple of n.
*/

#include<stdio.h>

int getValidInput(const char* prompt, int minValue);

int getYesOrNo(const char* prompt, int yesValue, int noValue);

void isMultiple(int x, int y);

int main()
{
    int repeat = 0;

    do{
        int m, n;

        printf("\n****** Welcome user! ******\n");
        m = getValidInput("Please enter the first number: ", 0);
        n = getValidInput("Please enter the second number: ", 1);

        isMultiple(m, n);

        repeat = getYesOrNo("Do you want to check for another number?", 1, 0);

    }while(repeat);

    printf("\nThank you for using the program. Goodbye!\n");

    return 0;
}

void isMultiple(int x, int y)
{
    if(x % y == 0)
    {
        printf("Yes, %d is a multiple of %d\n", x, y);
    }else{
        printf("No, %d is not a multiple of %d\n", x, y);
    }
}

int getValidInput(const char* prompt, int minValue)
{
    int num;
    while(1){
        printf("%s", prompt);
        if(scanf("%d", &num) != 1 || num < minValue)
        {
            printf("Error: Invalid input\n");
            printf("Please try again..........\n");
            while(getchar() != '\n');
        }else{
            return num;
        }
    }
}

int getYesOrNo(const char* prompt, int yesValue, int noValue)
{
    int num;
    while(1){
        printf("\n%s\n", prompt);
        if(scanf("%d", &num) != 1)
        {
            printf("Error: An unexpected error just occurred.\n");
            printf("Please try again.........\n");
            while(getchar() != '\n');
            continue;
        }else if(!(num == yesValue || num == noValue))
        {
            printf("Error: Please enter a valid input value.\n");
            while(getchar() != '\n');
            continue;
        }
        else{
            return num;
        }
    }
}