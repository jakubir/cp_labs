/** @file */

#include <stdio.h>
#include <cstdlib>

/// @brief Declarations:

/// @brief Function printing "Hello world!"
void printHello();

/// @brief Function printing "Hello!" num times
/// @param num Number of times to print "Hello!"
void printManyHello(unsigned int num);

/// @brief Function returning sum of a and b
/// @param a First number
/// @param b Second number
/// @return Sum of a and b
float mySum(float a, float b);

/// @brief Function that returns doubled value of x
/// @param x Number
/// @return Doubled value of x
float returnDoubledNumber(float x);

/// @brief Function that doubles value of x
/// @param x Address of x
void doubleNumber(float * x);

/// @brief Function that fills array arr with random integer numbers
/// @param arr Array of integers (address of first element)
/// @param size Size of array arr
void fillArr(int * arr, int size);

/// @brief Function that prints all values stored in array of integers arr
/// @param array Array of integers (address of first element)
/// @param size Size of array arr
void printArr(const int * array, int size);

/// @brief Function that prints text array str
/// @param str Array of characters / text array
void printString(const char * str);

/// @brief Main function, entry point of the program
/// @return 0 on successful execution
int main()
{
    /* TASK 1.
     For each of the functions:
    - call the function for different values and/or variables (if applicable, define input data if needed),
    - display value returned by the function (if applicable),
    - assign value returned by the function to some variable (if applicable).*/
    
    
    return 0;
}

/// @brief Definitions:

void printHello()
{
    printf("Hello world!\n");
}

void printManyHello(unsigned int num)
{
    for(int i = 0; i < num; i++)
        printf("Hello!\n");
}

float mySum(float a, float b)
{
    return a + b;
}

float returnDoubledNumber(float x)
{
    return x * 2;
}

void doubleNumber(float * x)
{
    *x = *x * 2;
}

void fillArr(int * arr, int size)
{
    for(int i = 0; i < size; i++)
        arr[i] = rand();
}

void printArr(const int * array, int size)
{
    for(int i = 0; i < size; i++)
        printf("%d ", *(array+i));
    printf("\n");
}

void printString(const char * str)
{
    while(*str)
        putchar(*(str++));
}
