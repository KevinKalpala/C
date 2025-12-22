/**
 * --------------------------------------------------------------------------------------------------------------------------------------------
 * Program written by : Kevin Kalpala
 * Date               : 22 / 12 / 25
 * 
 * Description:
 * This program simulates a simple voting system for an election with a fixed
 * number of candidates. It accepts votes from voters, counts the number of
 * votes received by each candidate, and also tracks the number of spoilt
 * ballots (invalid votes).
 * 
 * Input:
 * - Total number of ballots to be cast.
 * - Vote value for each ballot (integer).
 *   Valid votes range from 1 to 5, where each number represents a candidate.
 * 
 * Output:
 * - Total number of votes cast.
 * - Number of votes received by each candidate.
 * - Total number of spoilt ballots.
 * 
 * Note:
 * - Input validation is performed to ensure only valid integer inputs are
 *   accepted.
 * - Votes less than 1 are rejected at input time.
 * - Votes greater than the number of candidates are treated as spoilt ballots.
 * - Symbolic constant (CANDIDATES) is used for better readability and easy
 *   modification.
 * --------------------------------------------------------------------------------------------------------------------------------------------
 */

#include<stdio.h>

#define CANDIDATES 5

int getNumberOfBallots(char* prompt);

int getVote(char* prompt);

int main()
{
    int count[CANDIDATES], n, vote, spoiltBallotsCount = 0;
    
    for(int i = 0; i < CANDIDATES; i++)
    {
        count[i] = 0;
    }
    
    printf("\n****** Welcome User! ******\n");
    
    n = getNumberOfBallots("Please enter the number of ballots : ");
    
    for(int i = 0; i < n; i++)
    {
        vote = getVote("Please enter the vote : ");
        
        if (vote > 5) spoiltBallotsCount++;
        else
        {
            switch(vote)
            {
                case 1: count[0]++; break;
                case 2: count[1]++; break;
                case 3: count[2]++; break;
                case 4: count[3]++; break;
                case 5: count[4]++; break;
            }
        }
    }

    printf("Total votes cast = %d\n", n);
    printf("Votes received by each candidate are as follows:-\n");
    for(int i = 0; i < CANDIDATES; i++)
    {
        printf("Candidate %d = %d\n", i+1, count[i]);
    }
    printf("Total number of Spoilt ballots = %d\n", spoiltBallotsCount);
    
    return 0;
}

int getNumberOfBallots(char* prompt)
{
    int data;
    
    while(1)
    {
        printf("%s", prompt);
        if (scanf("%d", &data) != 1)
        {
            printf("Error: Value could not be read as an integer\n");
            printf("Please try again......................\n");
            while(getchar() != '\n' && !feof(stdin));
            continue;
        }
        else if (data < 1)
        {
            printf("Error: Invalid input. Please enter a number >= 1\n");
            while(getchar() != '\n' && !feof(stdin));
            continue;
        }
        else
        {
            return data;
        }
    }
}

int getVote(char* prompt)
{
    int data;

    while(1)
    {
        printf("%s", prompt);
        if (scanf("%d", &data) != 1)
        {
            printf("Error: Value could not be stored as an integer\n");
            printf("Please try again...................\n");
            while(getchar() != '\n' && !feof(stdin));
            continue;
        }
        else if (data < 1)
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