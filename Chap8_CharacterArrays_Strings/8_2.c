/**
 * -----------------------------------------------------------------------------------------------
 * Program written by : Kevin Kalpala
 * Date               : 12 / 02 / 25
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
 * -----------------------------------------------------------------------------------------------
 */

#include<stdio.h>
#include<string.h>

int main()
{
    char question[] = "Who is the inventor of C?";
    char answer[] = "Dennis Ritchie";
    char userAnswer[50];

    
    for(int i = 1; i <= 3; i++)
    {
        printf("%s\n", question);
        fgets(userAnswer, sizeof(userAnswer), stdin);
        userAnswer[strcspn(userAnswer, "\n")] = '\0';
        if(strcmp(answer, userAnswer) == 0)
        {
            printf("Good\n");
            break;
        }
        else
        {
            if(i == 3)
            {
                printf("The correct answer is : %s\n", answer);
            }
            else
            {
                printf("Try again\n");
            }
        }
    }


    return 0;
}