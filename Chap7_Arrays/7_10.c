/**
 * ------------------------------------------------------------------------------------------------------------------------
 * Program Name       : Binary Search Using Selection Sort
 * Program Description:
 * 
 * This program accepts an array of integers from the user, sorts the array using
 * the Selection Sort algorithm, and then searches for a given value using the
 * Binary Search technique.
 * 
 * The program ensures proper input validation for array size, array elements,
 * and the search value.
 * 
 * Selection Sort Logic:
 * - Repeatedly selects the largest element from the unsorted portion of the array
 * - Places it at the correct position from the end
 * - Continues until the array is fully sorted in ascending order
 * 
 * Binary Search Logic:
 * - Works on the sorted array
 * - Repeatedly divides the search range into halves
 * - Compares the middle element with the search value
 * - Stops when the value is found or when the search range becomes empty
 * 
 * Input:
 * - Size of the array (integer ≥ 1)
 * - Array elements (integers)
 * - Value to be searched (integer)
 * 
 * Output:
 * - Displays whether the given value is found in the array
 * - If found, prints the index position of the value
 * - If not found, prints an appropriate message
 * 
 * Note:
 * - The program uses iterative binary search
 * - Proper error handling is implemented for invalid inputs
 * - Array indexing starts from 0
 * ------------------------------------------------------------------------------------------------------------------------
 */

#include<stdio.h>

int getArrSize(char* prompt);

void getArr(char* prompt, int arr[], int size);

void sort(int arr[], int size);

int getValue(char* prompt);

void binarySearch(int val, int arr[], int size);

int main()
{
    int arrSize, value;
    
    printf("\n****** Welcome User! ******\n\n");
    
    arrSize = getArrSize("Please enter the size of the array : ");
    
    int array[arrSize];
    
    getArr("Please enter the given array element :-\n", array, arrSize);
    
    sort(array, arrSize);
    
    value = getValue("Please enter the value to search : ");
    
    binarySearch(value, array, arrSize);
    
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
            printf("Please try again..............\n");
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

void getArr(char* prompt, int arr[], int size)
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
                printf("Please try again......\n");
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

void sort(int arr[], int size)
{
    // Note this uses selection sort algorithm
    int temp, highest, maxIndex;
    
    for(int i = (size - 1); i > 0; i--)
    {
        highest = arr[0];
        maxIndex = 0;
        
        for(int j = 1; j <= i; j++)
        {
            if (arr[j] > highest)
            {
                highest = arr[j];
                maxIndex = j;
            }
        }
        
        temp = arr[i];
        arr[i] = highest;
        arr[maxIndex] = temp;
    }
}

int getValue(char* prompt)
{
    int data;
    
    while(1)
    {
        printf("%s", prompt);
        if (scanf("%d", &data) != 1)
        {
            printf("Error: Value could not be read as an integer\n");
            printf("Please try again........\n");
            while(getchar() != '\n' && !feof(stdin));
            continue;
        }
        else
        {
            return data;
        }
    }
}

void binarySearch(int val, int arr[], int size)
{
    int lowerIndex = 0, upperIndex = (size - 1);
    int mid;
    

    while(lowerIndex <= upperIndex)
    {
        mid = (lowerIndex + upperIndex) / 2;

        if(arr[mid] == val)
        {
            printf("The given value %d is found in array at index %d\n", val, mid);
            return;
        }
        else if(val > arr[mid])
        {
            lowerIndex = mid + 1;
        }
        else
        {
            upperIndex = mid - 1;
        }
    }

    printf("The value %d could not be found in the given array\n", val);
}