/**
 * -------------------------------------------------------------------------------------------------------------------------------------
 * Program written by : Kevin Kalpala
 * Date               : 23 / 12 / 25
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
 * -------------------------------------------------------------------------------------------------------------------------------------
 */

#include<stdio.h>

#define CLASS_SIZE 10

void getData(int array[][4], int size, int entries);

int main()
{
    int marks[CLASS_SIZE][4];

    printf("\n****** Welcome User! ******\n");

    getData(marks, CLASS_SIZE, 4);

    return 0;
}

void getData(int array[][4], int size, int entries)
{
    int data;

    printf("Please enter the data for the students:-\n");
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < entries; j++)
        {
            while(1)
            {
                if (j == 0) printf("Roll No for student %d :", i);
                    
                if (j < 4 && j >= 1) printf("Marks of subject %d : ", j);

                if (scanf("%d", &data) != 1)
                {
                    printf("Error: Value could not be read as an integer\n");
                    printf("Please try again....................\n");
                    while(getchar() != '\n' && !feof(stdin));
                    continue;
                }
                else if (data < 0 || data > 100)
                {
                    printf("Error: Invalid input. Please enter a value between 0 and 100 (both included)\n");
                    while(getchar() != '\n' && !feof(stdin));
                    continue;
                }
                else
                {
                    array[i][j] = data;
                    break;
                }
            }
        }
    }
}