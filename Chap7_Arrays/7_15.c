/**
 * --------------------------------------------------------------------------------------------------------------------------------------
 * Program written by : Kevin Kalpala
 * Date               : 07 / 01 / 26
 * 
 * Description:
 * This program reads two matrices A and B from the user and calculates:
 *   (a) A + B → Matrix addition
 *   (b) A - B → Matrix subtraction
 * The results of both operations are displayed on the screen.
 * 
 * Input:
 * - Number of rows and columns (must be positive integers)
 * - Elements of Matrix A (row-wise input)
 * - Elements of Matrix B (row-wise input)
 * 
 * Output:
 * - Matrix A + Matrix B (element-wise sum)
 * - Matrix A - Matrix B (element-wise difference)
 * 
 * Note:
 * - Both matrices must have the same dimensions for addition and subtraction.
 * - Program validates input and rejects invalid entries.
 * --------------------------------------------------------------------------------------------------------------------------------------
 */

#include<stdio.h>

int getDimension(char* prompt);

void getMatrix(char* prompt, int r, int c, int arr[r][c]);

void addMatrix(int r, int c, int a[r][c], int b[r][c], int sum[r][c]);

void subtractMatrix(int r, int c, int a[r][c], int b[r][c], int sub[r][c]);

void displayMatrix(int r, int c, int arr[r][c]);

int main()
{
    int rows = 0, cols = 0;
    
    printf("\n****** Welcome User! ******\n\n");
    
    rows = getDimension("Please enter the number of rows in the matricies: ");
    cols = getDimension("Please enter the number of columns in the matricies: ");
    
    int matrix1[rows][cols], matrix2[rows][cols];
    int sumMatrix[rows][cols], subMatrix[rows][cols];
    
    getMatrix("Please enter the details for matrix 1:-\n", rows, cols, matrix1);
    getMatrix("Please enter the details for matrix 2:-\n", rows, cols, matrix2);
    
    addMatrix(rows, cols, matrix1, matrix2, sumMatrix);
    subtractMatrix(rows, cols, matrix1, matrix2, subMatrix);
    
    printf("\n******      A + B       ******\n");
    displayMatrix(rows, cols, sumMatrix);
    
    printf("\n******      A - B       ******\n");
    displayMatrix(rows, cols, subMatrix);
    
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
            printf("Please try again...........\n");
            while(getchar() != '\n' && !feof(stdin));
            continue;
        }
        else if (data <= 0)
        {
            printf("Error: Invalid input. Please enter value >= 1\n");
            while(getchar() != '\n' && !feof(stdin));
            continue;
        }
        else
        {
            return data;
        }
    }
}

void getMatrix(char* prompt, int r, int c, int arr[r][c])
{
    printf("%s", prompt);
    for(int i = 0; i < r; i++)
    {
        printf("\nPlease enter the %d row below:-\n", (i + 1));
        for(int j = 0; j < c; j++)
        {
            while(1)
            {
                if (scanf("%d", &arr[i][j]) != 1)
                {
                    printf("Error: Value could not be read as an integer\n");
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

void addMatrix(int r, int c, int a[r][c], int b[r][c], int sum[r][c])
{
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            sum[i][j] = a[i][j] + b[i][j];
        }
    }
}

void subtractMatrix(int r, int c, int a[r][c], int b[r][c], int sub[r][c])
{
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            sub[i][j] = a[i][j] - b[i][j];
        }
    }
}

void displayMatrix(int r, int c, int arr[r][c])
{
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}