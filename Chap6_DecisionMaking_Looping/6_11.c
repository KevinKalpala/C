/**
 * -------------------------------------------------------------------------------------------------------------------------------------
 * Program written by : Kevin Kalpala
 * Date               : 10 / 12 / 25
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
 * -------------------------------------------------------------------------------------------------------------------------------------
 */

#include<stdio.h>

int getNumber();

int main()
{
    int number, i = 0;
    int binary[30];
    
    printf("\n****** Welcome User! ******\n");
    printf("Please enter a positive integer : ");
    number = getNumber();
    
    int temp = number;
    do
    {
        binary[i++] = temp % 2;
        temp /= 2;

    }while(temp > 0);

    printf("Binary equivalent : ");
    for(i = i - 1; i >= 0; i--)
    {
        printf("%d ", binary[i]);
    }
    
    printf("\n");
    
    return 0;
}

int getNumber()
{
    int data;

    while(1)
    {
        if (scanf("%d", &data) != 1)
        {
            printf("Error: Value could not be read as an integer\n");
            printf("Please try again..................\n");
            while(getchar() != '\n' && !feof(stdin));
            continue;
        }
        else if (data <= 0)
        {
            printf("Error: Invalid input. Please enter a positive integer\n");
            while(getchar() != '\n' && !feof(stdin));
            continue;
        }
        else
        {
            return data;
        }
    }
}