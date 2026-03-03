#include <iostream>

using namespace std;

int main()
{
	//1. Write a program printing in a single line all integers from 1 to some N (hard coded value). Do it two ways: using "while", "do...while" and "for". Next print the numbers in revers order. Example output (for N=3):
	//
	//while: 1 2 3
	//do..while: 1 2 3
	//for: 1 2 3
	//
	//while: 3 2 1
	//do..while: 3 2 1
	//for: 3 2 1
	//
	
	int N = 4;
	int i = 1;

	cout << "while: ";
	while (i <= N) 
	{
		cout << i << " ";
		i++;
	}

	i = 1;
	cout << endl << "do...while: ";
	do 
	{
		cout << i << " ";
		i++;
	} while (i <= N);

	cout << endl << "for: ";
	for (i = 1; i <= N; i++)
	{
		cout << i << " ";
	}

	i = N;

	cout << endl << "while: ";
	while (i > 0)
	{
		cout << i << " ";
		i--;
	}

	i = N;
	cout << endl << "do...while: ";
	do
	{
		cout << i << " ";
		i--;
	} while (i > 0);

	cout << endl << "for: ";
	for (i = N; i > 0; i--)
	{
		cout << i << " ";
	}

	//2. Write a program printing the ASCII table (hexadecimal code, decimal code, the character) from the code 32 to 126; run it and place the result in a text file (you will have to redirect the output).
	//Example:
	//20 32
	//21 33 !
	//22 34
	//23 35 #
	//24 36 $
	//...

	cout << endl;
	
	for (i = 32; i <= 126; i++)
	{
		cout << hex << i << " " << dec << i << " " << (char)i << endl;
	}

	//3. Evaluate the following expressions (and similar) “on paper”. Then check your results (write the code).
	//
	//2+2.7
	//4/7
	//4.0/7
	//7%2
	//3+5%5*2
	//5>2+6<3
	//6==2+3!=4
	
	cout << 2 + 2.7 << " "; // 4.7
	cout << 4 / 7 << " "; // 0
	cout << 4.0 / 7 << " "; // 0.52...
	cout << 7 % 2 << " "; // 1
	cout << 3 + 5 % 5 * 2 << " "; // 3
	cout << ((5 > (2 + 6)) < 3) << " "; // true
	cout << ((6 == (2 + 3)) != 4) << endl; // true

	//4. Write a program checking, whether an integer (hard coded) is a prime number.
	//Use the % operator. For example, 11%3 is 2 and 12%3 is 0; it means, that 3 is a divisor of 12. A prime number _n_ has EXACTLY TWO divisors: 1 and _n_ (we do not treat 1 as a prime number).
	
	N = 25;
	bool con = true;

	if (N < 1)
		con = false;
	else 
	{
		for (i = 2; i * i <= N; i++)
		{
			if (N % i == 0)
			{
				con = false;
				break;
			}
		}
	}

	if (con)
		cout << N << " is a prime number" << endl;
	else
		cout << N << " is NOT a prime number" << endl;

	//5. Check, whether the number 6321246989923 is prime or not. If not, find its factorization (represent as a product of prime numbers).
	//Hint: this is a big number, which does not fit into 32 bits (a normal _int _type). But
	//you may use _long long int_ to store very big integers and "%lld" (there
	//are TWO lowercase letters L) to print them. You may use a suffix "LL" to
	//ensure, that the vaule is treated as a very long integer (but in case of
	//such a big number, the compiler will treat it as _long long int_ even
	//without LL):
	// _long long int n;__
	//_ n = 6321289474823LL;_
	//_ printf("%lld\n", n);
	
	long long num = 6321246989923;
	con = true;

	if (num < 1)
		con = false;
	else
	{
		for (i = 2; i * i <= num; i++)
		{
			if (num % i == 0)
			{
				con = false;
				break;
			}
		}
	}

	if (con)
		cout << num << " is a prime number" << endl;
	else
	{
		cout << num << " is NOT a prime number" << endl;

		long long tmp_num = num;
		long long div = 2;

		cout << "Factors of " << num << ": " << 1 << " ";

		while (tmp_num > 1)
		{
			if (tmp_num % div == 0)
			{
				cout << div << " ";
				tmp_num /= div;
			}
			else
				div++;
		}

		cout << num << endl;
	}

	//6. Write w program printing a multiplication table (use hexadecimal format) up to 16. It should be properly formatted. Example:
	//
	//    |   1   2   3   4   5   6   7   8   9   a   b   c   d   e   f  10
	//---------------------------------------------------------------------
	//   1|   1   2   3   4   5   6   7   8   9   a   b   c   d   e   f  10
	//   2|   2   4   6   8   a   c   e  10  12  14  16  18  1a  1c  1e  20
	//   3|   3   6   9   c   f  12  15  18  1b  1e  21  24  27  2a  2d  30
	//   4|   4   8   c  10  14  18  1c  20  24  28  2c  30  34  38  3c  40
	//   5|   5   a   f  14  19  1e  23  28  2d  32  37  3c  41  46  4b  50
	//   6|   6   c  12  18  1e  24  2a  30  36  3c  42  48  4e  54  5a  60
	//   7|   7   e  15  1c  23  2a  31  38  3f  46  4d  54  5b  62  69  70
	//   8|   8  10  18  20  28  30  38  40  48  50  58  60  68  70  78  80
	//   9|   9  12  1b  24  2d  36  3f  48  51  5a  63  6c  75  7e  87  90
	//   a|   a  14  1e  28  32  3c  46  50  5a  64  6e  78  82  8c  96  a0
	//   b|   b  16  21  2c  37  42  4d  58  63  6e  79  84  8f  9a  a5  b0
	//   c|   c  18  24  30  3c  48  54  60  6c  78  84  90  9c  a8  b4  c0
	//   d|   d  1a  27  34  41  4e  5b  68  75  82  8f  9c  a9  b6  c3  d0
	//   e|   e  1c  2a  38  46  54  62  70  7e  8c  9a  a8  b6  c4  d2  e0
	//   f|   f  1e  2d  3c  4b  5a  69  78  87  96  a5  b4  c3  d2  e1  f0
	//  10|  10  20  30  40  50  60  70  80  90  a0  b0  c0  d0  e0  f0 100
	
	int j, k = 1;

	cout << " |\t";

	for (i = 1; i < 17; i++)
		cout << hex << i << "\t";

	cout << endl;

	for (i = 1; i < 19 * 7; i++)
		cout << "_";

	cout << endl;

	for (i = 1; i < 17; i++)
	{
		cout << k << "|\t";
		k++;
		for (j = 1; j < 17;j++)
		{
			cout << hex << j * i << "\t";
		}

		cout << endl;
	}

	//with printf
	/*
		int i, j, k = 1;

		printf("%4s|", ""); 
	
		for (i = 1; i <= 16; i++)
			printf("%4x", i); 
	
		printf("\n");
	
		for (i = 1; i <= 16 * 4 + 5; i++)
			printf("-"); 
	
		printf("\n");
	
		for (i = 1; i <= 16; i++)
		{
			printf("%4x|", k); 
			k++;
			for (j = 1; j <= 16;j++)
			{
			printf("%4x", j*i);
			}
	
			printf("\n");
		}
	*/

	//7. Write a program computing the square root of 1000 and print the result
	//on the screen.
	//Do NOT use the _sqrt_ function, but use an ITERATIVE
	//formula: x1 = 1000; xi+1 = (xi + 1000 / xi )/2. Stop when the precision
	//satisfies you (e.g. the error is less than 0.001).

	double x = 1000.0;
	double xi = 1000.0;
	do {
		x = xi;
		xi = (x + 1000 / x) / 2;
	} while (x - xi > 0.001);

	cout << "Square root of 1000 is " << x << endl;

	return 0;
}

