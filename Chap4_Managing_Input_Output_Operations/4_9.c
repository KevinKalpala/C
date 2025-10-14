/**
* Program written by Kevin Kalpala
* Date : 14/10/25
*
* Program to read the name ANIL KUMAR GUPTA in three parts using the scanf statement and to display the same in the following format using the printf statement.
* (a) ANIL K. GUPTA
* (b) A.K. GUPTA
* (c) GUPTA A.K.
*/

#include<stdio.h>

void getFullName(char fName[], char mName[], char lName[]);

int main()
{
    char firstName[30], middleName[30], lastName[30];
    
    printf("\n****** Welcome User! ******\n");

    // Get the data from the user
    getFullName(firstName, middleName, lastName);

    // (a) ANIL K. GUPTA
    printf("(a) %s %1.1s. %s\n", firstName, middleName, lastName);

    // (b) A.K. GUPTA
    printf("(b) %1.1s.%1.1s. %s\n", firstName, middleName, lastName);

    // (c) GUPTA A.K.
    printf("(c) %s %1.1s.%1.1s\n", lastName, middleName, firstName);
    
    return 0;
}

void getFullName(char fName[], char mName[], char lName[])
{
    while(1)
    {
        printf("Please enter the full name: ");
        if(scanf("%s %s %s", fName, mName, lName) != 3)
        {
            printf("Error: An unexpected error just occurred\n");
            printf("Please try again.............\n");
            while(getchar() != '\n');
            continue;
        }
        else{
            break;
        }
    }
}