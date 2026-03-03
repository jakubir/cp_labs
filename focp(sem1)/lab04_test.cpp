//TEST A

#include <stdio.h>
#define N 12

int main()
{

	// [1] (0.3 points) Declare an array of N characters

	char array[N];


	// [2] (0.3 points) Read a single character from standard input (use getchar)

	int ch;
	ch = getchar();


	// [3] (0.4 points) If the read character is an uppercase letter (A-Z), fill the entire array with that letter.

	if (ch >= 'A' && ch <= 'Z')
		for (int i = 0; i < N; i++)
			array[i] = ch;

	return 0;
}
