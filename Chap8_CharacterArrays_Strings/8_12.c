/**
 * -----------------------------------------------------------------------------------------------
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
 * -----------------------------------------------------------------------------------------------
 */

#include<stdio.h>
#include<string.h>

#define SIZE 100

int main()
{
    char text[SIZE];
    char substring[SIZE/2];
    char* ptr = text;
    int count = 0;

    printf("Please enter the text : ");
    fgets(text, SIZE, stdin);
    text[strcspn(text, "\n")] = '\0';

    printf("Please the search text : ");
    fgets(substring, SIZE/2, stdin);
    substring[strcspn(substring, "\n")] = '\0';

    printf("Occurrence found at : ");
    while((ptr = strstr(ptr, substring)) != NULL)
    {
        printf("%ld ", ptr - text);
        count++;
        ptr++;
    }
    printf("\n");

    printf("Total number of occurrences : %d\n", count);

    return 0;
}