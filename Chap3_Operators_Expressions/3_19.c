/**
* Program written by Kevin Kalpala
* Date 30/09/25
*
* Program to determine whether a given integer is odd or displays the number and description on the same line.
*/

#include<stdio.h>

int getValidInput(const char* prompt);

int getYesOrNo(const char* prompt, int yesValue, int noValue);

int main()
{
    int repeat;

    while(1){
        int num, x;
        printf("\n****** Welcome User! ******\n");

        num = getValidInput("Please enter a number: ");
        x = num % 2;

        if(num == 0){
            printf("The given number is %d\n", num);
            printf("It is neither odd nor even.\n");
        }else if(x == 0){
            printf("The given number %d is even because %d / %d leaves a remainder of %d\n", num, num, 2, x);
        }else{
            printf("The given number %d is odd because %d / %d leaves a remainder of %d\n", num, num, 2, x);
        }

        repeat = getYesOrNo("Do you want to re-run the program for a different number?", 1, 0);

        if(repeat == 0){
            printf("\nThank you for using the program\n");
            return 0;
        }
    }
}

int getValidInput(const char* prompt)
{
    int value;
    while(1)
    {
        printf("\n%s", prompt);
        if(scanf("%d", &value) != 1)
        {
            printf("Error: An unexpected error just occurred\n");
            printf("Please try again.................\n");
            while(getchar() != '\n');
        }else if(value < 0){
            printf("Error: Please enter a non-negative input value\n");
            while(getchar() != '\n');
        }else{
            return value;
        }
    }
}

int getYesOrNo(const char* prompt, int yesValue, int noValue)
{
    int choice;
    while(1){
        printf("\n%s\n", prompt);
        printf("Press %d for Yes and %d for No\n", yesValue, noValue);
        if(scanf("%d", &choice) != 1)
        {
            printf("Error: An unexpected error just occurred.\n");
            printf("Please try again......................\n");
            while(getchar() != '\n');
        }else if(choice != yesValue && choice != noValue){
            printf("Error: Please enter a valid input\n");
            while(getchar() != '\n');
        }else{
            return choice;
        }
    }
}