/**
* Program written by Kevin Kalpala
* Date 12/08/25
*
* Program to convert a given value of temperature from celsius to Fahrenheit and vice versa
*/

#include<stdio.h>

const float temp_in_celsius = 32.7; // Temperature value in celsius
const float temp_in_fahrenheit = 104.2; // Temperature value in fahrenheit

/**
* Function to convert the value of temperature from fahrenheit to celsius 
* @param temp_in_fahrenheit Temperature in fahrenheit
* @return Result of (5/9)*(F - 32)
*/
float calculate_celsius(float temperature);
/**
* Function to convert the value of temperature from celsius to fahrenheit 
* @param temp_in_celsius Temperature in celsius
* @return Result of (9/5)*C + 32
*/
float calculate_fahrenheit(float temperature);

int main()
{
    // Declare two variables to store the two converted temperatures in celsius and fahrenheit
    float temp_result_in_celsius, temp_result_in_fahrenheit; 

    // Intialize respective converted temperature values to both result variables
    temp_result_in_celsius = calculate_celsius(temp_in_fahrenheit);
    temp_result_in_fahrenheit = calculate_fahrenheit(temp_in_celsius);

    // Display the result values
    printf("1. From Celsius to Fahrenheit\n");
    printf("%5.3f Celsius = %5.3f Fahrenheit\n", temp_in_celsius, temp_result_in_fahrenheit);
    printf("2. From Fahrenheit to Celsius\n");
    printf("%5.3f Fahrenheit = %5.3f Celsius\n", temp_in_fahrenheit, temp_result_in_celsius);
    
    return 0;
}

float calculate_celsius(float temperature)
{
    float result;
    result = ((float)5/9) * (temperature - 32); // Cast to float to avoid integer division; 5/9 would be 0
    return result;
}

float calculate_fahrenheit(float temperature)
{
    float result;
    result = ((float)9/5) * temperature + 32; // Cast to float to avoid integer division; 9/5 as integers gives 1 but actually 9/5 is 1.8
    return result;
}