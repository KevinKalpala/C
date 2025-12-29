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

void printDetails(int array[][4], int size, int entries);

int main()
{
    int marks[CLASS_SIZE][4];
    
    printf("\n****** Welcome User! ******\n");
    
    getData(marks, CLASS_SIZE, 4);
    
    printDetails(marks, CLASS_SIZE, 4);
    
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
                if (j == 0) printf("Roll No for student %d : ", i+1);
                
                if (j >= 1) printf("Marks of subject %d : ", j);
                
                if (scanf("%d", &data) != 1)
                {
                    printf("Error: Value could not be read as an integer\n");
                    printf("Please try again....................\n");
                    while(getchar() != '\n' && !feof(stdin));
                    continue;
                }
                else if (j == 0)
                {
                    int repeat = 0;
                    for(int k = 0; k < i; k++)
                    {
                        if (data == array[k][j])
                        {
                            printf("Error: Roll No already exists. Please try again.......\n");
                            while(getchar() != '\n' && !feof(stdin));
                            repeat = 1;
                        }
                    }

                    if (repeat) continue;
                    else
                    {
                        array[i][j] = data;
                        break;
                    }
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

void printDetails(int array[][4], int size, int entries)
{
    int sum[size];

    printf("(a) Total marks obtained by each student:-\n");
    printf("-------------------------------------------------------------------\n");
    printf("|%-12s|%-12s|%-12s|%-12s|%-12s |\n", " Roll No", " Subject 1", " Subject 2", " Subject 3", " Total marks");
    printf("-------------------------------------------------------------------\n");
    
    for(int i = 0; i < size; i++)
    {
        sum[i] = 0;
        for(int j = 0; j < entries; j++)
        {
            if (j == 0) printf("| %-11d|", array[i][j]);
            else
            {
                sum[i] += array[i][j];
                
                if(j == 3) printf(" %-11d| %-11d |\n", array[i][j], sum[i]);
                else printf(" %-11d|", array[i][j]);
            }
        }
    }
    printf("-------------------------------------------------------------------\n\n");
    
    printf("(b) Highest marks in each subject and the student who secured it:-\n");

    int highestMarks[3][2] = {0};
    int studentDupHMarks[3][size];
    
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < size; j++)
        {
            studentDupHMarks[i][j] = 0;
        }
    }
    
    int dupCount[3] = {0};
    for(int i = 0; i < size; i++)
    {
        for(int j = 1; j < entries; j++)
        {
            if (array[i][j] > highestMarks[j - 1][1])
            {
                highestMarks[j - 1][0] = array[i][0];
                highestMarks[j - 1][1] = array[i][j];

                dupCount[j - 1] = 1;

                studentDupHMarks[j - 1][0] = array[i][0];
                for(int k = 1; k < size; k++) studentDupHMarks[j - 1][k] = 0;
            }
            else if (array[i][j] == highestMarks[j - 1][1])
            {
                studentDupHMarks[j - 1][dupCount[j - 1]++] = array[i][0];
            }
            else
            {
                // do nothing;
            }
        }
    }
    
    for(int i = 0; i < 3; i++)
    {
        printf("For Subject No : %d\n", i+1);
        printf("Highest Marks = %d\n", highestMarks[i][1]);
        
        if (dupCount[i] > 1)
        {
            printf("Obtained by Roll No : ");
            for(int j = 0; j < size; j++)
            {
                if (studentDupHMarks[i][j] > 0)
                {
                    printf(" %d", studentDupHMarks[i][j]);
                }
            }
            printf("\n");            
        }
        else printf("Obtained by Roll No : %d\n", highestMarks[i][0]);
    }
}