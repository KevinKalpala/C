/**
* Program written by Kevin Kalpala
* Date : 19/09/25
*
* Program to read a real number from the user and print the following output in one line:
* Smallest integer not less than the number     The given number       Largest integer not greater than the number
*/

#include<stdio.h>
#include<math.h>

int main()
{
    double number;

    printf("Please enter a real number (atmost 6-digits only including decimal point):\n");
    scanf("%lf", &number);

    printf("%d\t%.2f\t%d\n", (int)ceil(number), number, (int)floor(number));

    return 0;
}