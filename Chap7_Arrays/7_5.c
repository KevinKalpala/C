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

void getData(int arr[][], int size, int entries);

int main()
{
    int marks[CLASS_SIZE][4];

    printf("\n****** Welcome User! ******\n");

    getData(marks, CLASS_SIZE, 4);

    return 0;
}

void getData(int arr[][], int size, int entries)
{
    int data;

    printf("Please enter the data for the students:-\n");
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < entries; j++)
        {
            while(1)
            {
                if (j == 0) printf("Please enter the Roll No for student %d :", i);
                else if (printf("Please enter the marks of subject %d : "j);

            
        }
    }
}