/**
 * ---------------------------------------------------------------------------------------------------
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
 * ---------------------------------------------------------------------------------------------------
*/

#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main()
{
    char text[200], search[50], replace[50];
    char result[300] = "";

    printf("Please enter a text : ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0';
    
    printf("Please enter the search word : ");
    fgets(search, sizeof(search), stdin);
    search[strcspn(search, "\n")] = '\0';
    
    printf("Please enter the replace word : ");
    fgets(replace, sizeof(replace), stdin);
    replace[strcspn(replace, "\n")] = '\0';

    char* token = strtok(text, " ");

    while(token != NULL)
    {
        if(strcmp(token, search) == 0) strcat(result, replace);
        else strcat(result, token);

        strcat(result, " ");
        token = strtok(NULL, " ");
    }

    printf("\n%s\n", result);

    return 0;
}