/**
 * --------------------------------------------------------------------------------------------
 * Program written by : Kevin Kalpala
 * Date               : 20 / 02 / 26
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
 * --------------------------------------------------------------------------------------------
 */

#include<stdio.h>
#include<string.h>
#include<ctype.h>

#define MAXSIZE 4

int getIntData(char* prompt);

int main()
{
    char vehicleType[MAXSIZE][21];
    char monthOfSales[MAXSIZE][5];
    int price[MAXSIZE];
    
    for(int i = 0; i < MAXSIZE; i++)
    {
        printf("Please enter the vehicle type");
        fgets(vehicleType[i], 20, stdin);
        vehicleType[i][strcspn(vehicleType[i], "\n")] = '\0';
        
        printf("Please enter of month of sales : ");
        fgets(monthOfSales[i], 5, stdin);
        monthOfSales[i][strcspn(monthOfSales[i], "\n")] = '\0';
        
        price[i] = getIntData("Please enter the selling price : ");
    }
    
    for(int i = 0; i < 21; i++)
    {
        printf("%s %s %s");
    }
    
    return 0;
}

int getIntData(char* prompt)
{
    int data;

    while(1)
    {
        printf("%s", prompt);
        if(scanf("%d", &data) != 1)
        {
            printf("Error: Value could not be read as an integer\n");
            printf("Please try again...........\n");
            while(getchar() != '\n' && !feof(stdin));
            continue;
        }
        else if(data < 0)
        {
            printf("Error: Invalid input. Please enter a value >= 0\n");
            while(getchar() != '\n' && !feof(stdin));
            continue;
        }
        else
        {
            return data;
        }
    }
}