/**
 * -------------------------------------------------------------------------------------------------------------------
 * Program written by : Kevin Kalpala
 * Date               : 02 / 12 / 25
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
 * -------------------------------------------------------------------------------------------------------------------
 */

#include<stdio.h>
#include<math.h>

double getRad();

char getChar();

int main()
{
    char t;
    double x, result;
    
    printf("Please enter the value of x : ");
    x = getRad();
    
    printf("Please enter the value of T : ");
    t = getChar();

    // (i) if.......else statement

    // if (t == 'c' || t == 'C')
    // {
    //     result = cos(x);
    //     printf("COS(%.3lf) = %.3lf\n", x, result);
    // }
    // else
    // {
    //     if (t == 's' || t == 'S')
    //     {
    //         result = sin(x);
    //         printf("SIN(%.3lf) = %.3lf\n", x, result);
    //     }
    //     else
    //     {
    //         result = tan(x);
    //         printf("TAN(%.3lf) = %.3lf\n", x, result);
    //     }
    // }

    // (ii) switch statement

    int choice = (t == 's' || t == 'S') ? 1 : ((t == 'c' || t == 'C') ? 2 : 3); 

    switch(choice)
    {
        case 1:
            result = sin(x);
            printf("SIN(%.3lf) = %.3lf\n", x, result);
            break;

        case 2:
            result = cos(x);
            printf("COS(%.3lf) = %.3lf\n", x, result);
            break;

        case 3:
            result = tan(x);
            printf("TAN(%.3lf) = %.3lf\n", x, result);
            break;

        default:
            break;
    }
    
    return 0;
}

double getRad()
{
    double result;
    
    while(1)
    {
        if (scanf("%lf", &result) != 1)
        {
            printf("Error: Value could not be read as a double type\n");
            printf("Please try again....................\n");
            while(getchar() != '\n' && !feof(stdin));
            continue;
        }
        else if (result < 0 || result > 2 * M_PI)
        {
            printf("Error: Value out of range! Please enter a number between 0 and 2π\n");
            continue;
        }
        else
        {
            return result;
        }
    }
}

char getChar()
{
    int ch;
    
    // Peak at the first character in the stdin
    ch = getchar();
    if (ch != EOF && ch != '\n')
    {
        ungetc(c, stdin); // Put it back if it's not a leftover newline
    }
    // if c == '\n', it was leftover -> skip it
    else if (ch == '\n')
    {
        // do nothing, newline consumed
    }
    

    char c;

    while(1)
    {
        if (scanf("%c", &c) != 1)
        {
            printf("Error: Value could not be read as a character\n");
            printf("Please try again................\n");
            while(getchar() != '\n' && !feof(stdin));
            continue;
        }
        else if (c != 's' && c != 'S' && c != 'c' && c != 'C' && c != 't' && c != 'T')
        {
            printf("Error: Invalid input\n");
            continue;
        }
        else
        {
            return c;
        }
    }
}