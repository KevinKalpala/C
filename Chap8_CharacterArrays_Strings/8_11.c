/**
 * --------------------------------------------------------------------------------------------------------
 * Program written by : Kevin Kalpala
 * Date               : 25 / 02 / 26
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
 * --------------------------------------------------------------------------------------------------------
 */

#include<stdio.h>
#include<string.h>

#define SIZE 50

int main()
{
    char str1[SIZE], str2[SIZE];

    printf("Please enter string one : ");
    fgets(str1, SIZE, stdin);
    str1[strcspn(str1, "\n")] = '\0';

    printf("Please enter string two : ");
    fgets(str2, SIZE, stdin);
    str2[strcspn(str2, "\n")] = '\0';

    int cmp = strncmp(str1, str2, SIZE);

    if(cmp == 0)
    {
        printf("String 1 and String 2 are equal\n");
    }
    else if(cmp < 0)
    {
        printf("String 1 is less than String 2\n");
    }
    else
    {
        printf("String 1 is greater than String 2\n");
    }

    return 0;
}