#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define N 10

int main()
{
	//	1.1 Declare an array of N characters and fill it with values from 0 to N - 1.

		//int tab[N];

		//for (int i = 0; i < N; i++)
		//	tab[i] = i;

	//	1.2 Read N integers from the user, store them in an array, print them in reverse order.To simplify the solution, you may use C++ streams(_cin_, _cout_).

		//int tab[N];
		//int input;

		//for (int i = 0; i < N; i++)
		//{
		//	printf("Enter a number: ");
		//	scanf_s("%d", &input);
		//	tab[i] = input;
		//}

		//for (int i = N - 1; i >= 0; i--)
		//	printf("%d ", tab[i]);

	//	1.3 Array for ASCII characters
	//	Write a program counting the number of occurrences of letters a - z and
	//	A - Z in the input stream.Uppercase and lowercase letters should NOT be
	//	distinguished.Use getchar() function.

		 //int tab[26] = {0};
		 //int ch;
		 //while ((ch = getchar()) != EOF)
		 //    if (ch >= 'a' and ch <= 'z')
		 //        tab[ch-'a']++;
		 //    else if (ch >= 'A' and ch <= 'Z')
		 //        tab[ch-'A']++;

		 //for (int i = 0; i < 26; i++)
		 //    printf("%d ", tab[i]);

	//	1.4 Finding the minimum element + selection sort
	//	a) Declare an array of N integers and fill it with random numbers[hint:use rand() % 100]
	//	b) Find the minimum element in the array.
	//	c)* Swap the minimum element with the first element of the array.
	//	d)* Sort the entire array by repeating steps b and c for the unsorted portion of the array.

		//int tab[N];

		//srand(time(NULL));

		//for (int i = 0; i < N; i++) {
		//	tab[i] = rand() % 100;
		//	printf("%d ", tab[i]);
		//}
		//printf("\n");

		//for (int i = 0; i < N; i++)
		//{
		//	int min = tab[i];
		//	int min_index = i;
		//	int j;

		//	for (j = i+1; j < N; j++)
		//		if (tab[j] < min)
		//		{
		//			min = tab[j];
		//			min_index = j;
		//		}

		//	tab[min_index] = tab[i];
		//	tab[i] = min;
		//}

		//for (int i = 0; i < N; i++)
		//	printf("%d ", tab[i]);

	//	1.5 * Array for text, null terminator.
	//	Write a program that copies a text file from stdin to stdout so that each line of text is written twice.Use getchar to read single characters and an array to store a single line of text.Print one copy of the line using putchar and the other using printf.You may assume that the length of a text line does not exceed 100 characters.

		//int c = 0, ch, tab[100];

		//while ((ch = getchar()))
		//{
		//	if (ch == EOF || ch == '\n' || c + 1 % 100 == 0)
		//	{
		//		printf("\n");

		//		for (int i = 0; i < c; i++)
		//			printf("%c", (char)tab[i]);

		//		if (ch == EOF)
		//			break;

		//		c = 0;

		//		printf("\n");
		//	}
		//	else {
		//		putchar(ch);
		//		tab[c++] = ch;
		//	}
		//}

	//	1.6 * Find all prime numbers in the range from 2 to 200 using so called _Sieve
	//	of Eratosthenes_ : from the initial set of all numbers 2 - 200 remove
	//	multiples of 2 exept 2; mark the smallest remaining number as prime and
	//	remove all other multiples of it; continue until the square of the
	//	processed number is bigger than 200 and mark all remaining numbers as
	//	prime.

		//bool tab[201] = { 0 };

		//for (int i = 2; i < 201; i++)
		//	tab[i] = 1;

		//for (int i = 2; i * i < 200; i++)
		//{
		//	if (tab[i] == 0)
		//		continue;

		//	for (int j = i + i; j <= 200; j += i)
		//		tab[j] = 0;
		//}

	//	2.1 Declare a 2D array(size 10x10), fill it with multiplication table and print it.

		//int tab[10][10];

		//for (int i = 0; i < 10; i++)
		//{
		//	for (int j = 0; j < 10; j++)
		//	{
		//		tab[i][j] = (i + 1) * (j + 1);
		//		printf("%4d", tab[i][j]);
		//	}
		//	printf("\n");
		//}

		//printf("\n");

	//	2.2 * Declare a 2D array(size MxN) and fill it according to the below patterns

	//	0 0 0 0 0
	//	1 1 1 1 1
	//	2 2 2 2 2
	//	3 3 3 3 3

		//#define M 4
		//#define N 5

		//int tab2[M][N];

		//for (int i = 0; i < M; i++)
		//{
		//	for (int j = 0; j < N; j++)
		//	{
		//		tab2[i][j] = i;
		//		printf("%2d", tab2[i][j]);
		//	}
		//	printf("\n");
		//}

		//printf("\n");


	//	0 1 2 3 4
	//	0 1 2 3 4
	//	0 1 2 3 4
	//	0 1 2 3 4

		//for (int i = 0; i < M; i++)
		//{
		//	for (int j = 0; j < N; j++)
		//	{
		//		tab2[i][j] = j;
		//		printf("%2d", tab2[i][j]);
		//	}
		//	printf("\n");
		//}

		//printf("\n");


	//	0 1 0 1 0
	//	1 0 1 0 1
	//	0 1 0 1 0
	//	1 0 1 0 1
	//	0 1 0 1 0

		//for (int i = 0; i < M; i++)
		//{
		//	for (int j = 0; j < N; j++)
		//	{
		//		tab2[i][j] = (j+i) % 2 == 1;
		//		printf("%2d", tab2[i][j]);
		//	}
		//	printf("\n");
		//}

		//printf("\n");

	//	0 0 0 0 0
	//	1 1 1 1 1
	//	0 0 0 0 0
	//	1 1 1 1 1
	//	0 0 0 0 0

		//for (int i = 0; i < M; i++)
		//{
		//	for (int j = 0; j < N; j++)
		//	{
		//		tab2[i][j] = i % 2;
		//		printf("%2d", tab2[i][j]);
		//	}
		//	printf("\n");
		//}

	//	2.3 *
	//	Declare a 2D array of size NxN and fill it according to the below pattern(take care of even and odd N).

	//	 1  2  3  4  5  6
	//	20 21 22 23 24  7
	//	19 32 33 34 25  8
	//	18 31 36 35 26  9
	//	17 30 29 28 27 10
	//	16 15 14 13 12 11

	//  1  2  3
	//  8  9  4
    //  7  6  5

		#define N 6

		int tab[N][N];

	return 0;
}