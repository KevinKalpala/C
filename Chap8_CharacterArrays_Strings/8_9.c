/**
 * -------------------------------------------------------------------------------------------
 * Program written by : Kevin Kalpala
 * Date               : 24 / 02 / 26
 * 
 * Description:
 * 
 * 
 * Input:
 * 
 * 
 * Output:
 * 
 * 
 * Note:
 * 
 * -------------------------------------------------------------------------------------------
 */

#include<stdio.h>

char* units[] = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
char* teens[] = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
char* tens[] = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};

void getDoubleData(char* prompt, double* x);

void numbersToDigits(int n);

int main()
{
    double amt;
    getDoubleData("Please enter the amount : ", &amt);
    
    int digitBeforePoint, digitAfterPoint;
    
    digitBeforePoint = (int)amt;
    digitAfterPoint = (int)(amt * 100 + 0.5) % 100;
    
    numbersToDigits(digitBeforePoint);
    printf("Rupees and ");
    numbersToDigits(digitAfterPoint);
    printf("Paise\n");
    
    return 0;
}

void getDoubleData(char* prompt, double* x)
{
    while(1)
    {
        printf("%s", prompt);
        if(scanf("%lf", x) != 1)
        {
            printf("Error: Value could not be read as a double\n");
            printf("Please try again.............\n");
            while(getchar() != '\n' && !feof(stdin));
            continue;
        }
        else if(*x <= 0.00)
        {
            printf("Error: Invalid input. Please enter a value > 0.00\n");
            while(getchar() != '\n' && !feof(stdin));
            continue;
        }
        else
        {
            while(getchar() != '\n' && !feof(stdin));
            break;
        }
    }
}

void numbersToDigits(int n)
{
    if(n >= 1000)
    {
        numbersToDigits(n/1000);
        printf(" Thoundsand ");
        n %= 1000;
    }
    if(n >= 100)
    {
        printf("%s Hundred ", units[n/100]);
        n%=100;

        if(n > 0)
        {
            printf("and ");
        }
    }
    if(n >= 20)
    {
        printf("%s ", tens[n/10]);
        n%=10;
    }
    else if(n >= 10)
    {
        printf("%s ", teens[n - 10]);
        return;
    }

    if (n >= 0)
    {
        printf("%s ", units[n]);
    }
}