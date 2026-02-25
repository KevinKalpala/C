/**
 * ------------------------------------------------------------------------------------------
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
 * ------------------------------------------------------------------------------------------
 */

#include<stdio.h>
#include<string.h>

#define SIZE 100

int getIntData(char* prompt, int limit);

int main()
{
    char str1[SIZE];
    int m, n;
    
    printf("Please enter the string : ");
    fgets(str1, SIZE, stdin);
    str1[strcspn(str1, "\n")] = '\0';
    char* ptr = str1;

    n = getIntData("Please enter n : ", strlen(str1) - 1);
    m = getIntData("Please enter m : ", strlen(str1) - n);

    char str2[SIZE];
    strncpy(str2, ptr+n, m);
    str2[m] = '\0';

    printf("Copied string : ");
    printf("%s\n", str2);
    
    return 0;
}

int getIntData(char* prompt, int limit)
{
    int data;

    while(1)
    {
        printf("%s", prompt);
        if(scanf("%d", &data) != 1)
        {
            printf("Error: Value could not be read as an integer\n");
            printf("Please try again............\n");
            while(getchar() != '\n' && !feof(stdin));
            continue;
        }
        else if (data < 0 || data > limit)
        {
            printf("Error: Invalid input. Please try again....\n");
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