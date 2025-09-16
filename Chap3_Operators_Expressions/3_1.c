/**
* Program written by Kevin Kalpala
* Date : 16/09/25
*
* Program to read values of three variables and rotate them 
*/

#include<stdio.h>

int x, y, z;

void rotate();
void print();

int main()
{
    // Scan the values from the user
    printf("Enter the value of x:\n");
    scanf("%d",&x);

    printf("Enter the value of y:\n");
    scanf("%d",&y);

    printf("Enter the value of z:\n");
    scanf("%d",&z);

    // Display the variable values before rotation
    printf("Before Rotation\n");
    print();
    
    // Rotate the values
    rotate();
    
    // Display the variable values after rotation
    printf("After Rotation\n");
    print();
    
    return 0;
}

void rotate()
{
    int temp;
    temp = x;
    x = y;
    y = z;
    z = temp;
}

void print()
{
    printf("x = %d\ny = %d\nz = %d\n", x, y, z);
}