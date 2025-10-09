/**
* Program written by Kevin Kalpala
* Date : 09/10/25
*
* Program to read the following numbers, round them off to nearest integers and print out the results in integer form
* 35.7 50.21 -23.73 -46.45
*/

#include<stdio.h>
#include<math.h>

void getNumbers(float* n1, float* n2, float* n3, float* n4);

void roundNumbers(float* n1, float* n2, float* n3, float* n4, int* x, int* y, int* z, int* w);

int main()
{
    float num1, num2, num3, num4;
    int roundedNum1, roundedNum2, roundedNum3, roundedNum4;

    getNumbers(&num1, &num2, &num3, &num4);

    // Round the given numbers
    roundNumbers(&num1, &num2, &num3, &num4, &roundedNum1, &roundedNum2, &roundedNum3, &roundedNum4);
    
    // Display the results
    printf("The rounded numbers are %d, %d, %d and %d\n", roundedNum1, roundedNum2, roundedNum3, roundedNum4);

    return 0;
}

void getNumbers(float* n1, float* n2, float* n3, float* n4)
{
    while(1)
    {
        printf("Please enter four floating point numbers:\n");
        if(scanf("%f %f %f %f", n1, n2, n3, n4) != 4){
            printf("Error: An error just occurred while recording the numbers.\n");
            printf("Please try again......................................\n");
            while(getchar() != '\n');
            continue;
        }
        

        break;
    }
}

void roundNumbers(float* n1, float* n2, float* n3, float* n4, int* x, int* y, int* z, int* w)
{
    if(*n1 >= 0.0){
        *x = (int)(*n1 + 0.5);    
    }else{
        *x = (int)(*n1 - 0.5);
    }

    if(*n2 >= 0.0){
        *y = (int)(*n2 + 0.5);    
    }else{
        *y = (int)(*n2 - 0.5);
    }

    if(*n3 >= 0.0){
        *z = (int)(*n3 + 0.5);    
    }else{
        *z = (int)(*n3 - 0.5);
    }

    if(*n4 >= 0.0){
        *w = (int)(*n4 + 0.5);    
    }else{
        *w = (int)(*n4 - 0.5);
    }
}