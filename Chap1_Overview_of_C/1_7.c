
/* 
    Program written by Kevin Kalpala
    Date : 09/08/25
    
    Program adds two integers.
*/


#include<stdio.h>

// Constants to store the value of the given numbers
const int NUMBER1 = 20;
const int NUMBER2 = 10;

/** 
* Adds two integers.
*
* @param x First number
* @param y Second number
* @return Sum of x and y
*/
// note that the above given comment style is optional, but it's especially helpful in larger projects or when using documentation tools like Doxygen.
int addNumbers(int x, int y);
/** 
* Subtracts two integers.
*
* @param x First number
* @param y Second number
* @return Result of x minus y
*/
int subtractNumbers(int x, int y);

int main()
{

    // Declare two variables to store the result of operations(addition & subtraction)
    int add_result, sub_result;

    // Calculate the addition and store it in the result variable
    add_result = addNumbers(NUMBER1, NUMBER2);
 
    //Calculate the subtraction and store it in the result variable
    sub_result = subtractNumbers(NUMBER1, NUMBER2);

    // Display the results
    printf("%d + %d = %d\n", NUMBER1, NUMBER2, add_result);
    printf("%d - %d = %d\n", NUMBER1, NUMBER2, sub_result);

    return 0;
}

int addNumbers(int num1, int num2)
{
    return num1 + num2;
}

int subtractNumbers(int num1, int num2)
{
    return num1 - num2;
}