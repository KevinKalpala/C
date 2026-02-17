/**
 * ------------------------------------------------------------------------------------------
 * Program written by : Kevin Kalpala
 * Date               : 18 / 02 / 26
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

int main()
{
    char str[50], word[50];
    int wordCount = 0;
    printf("Please enter the string : ");
    fgets(str, 50, stdin);
    str[strcspn(str, "\n")] = '\0';

    printf("Please enter the word to search : ");
    fgets(word, 50, stdin);
    word[strcspn(word, "\n")] = '\0';

    char* token = strtok(str, " ,.!?;:");

    while(token !=  NULL)
    {
        if(strcmp(token, word) == 0)
        {
            wordCount++;
        }

        token = strtok(NULL, " ,.!?;:");
    }

    printf("Word Count : %d", wordCount);
    printf("Word entered : %s", word);

    return 0;
}