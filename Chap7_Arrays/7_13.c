/**
 * -----------------------------------------------------------------------------------------------------------------------------------
 * Program written by : Kevin Kalpala
 * Date               : 06 / 01 / 26
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
 * -----------------------------------------------------------------------------------------------------------------------------------
 */

#include<stdio.h>

int getDimension(char* prompt);

int main()
{
    int m, n;
    
    printf("\n****** Welcome User! ******\n\n");
    
    m = getDimension("Please enter the value of m : ");
    n = getDimension("Please enter the value of n : ");
    
    return 0;
}

int getDimension(char* prompt)
{
    int data;

    while(1)
    {
        printf("%s", prompt);
        if (scanf("%d", &data) != 1)
        {
            printf("Error: Value could not be read as an integer\n");
            printf("Please try again............\n");
            while(getchar() != '\n' && !feof(stdin));
            continue;
        }
        else if (data <= 0)
        {
            printf("Error: Invalid input. Please enter a value >= 1\n");
            while(getchar() != '\n' && !feof(stdin));
            continue;
        }
        else
        {
            return data;
        }
    }
}