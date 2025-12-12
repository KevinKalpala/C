/**
 * ----------------------------------------------------------------------------------------------------------------------------------
 * Program written by : Kevin Kalpala
 * Date               : 12 / 12 / 25
 * 
 * Description:
 * This program computes the useful life (in years) of an item based on its original cost, 
 * annual rate of depreciation, and scrap value. The calculation uses the formula:
 * 
 *      p = c * (1 - d)^n
 * 
 * where:
 *      c = original cost of the item
 *      d = rate of depreciation per year (0 < d < 1)
 *      p = scrap value of the item
 *      n = useful life in years
 * 
 * The program takes all inputs interactively from the user with full input validation.
 * It then repeatedly applies the depreciation formula until the value of the item 
 * becomes less than or equal to the scrap value, determining the useful life.
 * 
 * Input:
 * - Original cost of the item (positive double)
 * - Scrap value (positive double, strictly less than original cost)
 * - Rate of depreciation (double between 0 and 1)
 * 
 * Output:
 * - Useful life of the item in years (integer)
 * 
 * Note:
 * - The program validates all user inputs and re-prompts for invalid entries.
 * - The depreciation is calculated iteratively rather than using logarithms, 
 *   ensuring better understanding and simplicity.
 * ----------------------------------------------------------------------------------------------------------------------------------
 */

#include<stdio.h>

double getDouble(char* prompt, double constraint);

int main()
{
    int n = 1;
    double p, c, d;
    
    printf("\n****** Welcome User! ******\n");
    
    c = getDouble("Please enter the original cost of the item : ", 0.0);
    while(1)
    {
        p = getDouble("Please enter the scrap value of the item : ", 0.0);

        if(p >= c)
        {
            printf("Error: Invalid input. Present value cannot be >= original cost value\n");
            continue;
        }
        else break;
    }

    while (1)
    {
        d = getDouble("Please enter the value of the rate of depreciation for the item (between 0 and 1): ", 0.0);
        if (d >= 1)
        {
            printf("Error: Depreciation rate must be less than 1\n");
            continue;
        }
        break;
    }

    
    double temp = (c * (1.0 - d));
    while(1)
    {
        if (temp <= p) break;
        else if (temp == 0)
        {
            n = 1;
            break;
        }
        else
        {
            temp *= (1.0 - d);
            n++;
        }
    }

    printf("Useful life of the item = %d\n", n);
    
    return 0;
}

double getDouble(char* prompt, double constraint)
{
    double data;

    while(1)
    {
        printf("%s", prompt);
        
        if (scanf("%lf", &data) != 1)
        {
            printf("Error: Value could not be read as a double\n");
            printf("Please try again.....................\n");
            while(getchar() != '\n' && !feof(stdin));
            continue;
        }
        else if (data <= constraint)
        {
            printf("Error: Invalid input. Please try again................\n");
            while(getchar() != '\n' && !feof(stdin));
            continue;
        }
        else
        {
            return data;
        }
    }
}