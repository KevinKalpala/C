/**
 * -----------------------------------------------------------------------------------------------------------------------------
 * Program written by : Kevin Kalpala
 * Date               : 21 / 11 / 25
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
 * -----------------------------------------------------------------------------------------------------------------------------
 */

// ********************       (a) Floyd's triangle      *************************

// #include<stdio.h>

// int getIntData(int minLimit);

// int main()
// {
//     int maxcount;
//     int row = 1, printedInRow = 0;
    
//     printf("Please enter the upper limit to print: ");
//     maxcount = getIntData(1);
    
//     for(int count = 1; count <= maxcount; count++)
//     {
//         printf("%-3d", count);
//         printedInRow++;
//         if (printedInRow == row)
//         {
//             printf("\n");
//             row++;
//             printedInRow = 0;
//         }
//     }
    
//     return 0;
// }

// int getIntData(int minLimit)
// {
//     int val;
    
//     while(1)
//     {
//         if (scanf("%d", &val) != 1)
//         {
//             printf("Error: Input could not be read as an integer.\n");
//             while(getchar() != '\n' && !feof(stdin));
//             continue;
//         }
        
//         else if (val < minLimit)
//         {
//             printf("Enter an integer >= %d\n", minLimit);
//             continue;
//         }
        
//         else
//         {
//             return val;
//         }
//     }
// }

// ********************       (a) Modified Floyd's triangle      *************************

#include<stdio.h>

int getIntData(int minLimit);

int main()
{
    int maxcount;
    int row = 1, col = 0;
    
    printf("Please enter the number of terms to print: ");
    maxcount = getIntData(1);

    for(int count = 1; count <= maxcount; count++)
    {
        printf("%d ", ( row + col ) % 2);

        col++;

        if (col == row)
        {
            printf("\n");
            row++;
            col = 0;
        }
    }
    
    return 0;
}

int getIntData(int minLimit)
{
    int temp;

    while(1)
    {
        if (scanf("%d", &temp) != 1)
        {
            printf("Error: Input could not be read as an integer\n");
            while(getchar() != '\n' && !feof(stdin));
            continue;
        }
        
        else if (temp < minLimit)
        {
            printf("Enter an integer >= %d\n", minLimit);
            continue;
        }

        else
        {
            return temp;
        }
    }
}