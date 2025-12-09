/**
 * -----------------------------------------------------------
 * Program written by : Kevin Kalpala
 * Date               : 09 / 12 / 25
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
 * -----------------------------------------------------------
 */

#include<stdio.h>

int getAge();

int main()
{
    int count = 0;
    printf("\n****** Welcome User! ******\n");
    printf("Please enter the age of 100 persons below:-\n ");
    
    for(int i = 0; i < 100; i++)
    {
        int age;
        age = getAge();        
        
        if (age >= 50 && age <= 60)
        {
            count++;
        }
        else
        {
            continue;
        }
    }

    printf("Total number of people in the age group 50 to 60 : %d", count);
    
    return 0;
}

int getAge()
{
    int data;

    while(1)
    {
        if (scanf("%d", &data) != 1)
        {
            printf("Error: Value could not be stored as an integer\n");
            printf("Please try again.................\n");
            while(getchar() != '\n' && !feof(stdin));
            continue;
        }
        else if (data <= 0 || data > 100)
        {
            printf("Error: Invalid input. Please enter a positive and non-zero value\n");
            while(getchar() != '\n' && !feof(stdin));
            continue;
        }
        else
        {
            return data;
        }
    }
}