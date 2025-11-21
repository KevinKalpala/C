/**
 * ---------------------------------------------------------------------------------------------------------------------------------
 * Program written by : Kevin Kalpala
 * Date               : 20 / 11 / 25
 * 
 * Description:
 * This program prompts the user to enter two non-negative double values (x and y) 
 * and then generates a formatted square root table for numbers ranging from 0.0 to 9.9.
 * The table highlights the rows and columns corresponding to the integer and fractional 
 * parts of the entered values for easy identification.
 * 
 * Input:
 * - Two non-negative double values (x and y)
 *   - Only numbers >= 0 are accepted
 *   - Input validation is performed to ensure correct numeric input
 * 
 * Output:
 * - A formatted square root table from 0.0 to 9.9
 * - Rows and columns corresponding to the integer and fractional parts of x and y 
 *   are highlighted for emphasis
 * 
 * Note:
 * - The program uses a small epsilon (EPS = 1e-9) for floating-point comparisons.
 * - The program handles invalid inputs gracefully, prompting the user to re-enter.
 * - The square root table is displayed in a neatly aligned format for readability.
 * ---------------------------------------------------------------------------------------------------------------------------------
 */


// *********************************                      My version                 *********************************************

#include<stdio.h>
#include<math.h>

#define EPS 1e-9
#define SAME(a, b) (fabs((a) - (b)) < EPS)

void getDoubleData(double* val);

void printTable(double x, double y);

int main()
{
    double x, y;

    printf("\n****** Welcome User! ******\n");
    printf("\nPlease enter the value of x: ");
    getDoubleData(&x);
    printf("Please enter the value of y: ");
    getDoubleData(&y);

    printTable(x, y);

}

void getDoubleData(double* val)
{
    while (1)
    {
        if (scanf("%lf", val) != 1)
        {
            printf("Error: An unexpected error just occurred\n");
            printf("Please try again...................\n");
            while(getchar() != '\n');
            continue;
        }
        else if (*val < 0.0)
        {
            printf("Error: Invalid Input. Please enter a positive value or 0\n");
            continue;
        }
        else
        {
            break;
        }
    }
}

void printTable(double x, double y)
{
    double xFractionalPart = x - (int)x;
    double yFractionalPart = y - (int)y;

    // printf("%2.1f\n", xFractionalPart);
    // printf("%2.1f\n", yFractionalPart);

    printf("\n\n                                       Square Root Table\n");
    printf("\n-------------------------------------------------------------------------------------------------------\n");
    printf("|  Number  |");
    for (double i = 0.0; i<=0.9; i+=0.1)
    {
        if (SAME(i, xFractionalPart) || SAME(i, yFractionalPart))
        {
            printf("|  %2.1lf  |", i);
        }
        else if (!(SAME(i, xFractionalPart) || SAME(i, yFractionalPart)) && SAME(i, 0.9))
        {
            printf("    %2.1lf  |", i);
        }
        else
        {
            printf("   %2.1lf   ", i);
        }
    }
    printf("\n-------------------------------------------------------------------------------------------------------\n");
    for (double i = 0.0; i <= 9.0; i+=1.0)
    {
        if (SAME(i, (int)x) || SAME(i, (int)y))
        {
            printf("-------------------------------------------------------------------------------------------------------\n");
        }
        
        printf("|    %2.1f   |", i);
        for (double j = 0.0; j <= 0.9; j+=0.1)
        {
            if (SAME(j, xFractionalPart) || SAME(j, yFractionalPart))
            {
                printf("|  %2.1lf  |", sqrt(i+j));
            }
            else if (!(SAME(j, xFractionalPart) || SAME(j, yFractionalPart)) && SAME(j, 0.9))
            {
                printf("    %2.1lf  |", sqrt(i+j));
            }
            else
            {
                printf("   %2.1lf   ", sqrt(i+j));
            }
        }
        
        
        if (SAME(i, (int)x) || SAME(i, (int)y))
        {
            printf("\n-------------------------------------------------------------------------------------------------------");
        }
        
        printf("\n");
    }
    printf("-------------------------------------------------------------------------------------------------------\n");
}

// **************************         Chatgpt version              ******************************************

// #include <stdio.h>
// #include <math.h>

// /* =============================
//          CONFIGURATION
//    ============================= */
// #define EPS 1e-9
// #define SAME(a, b) (fabs((a) - (b)) < EPS)

// #define FRAC_STEP 0.1
// #define MAX_FRAC 0.9

// /* ANSI Colors (works on Linux/macOS/Windows with modern terminals) */
// #define CLR_RESET   "\033[0m"
// #define CLR_YELLOW  "\033[1;33m"
// #define CLR_CYAN    "\033[1;36m"


