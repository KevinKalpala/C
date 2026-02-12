#include<stdio.h>
#include<string.h>

int main()
{
    char fullName[22];

    fgets(fullName, 22, stdin);

    printf("%s", fullName+14);

    return 0;
}