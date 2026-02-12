/**
 * --------------------------------------------------------------------------------------------------
 * Program written by : Kevin Kalpala
 * Date               : 13 / 02 / 26
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
 * --------------------------------------------------------------------------------------------------
 */

#include<stdio.h>
#include<string.h>

int getIntData(char* prompt, int max);

void extractSubStr(char* src, char* des, int m, int n, int len);

int main()
{
    int m, n, slen;
    char str[50], cpyStr[50];
    
    printf("Please enter your string : ");
    fgets(str, 50, stdin);
    str[strcspn(str, "\n")] = '\0';
    
    slen = strnlen(str, sizeof(str));
    
    m = getIntData("Please enter the number of character to copy : ", slen);
    n = getIntData("Please enter the index to start extraction : ", slen);
    
    extractSubStr(str, cpyStr, m, n, slen);

    printf("The extracted sub-string is : %s\n", cpyStr);
    
    return 0;
}

int getIntData(char* prompt, int max)
{
    int data;
    
    while(1)
    {
        printf("%s", prompt);
        if (scanf("%d", &data) != 1)
        {
            printf("Error: Value could not be read as an integer\n");
            printf("Please try again.......\n");
            while(getchar() != '\n' && !feof(stdin));
            continue;
        }
        else if(data < 0 || data > max)
        {
            printf("Error: Invalid input. Please try again\n");
            while(getchar() != '\n' && !feof(stdin));
        }
        else
        {
            return data;
        }
    }
}

void extractSubStr(char* src, char* des, int m, int n, int len)
{
    if (n < 1 || n > len)
    {
        des[0] = '\0';
        return;
    }

    if (n + m - 1 > len)
        m = len - (n - 1);

    snprintf(des, m+1, "%.*s", m, src+n-1);
}