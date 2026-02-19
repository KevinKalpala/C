/**
 * ------------------------------------------------------------------------------------
 * Program written by : Kevin Kalpala
 * Date               : 19 / 02 / 26
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
 * ------------------------------------------------------------------------------------
 */

#include<stdio.h>
#include<ctype.h>
#include<string.h>

void swap(char* x, char* y);
void quickSort(char s[], int length);
void quickSortRecursion(char s[], int low, int high);
int partition(char s[], int low, int high);

int main()
{
    char str[100];

    printf("Please enter a string : ");
    fgets(str, 100, stdin);
    str[strcspn(str, "\n")] = '\0';

    int strLen = strnlen(str, 100);

    quickSort(str, strLen);

    printf("Sorted String : ");
    for(int i = 0; i < strLen; i++)
    {
        printf("%c", str[i]);
    }

    printf("\n");

    return 0;
}

void swap(char* x, char* y)
{
    char temp = *x;
    *x = *y;
    *y = temp;
}

void quickSort(char s[], int length)
{
    quickSortRecursion(s, 0, length - 1);
}

void quickSortRecursion(char s[], int low, int high)
{
    if(low < high)
    {
        int pivotPos = partition(s, low, high);
        quickSortRecursion(s, low, pivotPos - 1);
        quickSortRecursion(s, pivotPos + 1, high);
    }
}

int partition(char s[], int low, int high)
{
    int i = low;
    char pivot = s[high];

    for(int j = low; j < high; j++)
    {
        if(tolower(s[j]) <= tolower(pivot))
        {
            swap(&s[i], &s[j]);
            i++;
        }
    }

    swap(&s[i], &s[high]);

    return i;
}