/**
 * --------------------------------------------------------------------------------------------------------------------------------------------
 * Program written by : Kevin Kalpala
 * Date               : 22 / 12 / 25
 * 
 * Description:
 * This program reads temperature values (in degrees) for multiple cities
 * over a period of 31 days and determines the highest and lowest temperature
 * recorded. It also displays the corresponding day and city where these
 * extreme temperatures occurred.
 * 
 * Input:
 * - Temperature values (double) for 31 days and 10 cities.
 * - Each temperature must be a non-negative value.
 * 
 * Output:
 * - Highest temperature along with the city number and day number.
 * - Lowest temperature along with the city number and day number.
 * 
 * Note:
 * - The program uses a 2D array to store temperature values.
 * - Input validation is performed to ensure valid double values.
 * - Symbolic constants (DAYS and CITY) are used for better readability
 *   and easy modification.
 * --------------------------------------------------------------------------------------------------------------------------------------------
 */

#include<stdio.h>

#define DAYS 31
#define CITY 10

void readTemperatureValues(char* prompt, double arr[DAYS][CITY]);

void calculateHighestLowest(double arr[DAYS][CITY]);

int main()
{
    double temperature[DAYS][CITY];
    
    printf("\n****** Welcome User! ******\n");
    
    readTemperatureValues("Please enter the temperature values (in degrees):-\n", temperature);
    
    calculateHighestLowest(temperature);
    
    return 0;
}

void readTemperatureValues(char* prompt, double arr[DAYS][CITY])
{
    double value;
    
    printf("%s", prompt);
    for(int i = 0; i < DAYS; i++)
    {
        for(int j = 0; j < CITY; j++)
        {
            while(1)
            {
                if (scanf("%lf", &value) != 1)
                {
                    printf("Error: Value could not be read as a double\n");
                    printf("Please try again.............................\n");
                    while(getchar() != '\n' && !feof(stdin));
                    continue;
                }
                else if (value < 0)
                {
                    printf("Error: Invalid input. Please enter a value >= 0\n");
                    while(getchar() != '\n' && !feof(stdin));
                    continue;
                }
                else
                {
                    arr[i][j] = value;
                    break;
                }
            }
        }
    }
}
    
void calculateHighestLowest(double arr[DAYS][CITY])
{
    int highestDay, highestCity, lowestDay, lowestCity;
    double highest, lowest;

    for(int i = 0; i < DAYS; i++)
    {
        for(int j = 0; j < CITY; j++)
        {
            if (i == 0 && j == 0)
            {
                highest = arr[i][j];
                lowest = arr[i][j];
                highestDay = lowestDay = i + 1;
                highestCity = lowestCity = j + 1;
            }
            else
            {
                if (arr[i][j] > highest)
                {
                    highest = arr[i][j];
                    highestDay = i+1;
                    highestCity = j+1;
                }
                else if (arr[i][j] < lowest)
                {
                    lowest = arr[i][j];
                    lowestDay = i+1;
                    lowestCity = j+1;
                }
                else /*do nothing*/;
            }
        }
    }

    printf("Highest Temperature = %.4lf degrees in City = %d and at Day = %d\n", highest, highestCity, highestDay);

    printf("Lowest Temperature = %.4lf degrees in City = %d and at Day = %d\n", lowest, lowestCity, lowestDay);
}