/**
 * -----------------------------------------------------------------------
 * Program written by : Kevin Kalpala
 * Date               : 10 / 11 / 25
 * 
 * Description:
 *     This program computes and prints the number of students:
 *     (a) who have obtained more than 80 marks
 *     (b) who have obtained more than 60 marks
 *     (c) who have obtained more than 40 marks
 *     (d) who have obtained 40 or less marks
 *     (e) in the range 81 to 100
 *     (f) in the range 61 to 80
 *     (g) in the range 41 to 60
 *     (h) in the range 0 to 40
 * 
 * Input:
 *     Number of students
 *     Marks of Students
 * 
 * Output:
 *     Count of students falling in different categories
 * 
 * Note:
 *     The program should use a minimum number of if statements
 * -----------------------------------------------------------------------
 */

#include<stdio.h>

#define  MAX 100
#define MIN 0

void getNoOfStudents(int* x);

void getMarks(int arr[], int size);

int main()
{
    while(1)
    {
        int n = 0, repeatProgram = 0;
        // range1 --> number of students who have obtained marks in the range 81 to 100
        // range2 --> number of students who have obtained marks in the range 61 to 80
        // range3 --> number of students who have obtained marks in the range 41 to 60
        // range4 --> number of students who have obtained marks in the range 0 to 40
        int rangeCount[4] = {0}; // {range1, range2, range3, range4}
        
        printf("\n****** Welcome User! ******\n");
        
        getNoOfStudents(&n);
        
        int marks[n];
        
        getMarks(marks, n);

        // map[i] tells which counter to increment for marks/20 bucket
        // (marks-1)/20 ensures correct range boundaries (80→range2)
        int map[6] = {3, 3, 2, 1, 0, 0};

        for (int i = 0; i < n; i++)
        {
            int idx = (marks[i] - 1) / 20;
            if(idx < 0) idx = 0; // handle 0 marks
            if(idx > 5) idx = 5; // handle 100 marks
            rangeCount[map[idx]]++;
        }

        printf("\n****** Results ******\n");
        printf("\n(a) Students who have obtained more than 80 marks           : %d\n", rangeCount[0]);
        printf("(b) Students who have obtained more than 60 marks             : %d\n", rangeCount[0] + rangeCount[1]);
        printf("(c) Students who have obtained more than 40 marks             : %d\n", rangeCount[0] + rangeCount[1] + rangeCount[2]);
        printf("(d) Students who have obtained 40 or less marks               : %d\n",rangeCount[3]);
        printf("(e) Students who have obtained marks in the range 81 to 100\n : %d\n", rangeCount[0]);
        printf("(f) Students who have obtained marks in the range 61 to 80\n  : %d\n", rangeCount[1]);
        printf("(g) Students who have obtained marks in the range 41 to 60\n  : %d\n", rangeCount[2]);
        printf("(h) Students who have obtained marks in the range 0 to 40\n   : %d\n", rangeCount[3]);
        

        while(1)
        {
            printf("\nDo you want re-run the program? (Press 1 for YES and 0 for NO)\n");
            if(scanf("%d", &repeatProgram) != 1)
            {
                printf("Error: An unexpected error just occurred\n");
                printf("We are very sorry for the inconvenience. Please try again.......\n");
                while(getchar() != '\n');
                continue;   
            }
            else if (repeatProgram < 0 || repeatProgram > 1)
            {
                printf("Please enter either 1 (for YES) or 0 (for NO)\n");
                continue;
            }
            else
            {
                break;
            }
        }

        if(repeatProgram == 1)
        {
            continue;
        }
        else
        {
            printf("Thank you for the using this program\n");
            printf("Hope you have a very nice day\n");
            printf("\n...............................Exiting..............................\n");
            break;
        }
    }
    
    return 0;
}

void getNoOfStudents(int* x)
{
    while(1)
    {
        printf("\nPlease enter the Number of students: ");
        if (scanf("%d", x) != 1)
        {
            printf("Error: An unexpected error just occurred\n");
            printf("We are very sorry for the inconvenience. Please try again............\n");
            while(getchar() != '\n');
            continue;
        }
        else if ( *x < 0)
        {
            printf("Please enter a positive integer value or zero\n");
            continue;
        }
        else 
        {
            break;
        }
    }
}

void getMarks(int arr[], int size)
{
    printf("Please enter the marks of %d students in order:-\n");
    for (int i = 0; i < size; i++)
    {
        while (1)
        {
            if (scanf("%d", &arr[i]) != 1)
            {
                printf("Error: An unexpected error just occurred\n");
                printf("We are very sorry for the inconvenience. Please try again................\n");
                while(getchar() != '\n');
                continue;
            }
            else if (arr[i] < MIN || arr[i] > MAX)
            {
                printf("Please enter marks between %d and %d (inclusive): ", MIN, MAX);
                continue;
            }
            else
            {
                break;
            }
        }
    }
}