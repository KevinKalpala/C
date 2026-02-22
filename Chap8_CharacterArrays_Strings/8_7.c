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
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAXSIZE 4

int getIntData(char* prompt);

int getMonth(char* prompt);

int main()
{
    char vehicleType[MAXSIZE][21];
    char monthOfSales[MAXSIZE][6];
    char searchVehicleType[21];
    int price[MAXSIZE], startingMonth, endingMonth;
    
    for(int i = 0; i < MAXSIZE; i++)
    {
        printf("Please enter the vehicle type : ");
        fgets(vehicleType[i], 20, stdin);
        vehicleType[i][strcspn(vehicleType[i], "\n")] = '\0';
        
        
        printf("Please enter of month of sales : ");
        fgets(monthOfSales[i], 6, stdin);
        monthOfSales[i][strcspn(monthOfSales[i], "\n")] = '\0';
        
        price[i] = getIntData("Please enter the selling price : ");
    }
    
    startingMonth = getMonth("Please enter the starting month : ");
    endingMonth = getMonth("Please enter the ending month : ");
    
    if(startingMonth > endingMonth)
    {
        int temp = startingMonth;
        startingMonth = endingMonth;
        endingMonth = temp;
    }
    
    printf("Please enter the search vehicle type : ");
    fgets(searchVehicleType, 21, stdin);
    searchVehicleType[strcspn(searchVehicleType, "\n")] = '\0';
    
    printf("From %d to %d months:-\n", startingMonth, endingMonth);
    printf("Vehicle type\tMonth of sales\tPrice\n");
    
    for(int i = 0; i < MAXSIZE; i++)
    {
        int m1, m2;
        if(sscanf(monthOfSales[i], "%d/%d", &m1, &m2) == 2)
        {
            if(m2 >= startingMonth && m2 <= endingMonth && strcmp(vehicleType[i], searchVehicleType) == 0)
            {
                printf("%s\t%s\t%d\n", vehicleType[i], monthOfSales[i], price[i]);
            }
        }
    }
    
    printf("\n");
    
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
            while(getchar() != '\n' && !feof(stdin));
            return data;
        }
    }
}

int getMonth(char* prompt)
{
    int month;
    
    while(1)
    {
        printf("%s", prompt);
        
        if(scanf("%d", &month) != 1)
        {
            printf("Error: Value could not be read as an integer.\n");
            printf("Please try again...............\n");
            while(getchar() != '\n' && !feof(stdin));
            continue;
        }
        else if(month < 1 || month > 12)
        {
            printf("Error: Invalid input. Please enter a value between 1 and 12 (both inclusive)\n");
            while(getchar() != '\n' && !feof(stdin));
            continue;
        }
        else
        {
            while(getchar() != '\n' && !feof(stdin));
            return month;
        }
    }
}