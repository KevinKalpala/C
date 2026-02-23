/**
 * ---------------------------------------------------------------------------------------------
 * Program written by : Kevin Kalpala
 * Date               : 24 / 02 / 26
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
 * ---------------------------------------------------------------------------------------------
 */

#include<stdio.h>
#include<string.h>
#include<ctype.h>

void checkPalindrome(char t[], int len);

int main()
{
    char text[100];

    printf("Please enter the string : ");
    fgets(text, 100, stdin);
    text[strcspn(text, "\n")] = '\0';
    
    checkPalindrome(text, strlen(text));
    
    return 0;
}

void checkPalindrome(char t[], int len)
{
    int check = 1;
    for(int i = 0; i <= (len - 1) / 2; i++)
    {
        if(tolower(t[i]) != tolower(t[len - 1 - i]))
        {
            check = 0;
            break;
        }
    }

    if(check == 1) printf("The given string is a palindrome\n");
    else printf("The given string is not a palindrome\n");
}