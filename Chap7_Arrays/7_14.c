/**
 * ----------------------------------------------------------------------------------------------------------------------------------
 * Program written by : Kevin Kalpala
 * Date               : 06 / 01 / 26
 * 
 * Description:
 *      This program reads an International Standard Book Number (ISBN-10)
 *      in the form XXXX-XXX-XXXX-X (with or without hyphens).
 *      The program extracts only the numeric digits from the input and
 *      stores them into an integer array.
 * 
 *      It then validates the ISBN using the official checksum formula:
 *          Sum = (1 × digit1) + (2 × digit2) + ... + (9 × digit9)
 *          Check digit = Sum % 11
 *      If the calculated check digit matches the last digit entered,
 *      the ISBN is declared valid; otherwise, it is invalid.
 * 
 * Input:
 *      A single ISBN number containing digits and separators such as:
 *          Example: 0-07-041183-2
 *      Only digits are extracted; any other character is ignored.
 * 
 * Output:
 *      Displays whether:
 *          • "The ISBN is valid"  → if checksum matches
 *          • "The ISBN is not valid" → if checksum fails
 *          • "Invalid ISBN format" → if fewer or more than 10 digits entered
 * 
 * Note:
 *      - The ISBN must contain exactly 10 numeric digits.
 *      - Hyphens do not affect validation.
 *      - This program does not support 'X' as check digit (sometimes used in ISBN-10).
 * ----------------------------------------------------------------------------------------------------------------------------------
 */

#include<stdio.h>

void getISBN(char* prompt, int size, int number[size]);

void checkISBN(int size, int number[size]);

int main()
{
    int isbn[10];
    
    printf("\n****** Welcome User! ******\n\n");
    
    getISBN("Please enter the ISBN for the customer (eg :- 0-07-041183-2):-\n", 10, isbn);
    
    checkISBN(10, isbn);
    
    return 0;
}

void getISBN(char* prompt, int size, int number[size])
{
    char ch;
    int arrIndex = 0;
    
    printf("%s", prompt);
    
    while(arrIndex < size && (ch = getchar()) != '\n' && ch != EOF)
    {
        if (ch >= '0' && ch <= '9')
        {
            number[arrIndex++] = ch - '0';
        }
    }

    if(arrIndex != 10) {
        printf("Invalid ISBN format\n");
        return;
    }
}

void checkISBN(int size, int number[size])
{
    int sum = 0;
    for(int i = 0; i < size - 1; i++)
    {
        sum += ((i + 1) * number[i]);
    }

    if (sum % 11 == number[9]) printf("The ISBN is valid\n");
    else printf("The ISBN is not valid\n");
}