/** @file */

#include <stdio.h>
#include <cstdlib>
#include <limits.h>

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
void doubleNumber(float* x);

/// @brief Function that fills array arr with random integer numbers
/// @param arr Array of integers (address of first element)
/// @param size Size of array arr
void fillArr(int* arr, int size);

/// @brief Function that prints all values stored in array of integers arr
/// @param array Array of integers (address of first element)
/// @param size Size of array arr
void printArr(const int* array, int size);

/// @brief Function that prints text array str
/// @param str Array of characters / text array
void printString(const char* str);

// 2) Write a function taking two integers as parameters and returning the maximum of these numbers.
int max(int a, int b)
{
    return a > b ? a : b;
}

//3) Write a function taking three doubles as parameters and returning 1 if they are equal, 0 otherwise.
bool are_equal(double a, double b, double c)
{
    return a == b && a == c ? 1 : 0;
}

//4) Write a function taking an integer as parameter and increasing its value by 100.
void plus_100(int* a)
{
    *a += 100;
}

//5) Write a function my_swap, which exchanges values in two float variables.
void my_swap(float* a, float* b)
{
    float tmp = *a;
    *a = *b;
    *b = tmp;
}

//6) Write a function minOfArr, which finds minimum value in an array of integers.
int minOfArr(int* arr, int size)
{
    int min = arr[0];
    for (int i = 1; i < size; i++)
        if (arr[i] < min)
            min = arr[i];

    return min;
}

//7) Write a function accepting a text string(a pointer to char) and counting words in this text.
int num_of_words(const char* txt)
{
    int counter = 1;
    while (*txt) {
        if (*txt == ' ' || *txt == '\n')
            counter++;
        txt++;
    }
    return counter;
}

//8) Write a recursive function fibonacci, which returns n-th Fibonacci number (n should be taken as a parameter). A recursive function contains a call to itself. Fibonacci sequence: F_0 = 1; F_1 = 1; F_n = F_(n-1) + F_(n-2)
int fibonacci(int n) {
    if (n == 0 || n == 1)
        return 1;

    return fibonacci(n - 1) + fibonacci(n - 2);
}

//9) Write a function concatenating two strings (like strcat).
//This C library function strcat  appends the string pointed to by src to the end of the string pointed to by dest.
char*  my_strcat(char* dest, const char* src)
{
    int dest_len = 0;
    while (*(dest+dest_len) != '\0')
        dest_len++;

    char* str = dest;
    
    str += dest_len;
    *str++ = *src++;
    *str++ = *src++;
    *str++ = *src++;
    *str++ = *src++;
    *str++ = *src++;

    return str;
}

/// @brief Main function, entry point of the program
/// @return 0 on successful execution
int main()
{
    // POINTERS
    // Define an array of 100 doubles and fill it with numbers using a pointer.

    double array[100] = { 0 };

    for (int i = 0; i < 100; i++)
    {
        *(array + i) = i * 5.0f;
    }

    /* TASK 1.
     For each of the functions:
    - call the function for different values and/or variables (if applicable, define input data if needed),
    - display value returned by the function (if applicable),
    - assign value returned by the function to some variable (if applicable).*/

    printHello();

    printManyHello(5);

    printf("%f\n", mySum(1.0f, 2.0f));
    printf("%f\n", mySum(1, 2));

    printf("%f\n", returnDoubledNumber(4.0f));

    float x = 5.0f;
    doubleNumber(&x);
    printf("%f\n", x);

    int tab[10];
    fillArr(tab, 10);
    printArr(tab, 10);

    printString("Hello\n");

    printf("%d\n", max(10, 5));

    printf("%d\n", are_equal(5, 5, 5));

    int a = 0;
    plus_100(&a);
    printf("%d\n", a);

    float f1 = 2.0f, f2 = 4.0f;
    my_swap(&f1, &f2);
    printf("%f %f\n", f1, f2);

    printf("%d\n", minOfArr(tab, 10));

    printf("%d\n", num_of_words("Some random sentence."));

    printf("%d\n", fibonacci(5));

    char start[4] = { 'A', 'l', 'a', '\0'};
    printString(my_strcat(start, " ma kota"));

    return 0;
}

/// @brief Definitions:

void printHello()
{
    printf("Hello world!\n");
}

void printManyHello(unsigned int num)
{
    for (int i = 0; i < num; i++)
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

void doubleNumber(float* x)
{
    *x = *x * 2;
}

void fillArr(int* arr, int size)
{
    for (int i = 0; i < size; i++)
        arr[i] = rand();
}

void printArr(const int* array, int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", *(array + i));
    printf("\n");
}

void printString(const char* str)
{
    while (*str)
        putchar(*(str++));
}
