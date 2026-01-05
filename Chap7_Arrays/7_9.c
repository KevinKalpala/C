/**
 * ----------------------------------------------------------------------------------------------------------------------------
 * Program written by : Kevin Kalpala
 * Date               : 30 / 12 / 25
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
 * ----------------------------------------------------------------------------------------------------------------------------
 */

#include<stdio.h>

int getArrSize(char* prompt);

void getArray(char* prompt, int arr[], int size);

int main()
{
    int temp, highest, maxIndex;
    int arrSize;
    
    printf("\n****** Welcome User! ******\n\n");
    
    arrSize = getArrSize("Please enter the size of the array : ");
    
    int array[arrSize];
    
    getArray("Please enter the elements :-\n", array, arrSize);
    
    for(int i = arrSize - 1; i > 0; i--)
    {
        highest = array[0];
        maxIndex = 0;
        
        for(int j = 1; j <= i; j++)
        {
            if (array[j] > highest)
            {
                highest = array[j];
                maxIndex = j;
            }
        }
        
        temp = array[i];
        array[i] = highest;
        array[maxIndex] = temp;
    }
    
    printf("Printing the sorted array..................\n");
    for(int i = 0; i < arrSize; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
    
    return 0;
}

int getArrSize(char* prompt)
{
    int data;
    
    while(1)
    {
        printf("%s", prompt);
        if (scanf("%d", &data) != 1)
        {
            printf("Error: Value could not be read as an integer\n");
            printf("Please try again.............\n");
            while(getchar() != '\n' && !feof(stdin));
            continue;
        }
        else if (data <= 0)
        {
            printf("Error: Invalid input. Please enter a value >= 1\n");
            while(getchar() != '\n' && !feof(stdin));
            continue;
        }
        else
        {
            return data;
        }
    }
}

void getArray(char* prompt, int arr[], int size)
{
    int data;

    printf("%s", prompt);

    for(int i = 0; i < size; i++)
    {
        while(1)
        {
            if (scanf("%d", &data) != 1)
            {
                printf("Error: Value could not be read as an integer\n");
                printf("Please try again............\n");
                while(getchar() != '\n' && !feof(stdin));
                continue;
            }
            else
            {
                arr[i] = data;
                break;
            }
        }
    }
}