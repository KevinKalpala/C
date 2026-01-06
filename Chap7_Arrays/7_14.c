/**
 * ----------------------------------------------------------------------------------------------------------------------------------
 * Program written by : Kevin Kalpala
 * Date               : 06 / 01 / 26
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
 * ----------------------------------------------------------------------------------------------------------------------------------
 */

#include<stdio.h>

void getISBN(char* prompt, char no[], int size);

void checkISBN(char no[], int size);

int main()
{
    char isbn[14];
    
    printf("\n****** Welcome User! ******\n\n");
    
    getISBN("Please enter the ISBN for the customer :-\n", isbn, 14);
    
    checkISBN(isbn, 14);
    
    return 0;
}

void getISBN(char* prompt, char no[], int size)
{
    printf("%s", prompt);
    for(int i = 0; i < size; i++)
    {
        while(1)
        {
            if (i == 1 || i == 4 || i == 11) no[i] = '-';
            else if (i == 13) no[i] = '\0';
            else
            {
                scanf(" %c", &no[i]);

                if (no[i] < '0' || no[i] > '9')
                {
                    printf("Error: Value could not be read as a character\n");
                    printf("Please try again..........\n");
                    while(getchar() != '\n' && !feof(stdin));
                    continue;
                }
                else
                {
                    break;
                }
            }
        }
    }
}

void checkISBN(char no[], int size)
{
    int sum = 0;
    for(int i = 0; i < (size - 2); i++)
    {
        if (no[i] == '-')
        {
            // do nothing;
        }
        else
        {
            sum += ((i+1) * (no[i] - '0'));
        }
    }

    if (sum % 11 == (no[12] - '0')) printf("The given ISBN is valid\n");
    else printf("The given ISBN is invalid\n");
}