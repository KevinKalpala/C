#include<stdio.h>
#include<math.h>

int main()
{
    int i;
    float a, x, y1, y2;
    a = 0.4;

    printf("                                   Y ---->\n");
    printf("   0 -------------------------------------------------------------------------------\n");

    for(x = 0; x < 5; x += 0.25)
    {
        y1 = (int)(50 * exp(-a * x) + 0.5);
        y2 = (int)(50 * exp(-a * x * x / 2) + 0.5);

        /* Print X-axis vertical marker at x = 2.5 */
        if (x == 2.5)
            printf(" X | ");
        else
            printf("   | ");

        /* CASE 1: y1 == y2 → print a single # */
        if (y1 == y2)
        {
            for(i = 1; i <= y1 - 1; ++i)
                printf(" ");
            printf("#\n");
            continue;
        }

        /* CASE 2: y1 > y2 → y2 is left (*), y1 is right (0) */
        if (y1 > y2)
        {
            for(i = 1; i <= y2 - 1; ++i)
                printf(" ");
            printf("*");
            for(i = 1; i <= (y1 - y2 - 1); ++i)
                printf("-");
            printf("0\n");
            continue;
        }

        /* CASE 3: y2 > y1 → y1 is left (0), y2 is right (*) */
        if (y2 > y1)
        {
            for(i = 1; i <= y1 - 1; ++i)
                printf(" ");
            printf("0");
            for(i = 1; i <= (y2 - y1 - 1); ++i)
                printf("-");
            printf("*\n");
            continue;
        }
    }

    return 0;
}
