/**
 * --------------------------------------------------------------------------------------------------
 * Program written by : Kevin Kalpala
 * Date               : 02 / 12 / 25
 * 
 * Description:
 *      This program reads two integer values representing a lower and upper limit. It then checks all
 *      numbers within this range and identifies which ones are prime. The program counts and displays
 *      all prime numbers found between the given range.
 *      
 *      The original version of the program checked a single number for primality. In this modified 
 *      version, the logic has been expanded to handle a range of numbers instead of just one.
 * 
 * Input:
 *      lower limit → An integer value representing the starting point of the range.
 *      upper limit → An integer value representing the ending point of the range.
 * 
 * Output:
 *      - A list of all prime numbers between the given limits.
 *      - The total count of prime numbers found.
 * 
 * Note:
 *      - Input is validated to ensure only integers are accepted.
 *      - sqrt() from <math.h> is used to optimize the prime-checking logic.
 *      - Numbers less than or equal to 1 are automatically excluded, as they are not prime.
 * --------------------------------------------------------------------------------------------------
 */

// ****************************     Original Program    ************************************

// #include<stdio.h>
// #include<math.h>

// int getIntData();

// void checkIfPrime(int n);

// int main()
// {
//     int num, isPrime = 0;
    
//     printf("\nPlease enter a number : ");
//     num = getIntData();
    
//     checkIfPrime(num);
    
//     return 0;
// }

// int getIntData()
// {
//     int data;
    
//     while(1)
//     {
//         if (scanf("%d", &data) != 1)
//         {
//             printf("Error: Value could not be read as an integer\n");
//             printf("Please try again.............\n");
//             while(getchar() != '\n' && !feof(stdin));
//             continue;
//         }
//         else
//         {
//             return data;
//         }
//     }
// }

// void checkIfPrime(int n)
// {
//     int isPrime = 1;

//     if (n <= 1)
//     {
//         isPrime = 0;
//     }
//     else
//     {
//         for(int i = 2; i <= sqrt(n); i++)
//         {
//             if (n % i == 0)
//             {
//                 isPrime = 0;
//                 break;
//             }
//         }
//     }

//     if (isPrime)
//     {
//         printf("%d is a Prime Number.\n", n);
//     }
//     else
//     {
//         printf("%d is not a prime number.\n", n);
//     }
// }

// *************************         Modified Program          **************************************

#include<stdio.h>
#include<math.h>

int getIntData();

void checkPrime(int lowerLimit, int upperLimit);

int main()
{
    int lower, upper;
    
    printf("\nPlease enter the lower limit : ");
    lower = getIntData();
    
    printf("Please enter the upper limit : ");
    upper = getIntData();
    
    checkPrime(100, 200);
    
    return 0;
}

int getIntData()
{
    int data;

    while(1)
    {
        if (scanf("%d", &data) != 1)
        {
            printf("Error: Value could not be read as an integer\n");
            printf("Please try again....................\n");
            while(getchar() != '\n' && !feof(stdin));
            continue;
        }
        else
        {
            return data;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   
        }
    }
}

void checkPrime(int lowerLimit, int upperLimit)
{
    int count = 0;
    
    for (int i = lowerLimit; i <= upperLimit; i++)
    {
        int isPrime = 1;

        if (i <= 1)
        {
            continue;
        }
        
        for (int j = 2; j <= sqrt(i); j++)
        {
            if (i % j == 0)
            {
                isPrime = 0;
                break;
            }
        }
        
        if (isPrime)
        {
            printf("%d ", i);
            count++;
        }
    }
    
    printf("\nTotal prime numbers between %d and %d: %d\n",
        lowerLimit, upperLimit, count);
}