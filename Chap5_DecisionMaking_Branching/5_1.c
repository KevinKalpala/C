/**
* -------------------------------------------------------------
* Program written by : Kevin Kalpala
* Date               : 05 / 11 / 2025
*
* Description:
*   This program determines whether a given number is even or odd.
*   It demonstrates two approaches:
*     (a) Without using the else statement
*     (b) With using the else statement
*
* Input :
*   A positive integer (including zero)
*
* Output :
*   Displays whether the number is EVEN or ODD
*
* Note :
*   The program uses 'goto' statements intentionally to demonstrate
*   flow control in C programming.
* -------------------------------------------------------------
*/

#include<stdio.h>

void getNumber(int* x);

void checkOddorEven(int number);

int getYesOrNo();

int main()
{
    start:
        int num, repeatProgram = 0;

        printf("\n****** Welcome User! ******\n");
        getNumber(&num);
        
        //Check if number is odd or even
        checkOddorEven(num);

        printf("\nDo you want to re-run this program?\n");
        repeatProgram = getYesOrNo();

        if (repeatProgram == 1)
        {
            goto start;
        }
        else
        {
            printf("\nPress Enter to exit...");
            while(getchar() != '\n');
            getchar();

            printf("Thank you for using the program!\n");
            printf("Hope you have a wondeful day\n");
        }

    return 0;
}

void getNumber(int* x)
{
    inputLoop:
        printf("Please enter a positive number (or zero): ");
        if (scanf("%d", x) != 1)
        {
            printf("Error: An unexpected error just occurred\n");
            printf("Please try again........\n");
            while(getchar() != '\n');
            goto inputLoop;
        }
        if (*x < 0)
        {
            printf("Please enter either zero or a positive integer value for the number\n");
            goto inputLoop;
        }
}

void checkOddorEven(int number)
{
    // (a) without using else option
    printf("\n (a) without using else option\n");
    if (number % 2 == 0)
    {
        printf("NUMBER IS EVEN\n");
    }
    if (number % 2 != 0)
    {
        printf("NUMBER IS ODD\n");
    }

    printf("\n-------------------------------------------\n");

    // (b) with else option
    printf("\n (b) with else option\n");
    if (number % 2 == 0)
    {
        printf("NUMBER IS EVEN\n");
    }
    else
    {
        printf("NUMBER IS ODD\n");
    }
}

int getYesOrNo()
{
    answerLoop:
        int answer = 0;

        printf("(Please press 1 for YES and any other number for NO)\n");
        if (scanf("%d", &answer) != 1)
        {
            printf("Error: An unexpected error just occurred\n");
            printf("Please try again............\n");
            while(getchar() != '\n');
            goto answerLoop;
        }
        else
        {
            return answer;
        }
}