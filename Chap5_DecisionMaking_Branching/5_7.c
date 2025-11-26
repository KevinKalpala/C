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

// #include<stdio.h>

// int main()
// {
//     // (a) Original Floyd's triangle
//     int count = 1;
//     int nextStartValue = 1;
//     for(int i = 1; i <= 91; i++)
//     {
//         int lastColValue = 0;
//         for(int col = 0; col < count; col++)
//         {
//             printf("%d", nextStartValue+col);
//             lastColValue = col;
//         }
//         printf("\n");

//         nextStartValue += lastColValue;
//         count++;

//         if(nextStartValue > 91)
//         {
//             break;
//         }
//     }

//     return 0;
// }

#include<stdio.h>

int getIntData(int minLimit);

int main()
{
    int maxcount;
    int row = 1, printedInRow = 0;
    
    printf("Please enter the upper limit to print: ");
    maxcount = getIntData(1);
    
    for(int count = 1; count <= maxcount; count++)
    {
        printf("%-3d", count);
        printedInRow++;
        if (printedInRow == row)
        {
            printf("\n");
            row++;
            printedInRow = 0;
        }
    }
    
    return 0;
}

int getIntData(int minLimit)
{
    int val;

    while(1)
    {
        if (scanf("%d", &val) != 1)
        {
            printf("Error: Input could not be read as an integer.\n");
            while(getchar() != '\n' && !feof(stdin));
            continue;
        }

        if (val < minLimit)
        {
            printf("Enter an integer >= %d\n", minLimit);
            continue;
        }

        else
        {
            return val;
        }
    }
}