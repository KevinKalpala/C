/**
 * ------------------------------------------------------------------------------------------------------------------------
 * Program written by : Kevin Kalpala
 * Date               : 29 / 12 / 25
 * 
 * Description:
 * This program performs matrix multiplication (dot product) of two square matrices.
 * The user inputs the size N of the matrices, followed by the elements of two N x N
 * matrices, A and B. The program calculates C = A dot B and prints all matrices
 * in a readable format.
 * 
 * Input:
 * - Size of the square matrices (N)
 * - Elements of matrix A
 * - Elements of matrix B
 * 
 * Output:
 * - The resulting matrix C = A dot B
 * 
 * Note:
 * - Uses variable-length arrays (C99 feature) to handle user-defined matrix size.
 * - Includes input validation to ensure correct integer input.
 * - Properly formats matrices for clarity.
 * ------------------------------------------------------------------------------------------------------------------------
 */

#include <stdio.h>

// Function prototypes
int getN(char* prompt);
void getArray(char c, int size, int arr[][size]);
void calculateAdotB(int size, int arr1[][size], int arr2[][size], int arr3[][size]);
void printMatrix(char c, int size, int arr[][size]);

int main()
{
    printf("\n****** Welcome User! ******\n\n");

    // Get matrix size from user
    int n = getN("Please enter the value of N (size of square matrices): ");

    // Declare variable-length arrays
    int a[n][n], b[n][n], c[n][n];

    // Initialize matrix C to zero
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            c[i][j] = 0;

    // Get matrices A and B from user
    getArray('A', n, a);
    getArray('B', n, b);

    // Print input matrices
    printMatrix('A', n, a);
    printMatrix('B', n, b);

    // Calculate C = A dot B
    calculateAdotB(n, a, b, c);

    // Print resulting matrix
    printMatrix('C', n, c);

    return 0;
}

// Function to get a positive integer from the user
int getN(char* prompt)
{
    int data = 0;

    while(1)
    {
        printf("%s", prompt);
        if(scanf("%d", &data) != 1)
        {
            printf("Error: Value could not be read as an integer.\nPlease try again.\n");
            while(getchar() != '\n' && !feof(stdin));
            continue;
        }
        else if(data <= 0)
        {
            printf("Error: Invalid input. Please enter a value >= 1.\n");
            while(getchar() != '\n' && !feof(stdin));
            continue;
        }
        else
        {
            return data;
        }
    }
}

// Function to get matrix elements from user
void getArray(char c, int size, int arr[][size])
{
    printf("\nEnter elements for Matrix %c:\n", c);
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            while(1)
            {
                printf("%c[%d][%d] = ", c, i+1, j+1);
                if(scanf("%d", &arr[i][j]) != 1)
                {
                    printf("Error: Value could not be read as an integer.\nPlease try again.\n");
                    while(getchar() != '\n' && !feof(stdin));
                    continue;
                }
                else
                {
                    break; // valid input
                }
            }
        }
    }
}

// Function to calculate matrix multiplication
void calculateAdotB(int size, int arr1[][size], int arr2[][size], int arr3[][size])
{
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            for(int k = 0; k < size; k++)
            {
                arr3[i][j] += arr1[i][k] * arr2[k][j];
            }
        }
    }
}

// Function to print a matrix
void printMatrix(char c, int size, int arr[][size])
{
    printf("\nMatrix %c:\n", c);
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            printf("%d\t", arr[i][j]);
        }
        printf("\n");
    }
}
