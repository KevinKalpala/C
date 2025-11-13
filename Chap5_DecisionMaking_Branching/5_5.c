/**
 * -------------------------------------------------------------------------------------------
 * Program written by : Kevin Kalpala
 * Date               : 13 / 11 / 2025
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
 * -------------------------------------------------------------------------------------------
 */

#include<stdio.h>

#define MAX 100
#define MIN 0

void getNoOfStudents(int* n);

void getData(int marks[][3], int size);

void checkEligibility(int marks[][3], int size);

int checkCriteria1(int mathsMarks);

int checkCriteria2(int physicsMarks);

int checkCriteria3(int chemistryMarks);

int checkCriteria4(int mathsMarks, int physicsMarks, int chemistryMarks);

int main()
{
    while (1)
    {
        int students = 0, repeatProgram = 0;
    
        printf("\n****** Welcome User! ******\n");

        getNoOfStudents(&students);

        int marks[students][3];

        getData(marks, students);

        checkEligibility(marks, students);

        while (1)
        {
            printf("Do you want to re-run this program? (Press 1 for YES and 0 for NO)\n");
            if (scanf("%d", &repeatProgram) != '\n')
            {
                printf("Error: An unexpected error just occurred.\n");
                printf("We are very sorry for the inconvenience. Please try again...........\n");
                while(getchar() != '\n');
                continue;
            }
            else if (repeatProgram != 0 && repeatProgram != 1)
            {
                printf("Error: Please enter a valid value\n");
                printf("Press 1 for YES and 2 for NO\n");
                continue;
            }
            else
            {
                break;
            }
        }

        if(repeatProgram)
        {
            continue;
        }
        else
        {
            printf("\nThank you for using this program\n");
            printf("We hope you have a very nice day\n");
            break;
        }
    }

    return 0;
}

void getNoOfStudents(int* n)
{
    while (1)
    {
        printf("\nPlease enter the number of students: ");
        if (scanf("%d", n) != 1)
        {
            printf("Error: An unexpected error just occurred.\n");
            printf("We are very sorry for the inconvenience. Please try again...........\n");
            while(getchar() != '\n');
            continue;
        }
        else if (*n <= 0)
        {
            printf("Error: Please enter a positive and non-zero value");
            continue;
        }
        else
        {
            break;
        }
    }
}

void getData(int marks[][3], int size)
{
    while (1)
    {
        for (int i = 0; i < size; i++)
        {
            printf("\n****** Student Number %d ******\n", i+1);
            printf("Please enter the following details for the students:-\n");
            for (int j = 0; j < 3; j++)
            {
                if (j == 0)
                {
                    printf("Maths: ");
                    if (scanf("%d", &marks[i][j]) != 1)
                    {
                        printf("Error: An unexpected error just occurred.\n");
                        printf("We are very sorry for the inconvenience. Please try again..............\n");
                        while(getchar() != '\n');
                        continue;
                    }
                    else if (marks[i][j] <= MIN || marks[i][j] >= MAX)
                    {
                        printf("Error: Please enter a value between %d and %d\n", MIN, MAX);
                        continue;
                    }
                    else
                    {
                        break;
                    }
                }

                if (j == 1)
                {
                    printf("Physics: ");
                    if (scanf("%d", &marks[i][j]) != 1)
                    {
                        printf("Error: An unexpected error just occurred.\n");
                        printf("We are very sorry for the inconvenience. Please try again..............\n");
                        while(getchar() != '\n');
                        continue;
                    }
                    else if (marks[i][j] <= MIN || marks[i][j] >= MAX)
                    {
                        printf("Error: Please enter a value between %d and %d\n", MIN, MAX);
                        continue;
                    }
                    else
                    {
                        break;
                    }
                }

                if (j == 2)
                {
                    printf("Chemistry: ");
                    if (scanf("%d", &marks[i][j]) != 1)
                    {
                        printf("Error: An unexpected error just occurred.\n");
                        printf("We are very sorry for the inconvenience. Please try again..............\n");
                        while(getchar() != '\n');
                        continue;
                    }
                    else if (marks[i][j] <= MIN || marks[i][j] >= MAX)
                    {
                        printf("Error: Please enter a value between %d and %d\n", MIN, MAX);
                        continue;
                    }
                    else
                    {
                        break;
                    }
                }
            }
        }

        break;
    }
}

void checkEligibility(int marks[][3], int size)
{
    int eligibleStudents[size][4], totalEligibleStudents = 0; // i = size because atmost all the students can be eligible

    for (int i = 0; i < size; i++)
    {
        int criteria1Status = 0, criteria2Status = 0, criteria3Status = 0, criteria4Status = 0;

        criteria1Status = checkCriteria1(marks[i][1]);
        criteria2Status = checkCriteria2(marks[i][2]);
        criteria3Status = checkCriteria3(marks[i][3]);
        criteria4Status = checkCriteria4(marks[i][1], marks[i][2], marks[i][3]);

        if(criteria1Status && criteria2Status && criteria3Status && criteria4Status)
        {
            eligibleStudents[totalEligibleStudents][0] = i;
            eligibleStudents[totalEligibleStudents][1] = marks[i][1];
            eligibleStudents[totalEligibleStudents][2] = marks[i][2];
            eligibleStudents[totalEligibleStudents][3] = marks[i][3];
            totalEligibleStudents++;
        }
    }

    printf("\n******* Results ******\n");
    printf("Total eligible students found: %d\n", totalEligibleStudents);
    printf("Their details are mentioned below:-\n");
    printf("----------------------------------------------------------------------------------------------\n");
    printf("|                          |----------------------  Marks Obtained   ------------------------|\n");
    printf("----------------------------------------------------------------------------------------------\n");
    printf("%-15s%-15s%-15s%-15s\n", "| Student No", "Maths", "Physics", "Chemistry |");
    for (int i = 0; i <= totalEligibleStudents; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (j == 0)
            {
                printf("| %-15d", eligibleStudents[i][j]);
                
            }
            else if (j == 3)
            {
                printf("%-15d |", eligibleStudents[i][j]);
                printf("\n");
                
            }
            else
            {
                printf("%-15d", eligibleStudents[i][j]);
            }
        }
    }   
    printf("----------------------------------------------------------------------------------------------\n");
}

int checkCriteria1(int mathsMarks)
{
    if (mathsMarks >= 60) return 1;
    else return 0;
}

int checkCriteria2(int physicsMarks)
{
    if (physicsMarks >= 50) return 1;
    else return 0;
}

int checkCriteria3(int chemistryMarks)
{
    if (chemistryMarks >= 40) return 1;
    else return 0;
}   

int checkCriteria4(int mathsMarks, int physicsMarks, int chemistryMarks)
{
    if ((mathsMarks + physicsMarks + chemistryMarks) >= 200) return 1;
    else if ((mathsMarks + physicsMarks) >= 150) return 1;
    else return 0;
}   