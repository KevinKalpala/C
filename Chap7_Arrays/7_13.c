/**
 * -----------------------------------------------------------------------------------------------------------------------------------
 * Program written by : Kevin Kalpala
 * Date               : 06 / 01 / 26
 * 
 * Description:
 * This program reads a matrix of size m × n from the user and prints its transpose.
 * The transpose of a matrix is obtained by converting rows into columns and
 * columns into rows.
 * 
 * Input:
 * - Two positive integers m and n representing the number of rows and columns.
 * - m × n integer elements of the matrix.
 * 
 * Output:
 * - The transpose of the given matrix (of size n × m) displayed on the screen.
 * 
 * Note:
 * - Input validation is performed to ensure valid positive dimensions and integer values.
 * - The program uses variable length arrays (VLA) and modular functions for clarity.
 * -----------------------------------------------------------------------------------------------------------------------------------
 */

#include<stdio.h>

int getDimension(char* prompt);

void getMatrix(char* prompt, int m, int n, int arr[m][n]);

void printTransposeMatrix(int m, int n, int arr[m][n]);

int main()
{
    int m, n;
    
    printf("\n****** Welcome User! ******\n\n");
    
    m = getDimension("Please enter the value of m : ");
    n = getDimension("Please enter the value of n : ");
    
    int matrix[m][n];
    
    getMatrix("Please enter the details of the matrix :-\n", m, n, matrix);
    
    printTransposeMatrix(m, n, matrix);
    
    return 0;
}

int getDimension(char* prompt)
{
    int data;
    
    while(1)
    {
        printf("%s", prompt);
        if (scanf("%d", &data) != 1)
        {
            printf("Error: Value could not be read as an integer\n");
            printf("Please try again............\n");
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

void getMatrix(char* prompt, int m, int n, int arr[m][n])
{
    printf("%s", prompt);
    
    for(int i = 0; i < m; i++)
    {
        printf("Please enter the %d row below:-\n", (i + 1));
        for(int j = 0; j < n; j++)
        {
            while(1)
            {
                if (scanf("%d", &arr[i][j]) != 1)
                {
                    printf("Error: Value could not be read as an integer.\n");
                    printf("Please try again...........\n");
                    while(getchar() != '\n' && !feof(stdin));
                    continue;
                }
                else
                {
                    break;
                }
            }
        }
        printf("\n");
    }
}

void printTransposeMatrix(int m, int n, int arr[m][n])
{
    printf("Transpose of the given matrix is given below:-\n");
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            printf("%d ", arr[j][i]); // note i and j are swapped to print values([0,0],[0,1],[1,0],[1,1]........[2,1])
        }
        printf("\n");
    }
}