// /* =============================
//       FUNCTION DECLARATIONS
//    ============================= */
// void getPositiveDouble(const char* msg, double* val);
// void getIntRange(int* start, int* end);
// void printHeader(double xFrac, double yFrac);
// int isHighlightedFrac(double f, double xFrac, double yFrac);
// int isHighlightedRow(int row, int xInt, int yInt);
// void printRow(int row, double xFrac, double yFrac, int xInt, int yInt);
// void printTable(double x, double y, int rowStart, int rowEnd);


// /* =============================
//               MAIN
//    ============================= */
// int main() {
//     double x, y;
//     int rowStart, rowEnd;

//     printf("\n********** WELCOME USER **********\n");

//     getPositiveDouble("\nEnter value x: ", &x);
//     getPositiveDouble("Enter value y: ", &y);

//     printf("\nEnter table integer row range (recommended: include floor(x) and floor(y)):\n");
//     getIntRange(&rowStart, &rowEnd);

//     printTable(x, y, rowStart, rowEnd);

//     return 0;
// }


// /* =============================
//          INPUT FUNCTIONS
//    ============================= */
// void getPositiveDouble(const char* msg, double* val)
// {
//     printf("%s", msg);

//     while (1)
//     {
//         if (scanf("%lf", val) != 1) {
//             printf("Invalid input. Try again: ");
//             while (getchar() != '\n');
//             continue;
//         }
//         if (*val < 0) {
//             printf("Value must be >= 0. Try again: ");
//             continue;
//         }
//         break;
//     }
// }

// void getIntRange(int* start, int* end)
// {
//     while (1)
//     {
//         printf("Start integer: ");
//         if (scanf("%d", start) != 1) {
//             printf("Invalid number.\n");
//             while (getchar() != '\n');
//             continue;
//         }

//         printf("End integer:   ");
//         if (scanf("%d", end) != 1) {
//             printf("Invalid number.\n");
//             while (getchar() != '\n');
//             continue;
//         }

//         if (*end < *start) {
//             printf("End must be >= start. Try again.\n");
//             continue;
//         }

//         break;
//     }
// }


// /* =============================
//         HIGHLIGHT FUNCTIONS
//    ============================= */
// int isHighlightedFrac(double f, double xFrac, double yFrac)
// {
//     return SAME(f, xFrac) || SAME(f, yFrac);
// }

// int isHighlightedRow(int row, int xInt, int yInt)
// {
//     return row == xInt || row == yInt;
// }


// /* =============================
//           PRINT HEADER
//    ============================= */
// void printHeader(double xFrac, double yFrac)
// {
//     printf("\n\n                                         SQUARE ROOT TABLE\n");
//     printf("-------------------------------------------------------------------------------------------------------\n");
//     printf("|  Number  |");

//     for (double f = 0.0; f <= MAX_FRAC + EPS; f += FRAC_STEP)
//     {
//         if (isHighlightedFrac(f, xFrac, yFrac))
//             printf("%s  %2.1lf  %s|", CLR_YELLOW, f, CLR_RESET);
//         else
//             printf("   %2.1lf   |", f);
//     }

//     printf("\n-------------------------------------------------------------------------------------------------------\n");
// }


// /* =============================
//              ROW PRINT
//    ============================= */
// void printRow(int row, double xFrac, double yFrac, int xInt, int yInt)
// {
//     int highlightRow = isHighlightedRow(row, xInt, yInt);

//     if (highlightRow)
//         printf("%s|   %2d     |%s", CLR_CYAN, row, CLR_RESET);
//     else
//         printf("|   %2d     |", row);

//     for (double f = 0.0; f <= MAX_FRAC + EPS; f += FRAC_STEP)
//     {
//         double val = sqrt(row + f);
//         int highlightFrac = isHighlightedFrac(f, xFrac, yFrac);

//         if (highlightFrac)
//             printf("%s  %2.2lf  %s|", CLR_YELLOW, val, CLR_RESET);
//         else
//             printf("  %2.2lf  |", val);
//     }

//     printf("\n");
// }


// /* =============================
//           FULL TABLE PRINT
//    ============================= */
// void printTable(double x, double y, int rowStart, int rowEnd)
// {
//     int xInt = (int)x;
//     int yInt = (int)y;

//     double xFrac = x - xInt;
//     double yFrac = y - yInt;

//     printHeader(xFrac, yFrac);

//     for (int row = rowStart; row <= rowEnd; row++)
//     {
//         if (isHighlightedRow(row, xInt, yInt))
//             printf("-------------------------------------------------------------------------------------------------------\n");

//         printRow(row, xFrac, yFrac, xInt, yInt);

//         if (isHighlightedRow(row, xInt, yInt))
//             printf("-------------------------------------------------------------------------------------------------------\n");
//     }

//     printf("-------------------------------------------------------------------------------------------------------\n");
// }
