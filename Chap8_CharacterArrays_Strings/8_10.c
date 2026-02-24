/**
 * ------------------------------------------------------------------------------------------
 * Program written by : Kevin Kalpala
 * Date               : 24 / 02 / 26
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
 * ------------------------------------------------------------------------------------------
 */

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

int getIntData(char* prompt);

void alphabeticalSort(int s, int x, char names[s][x], int rollNos[s], int mark[s]);

void rollNoSort(int s, int x, char names[s][x], int rollNos[s], int mark[s]);

void markSort(int s, int x, char names[s][x], int rollNos[s], int mark[s]);

int main()
{
    int size;
    
    size = getIntData("Please enter the size of the class : ");
    
    int rollNo[size], marks[size];
    char name[size][41];
    
    printf("Please enter the following details:-\n");
    for(int i = 0; i < size; i++)
    {
        printf("For student no %d:-\n", i+1);
        rollNo[i] = getIntData("Roll No of student : ");
        marks[i] = getIntData("Marks obtained by the student : ");
        
        printf("Name of student : ");
        fgets(name[i], 41, stdin);
        name[i][strcspn(name[i], "\n")] = '\0';
    }
    
    //(a)
    alphabeticalSort(size, 41, name, rollNo, marks);
    
    //(b)
    rollNoSort(size, 41, name, rollNo, marks);

    //(c)
    markSort(size, 41, name, rollNo, marks);
    
    return 0;
}

int getIntData(char* prompt)
{
    int data;
    
    while(1)
    {
        printf("%s",prompt);
        if(scanf("%d", &data) != 1)
        {
            printf("Error: Value could not be read as an integer\n");
            printf("Please try again..............\n");
            while(getchar() != '\n' && !feof(stdin));
            continue;
        }
        else if(data <= 0)
        {
            printf("Error: Invalid input. Please enter a value > 0\n");
            while(getchar() != '\n' && !feof(stdin));
            continue;
        }
        else
        {
            while(getchar() != '\n' && !feof(stdin));
            return data;
        }
    }
}

void alphabeticalSort(int s, int x, char names[s][x], int rollNos[s], int mark[s])
{
    char alphaSortedNames[s][x];
    int alphaSortedRollNo[s], alphaSortedMark[s];
    
    for(int i = 0; i < s; i++)
    {
        alphaSortedRollNo[i] = rollNos[i];
        alphaSortedMark[i] = mark[i];
        strcpy(alphaSortedNames[i], names[i]);
    }
    
    for(int i = 0; i < s - 1; i++)
    {
        for(int j = i; j < s - i - 1; j++)
        {
            if(strcmp(alphaSortedNames[j], alphaSortedNames[j+1]) > 0)
            {
                char temp[41];
                strcpy(temp, alphaSortedNames[j]);
                strcpy(alphaSortedNames[j],  alphaSortedNames[j+1]);
                strcpy(alphaSortedNames[j+1], temp);
                
                int tempRollNo;
                tempRollNo = alphaSortedRollNo[j];
                alphaSortedRollNo[j] = alphaSortedRollNo[j+1];
                alphaSortedRollNo[j+1] = tempRollNo;
                
                int tempMarks;
                tempMarks = alphaSortedMark[j];
                alphaSortedMark[j] = alphaSortedMark[j+1];
                alphaSortedMark[j+1] = tempMarks;
            }
        }
    }
    
    printf("(a) Alphabetical list of names, roll numbers and marks obtained:-\n");
    printf("Roll No\tName\tMarks obtained\n");
    for(int i = 0; i < s; i++)
    {
        printf("%d\t%s\t%d\n", alphaSortedRollNo[i], alphaSortedNames[i], alphaSortedMark[i]);
    }
}

void rollNoSort(int s, int x, char names[s][x], int rollNos[s], int mark[s])
{
    char rollNoSortedNames[s][x];
    int rollNoSortedRollNos[s], rollNoSortedMarks[s];

    for(int i = 0; i < s; i++)
    {
        rollNoSortedRollNos[i] = rollNos[i];
        rollNoSortedMarks[i] = mark[i];
        strcpy(rollNoSortedNames[i], names[i]);
    }

    for(int i = 0; i < s - 1; i++)
    {
        for(int j = i; j < s - i - 1; j++)
        {
            if(rollNoSortedRollNos[j] > rollNoSortedRollNos[j+1])
            {
                int temp1 = rollNoSortedRollNos[j];
                rollNoSortedRollNos[j] = rollNoSortedRollNos[j+1];
                rollNoSortedRollNos[j+1] = temp1;

                int temp2 = rollNoSortedMarks[j];
                rollNoSortedMarks[j] = rollNoSortedMarks[j+1];
                rollNoSortedMarks[j+1] = temp2;

                char temp3[41];
                strcpy(temp3, rollNoSortedNames[j]);
                strcpy(rollNoSortedNames[j], rollNoSortedNames[j+1]);
                strcpy(rollNoSortedNames[j+1], temp3);
            }
        }
    }

    printf("(b) List sorted on roll numbers:-\n");
    printf("Roll No\tName\tMarks obtained\n");
    for(int i = 0; i < s; i++)
    {
        printf("%d\t%s\t%d\n", rollNoSortedRollNos[i], rollNoSortedNames[i], rollNoSortedMarks[i]);
    }
}

void markSort(int s, int x, char names[s][x], int rollNos[s], int mark[s])
{
    char markSortedNames[s][x];
    int markSortedRollNos[s], markSortedMarks[s];

    for(int i = 0; i < s; i++)
    {
        markSortedMarks[i] = mark[i];
        markSortedRollNos[i] = rollNos[i];
        strcpy(markSortedNames[i], names[i]);
    }

    for(int i = 0; i < s - 1; i++)
    {
        for(int j = i; j < s - i - 1; j++)
        {
            if(markSortedMarks[j] < markSortedMarks[j+1])
            {
                int temp1 = markSortedMarks[j];
                markSortedMarks[j] = markSortedMarks[j+1];
                markSortedMarks[j+1] = temp1;

                int temp2 = markSortedRollNos[j];
                markSortedRollNos[j] = markSortedRollNos[j+1];
                markSortedRollNos[j+1] = temp2;

                char temp3[41];
                strcpy(temp3, markSortedNames[j]);
                strcpy(markSortedNames[j], markSortedNames[j+1]);
                strcpy(markSortedNames[j+1], temp3);
            }
        }
    }

    printf("(c) List sorted on marks:-\n");
    printf("Rank\tRoll No\tName\tMarks obtained\n");
    for(int i = 0; i < s; i++)
    {
        printf("%d\t%d\t%s\t%d\n",i+1, markSortedRollNos[i], markSortedNames[i], markSortedMarks[i]);
    }
}