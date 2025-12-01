/**
 * ---------------------------------------------------------------------------------------------------------------------
 * Program Written By : Kevin Kalpala
 * Date               : 01 / 12 / 25
 * 
 * Description:
 *      This program reads three integer values from the user and checks whether they
 *      can form the sides of a right-angled triangle based on the Pythagorean theorem:
 *                      
 *                  (Smallest Side)^2 + (Middle Side)^2 = (Largest Side)^2
 *
 *      The program validates input ensuring:
 *          - Only integers are accepted
 *          - No negative, zero, or duplicate values are entered
 *
 * Input:
 *      Three positive, unique integer values entered by the user.
 * 
 * Output:
 *      - If valid and forms a right-angled triangle:
 *              Displays the sides as: Base, Height, and Hypotenuse.
 *      - Otherwise:
 *              Informs the user that the values do not form a right-angled triangle.
 * 
 * Note:
 *      The input is restricted to integers only. Duplicate or non-positive values 
 *      are considered invalid and the user will be prompted to re-enter values.
 * ---------------------------------------------------------------------------------------------------------------------
 */

#include<stdio.h>

void getData(int* a, int* b, int* c);

void checkTriangle(int a, int b, int c);

int main()
{
    int num1, num2, num3;
    
    printf("\n****** Welcome User! ******\n");
    printf("Please enter three integer values: ");
    getData(&num1, &num2, &num3);
    
    checkTriangle(num1, num2, num3);
    
    return 0;
}

void getData(int* a, int* b, int* c)
{
    while(1)
    {
        if (scanf("%d %d %d", a, b, c) != 3)
        {
            printf("Error: Invalid input.\nValues could not be stored as an integer. Please try again.............\n");
            while(getchar() != '\n' && !feof(stdin));
            continue;
        }
        else if (a <= 0 || b <= 0 || c <= 0)
        {
            printf("Please enter a positive and non-zero value\n");
            continue;
        }
        else if (a == b || b == c || c == a)
        {
            printf("Error: Invalid input. Please enter unique values of a, b and c\n");
            continue;
        }
        else
        {
            break;
        }
    }
}

void checkTriangle(int a, int b, int c)
{
    int highestValue = (a > b) ? ((a > c) ? a : c) : ((b > c) ? b : c);
    int lowestValue = (a < b) ? ((a < c) ? a : c) : ((b < c) ? b : c); 
    int middleValue = (a == highestValue || a == lowestValue) ? ((b == highestValue || b == lowestValue) ? c : b) : a;
    if ((lowestValue * lowestValue) + (middleValue * middleValue) == (highestValue * highestValue))
    {
        printf("These values are sides of a right angled triangle with below given details:-\n");
        printf("Height     = %3d\n", middleValue);
        printf("Base       = %3d\n", lowestValue);
        printf("Hypotenuse = %3d\n", highestValue);
    }
    else
    {
        printf("No right angled triangle exists where %d, %d and %d are sides\n", a, b, c);
    }
}