/**
 * -------------------------------------------------------------------------------------------
 * Program written by : Kevin Kalpala
 * Date               : 25 / 02 / 26
 * 
 * Description:
 * '
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
#include<string.h>

#define NAMESIZE 21

int getIntData(char* prompt);

int main()
{
    int size;
    int found = 0;
    
    size = getIntData("Please enter the class size : ");

    int rollNo[size], choice;
    char names[size][NAMESIZE];
    char searchName[NAMESIZE];
    int searchRollNo;

    printf("Please enter the following details for the students:-\n");
    for(int i = 0; i < size; i++)
    {
        rollNo[i] = getIntData("Roll Number : ");

        printf("Name : ");
        fgets(names[i], NAMESIZE, stdin);
        names[i][strcspn(names[i], "\n")] = '\0';
    }

    choice = getIntData("Please enter the choice\n1. For searching by names\t2. For searching by roll number\n");

    while(choice != 1 && choice != 2)
    {
        choice = getIntData("Please enter the choice\n1. For searching by names\t2. For searching by roll number\n");
    }

    switch (choice)
    {
        case 1:
            found = 0;
            printf("Please enter the search name : ");
            fgets(searchName, NAMESIZE, stdin);
            searchName[strcspn(searchName, "\n")] = '\0';

            printf("Roll No\tName\n");
            for(int i = 0; i < size; i++)
            {
                if(strcmp(names[i], searchName) == 0)
                {
                    found++;
                    printf("%d\t%s\n", rollNo[i], names[i]);
                    break;
                }
            }
            
            if(!found)
            {
                printf("Record not found\n");
            }
            break;
            
        case 2:
            found = 0;
            searchRollNo = getIntData("Please enter the search roll number : ");

            for(int i = 0; i < size; i++)
            {
                if(rollNo[i] == searchRollNo)
                {
                    printf("%d\t%s\n", rollNo[i], names[i]);
                    found++;
                    break;
                }
            }
            
            if(!found)
            {
                printf("Record not found\n");
            }
            break;

        default:
            break;
    }


    return 0;
}

int getIntData(char* prompt)
{
    int data;

    while(1)
    {
        if(scanf("%d", &data) != 1)
        {
            printf("Error: Value could not be read as an integer\n");
            printf("Please try again...................\n");
            while(getchar() != '\n' && !feof(stdin));
            continue;
        }
        else if(data <= 0)
        {
            printf("Error: Invalid input. Please enter a value > 0\n");
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