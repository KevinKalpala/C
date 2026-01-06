/**
 * -----------------------------------------------------------------------------------------------------------------------------------
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
 * -----------------------------------------------------------------------------------------------------------------------------------
 */

#include<stdio.h>

int getDimension(char* prompt);

void getMatrix(char* prompt, int m, int n, int arr[m][n]);

int main()
{
    int m, n;
    
    printf("\n****** Welcome User! ******\n\n");
    
    m = getDimension("Please enter the value of m : ");
    n = getDimension("Please enter the value of n : ");
    
    int matrix[m][n];
    
    getMatrix("Please enter the details of the matrix :-\n", m, n, matrix);
    
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
        for(int j = 0; j < n; j++)
        {
            while(1)
            {
                if (scanf("%d ", arr[i][j]) != 1)
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