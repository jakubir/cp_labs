/*
 GROUP A

 Write a function that checks whether an integer is a palindrome - that
 is, whether rewriting its decimal digits in reverse order yields the same
 number. For example, the numbers 314151413 and 956659 are palindromes, but
 neither 234234 nor 2718 are. Then, copy the palindrome numbers from a file
 "numbers.txt" containing integer numbers to another file "palindromes.txt".
 */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

bool is_palindrome(int num)
{
	int reverse = 0, copy = num;

	while (copy > 0)
	{
		reverse *= 10;
		reverse += copy % 10;
		copy /= 10;
	}

	if (reverse != num)
		return false;

	return true;
}

/*
 GROUP B

 The file "matrix.csv" contains a matrix of real numbers with size 10 *
 10 elements. Subsequent numbers are separated by commas. Write a program
 that creates a file "transposed.csv", with the transposition of this
 matrix.
 */

/*
1,0,0,0,0,0,0,0,0,0,
1,0,0,0,0,0,0,0,0,0,
1,0,0,0,0,0,0,0,0,0,
1,0,0,0,0,0,0,0,0,1,
1,0,0,0,0,0,0,0,0,0,
1,0,0,0,0,0,0,0,0,0,
1,0,0,0,0,0,0,0,0,0,
1,0,0,0,0,0,0,0,0,0,
1,0,0,0,0,0,0,0,0,0,
1,0,0,0,0,0,0,0,0,0,
*/

bool matrix_transposition()
{
	FILE* in_file = fopen("matrix.csv", "r");

	if (!in_file)
		return false;

	int matrix[10][10];
	int num = 0;

	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
		{
			fscanf(in_file, "%d,", &num);
			matrix[i][j] = num;
		}

	fclose(in_file);


	FILE* out_file = fopen("transposed.csv", "w");

	if (!out_file)
		return false;

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
			fprintf(in_file, "%d,", matrix[j][i]);

		fprintf(in_file, "\n");
	}

	fclose(out_file);


	return true;
}

int main()
{
	FILE *in_file = fopen("numbers.txt", "r");
	FILE *out_file = fopen("palindromes.txt", "w");

	if (!in_file || !out_file)
		return false;

	int num;

	while (fscanf(in_file, "%d", &num) != EOF)
		if (is_palindrome(num))
			fprintf(out_file, "%d\n", num);

	fclose(in_file);
	fclose(out_file);

	matrix_transposition();

	return 0;
}