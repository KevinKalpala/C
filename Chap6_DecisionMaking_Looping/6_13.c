/**
 * ------------------------------------------------------------------------------------------------------------------------------------
 * Program written by : Kevin Kalpala
 * Date               : 12 / 12 / 25
 * 
 * Description:
 * This program computes the value of Euler's number 'e' using the infinite series expansion:
 *      e = 1 + (1/1!) + (1/2!) + ... + (1/n!)
 * The program continues adding terms until the difference between two successive values of 'e'
 * becomes less than 0.00001 (EPS). The factorial terms are generated efficiently using:
 *      term = term / i
 * instead of recalculating factorial every time.
 * 
 * Input:
 * No input is required.
 * 
 * Output:
 * Displays the computed value of 'e' up to 6 decimal places.
 * 
 * Note:
 * The loop terminates when |newE - e| < EPS.
 * ------------------------------------------------------------------------------------------------------------------------------------
 */

#include<stdio.h>
#include<math.h>

#define EPS 1e-5
#define DIFFERENCE(a, b) (fabs((a) - (b)) < EPS)

int main()
{
    int i = 1;
    double term = 1.0, newE, e = 1.0;

    while(1)
    {
        term = term / i;
        newE = e + term;
        
        if (DIFFERENCE(newE, e)) break;

        e = newE;
        i++;
    }

    printf("\ne = %.6lf\n", e);

    return 0;
}