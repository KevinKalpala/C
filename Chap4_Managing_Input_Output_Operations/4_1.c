/**
* Program written by Kevin Kalpala
* Date : 08/10/25
*
* Program to read the string "WORDPROCESSING" from the terminal and display the same in the following formats:
* (a) WORD PROCESSING
* (b) WORD
*     PROCESSING
* (c) W.P.
*/

#include<stdio.h>
#include<string.h>
#include<ctype.h>

void getWord(char *w);

int main()
{
    char word[20];

    getWord(word);

    // (a) WORD PROCESSING
    printf("(a) %.4s%s%.10s\n", word, " ", word + 4);
    
    // (b) WORD
    //     PROCESSING
    printf("(b) %.4s\n    %.10s\n", word, word + 4);
    
    // (c) W.P.

    printf("(c) %c.%c.\n", toupper(word[0]), toupper(word[4]));

    return 0;
}

void getWord(char *w)
{
    while(1){
        printf("Please enter the word: ");
        if(scanf("%19s", w) != 1){
            printf("Error: An unexpected error just occurred.\n");
            printf("Please try again........................\n");
            while(getchar() != '\n');
            continue;
        }
        if(strcmp(w, "WORDPROCESSING") != 0){
            printf("Error: Please enter exactly 'WORDPROCESSING'\n");
            continue;
        }

        break;
    }
}