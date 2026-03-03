#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

int main()
{
	//1. (0.3) Print all odd numbers from 1 to 100 ("1 3 5 7 ...").
	
	/*for (int i = 1; i <= 100; i += 2)
		printf("%d ", i);

	printf("\n");*/

	//2. (0.2) Define and initialize three integer variables : "start", "stop", and "divisor" (set them to 1, 200, and 5 respectively).
	
	/*int start = 1, stop = 200, divisor = 5*/;

	//3. (0.5) Print all numbers in the range from "start" to "stop" that are divisible by "divisor".

	/*for (int i = start; i <= stop; i++)
		if (i % divisor == 0)
			printf("%d ", i);*/

	//  1. Guessing game.
	//	The program selects a random number(hint: use rand()).Next, it asks the user to try to guess it, displaying hints whether the number is smaller or larger than user’s guess.The program keeps asking until the user guesses(use a loop).Additionally: add a limit on the number of guess attempts(do not **use** break**).

	/*srand(time(NULL));

	int x = rand() % 100;
	int guess;

	while (true)
	{
		printf("Guess a number: ");
		scanf_s("%d", &guess);
		if (guess == x)
		{
			printf("You guessed the number");
			break;
		}
		else if (guess > x)
			printf("The number is lower\n");
		else
			printf("The number is higher\n");
	}*/

	//	2. Define and initialise two integer numbers : base and exponent.Calculate the value base raised to the power of exponent(do not use the "pow" function).Use "break" instead of the usual loop condition.

	/*int base = 2, exponent = 10, result = 1;
	int tmp = exponent;

	while (true)
	{
		if (tmp == 0)
			break;

		result *= base;
		tmp--;
	}

	printf("%d^%d = %d", base, exponent, result);*/

	//	3. Program that guesses a user - invented integer in the range[1, 8].It should use a conditional if statement.Remarks :
	//	a) the program asks many times whether the number is less than some number $k$,
	//	b) depending on the answer('y' or 'n'), the program determines k for the next question or ends its operation(incorrect answer or guessed number),
	//	c) the program should ask as few questions as possible.


	/*char answer = ' ';

	printf("Is the number less than 5? ");
	scanf_s(" %c", &answer);
	if (answer == 'y') //1234
	{
		printf("Is the number less than 3? ");
		scanf_s(" %c", &answer);
		if (answer == 'y') //12
		{
			printf("Is the number less than 2? ");
			scanf_s(" %c", &answer);
			if (answer == 'y') //1
			{
				printf("Your number is 1");
			}
			else //2
			{
				printf("Your number is 2");
			}
		}
		else //34
		{
			printf("Is the number less than 4? ");
			scanf_s(" %c", &answer);
			if (answer == 'y') //3
			{
				printf("Your number is 3");
			}
			else //4
			{
				printf("Your number is 4");
			}
		}
	}
	else //5678
	{
		printf("Is the number less than 7? ");
		scanf_s(" %c", &answer);
		if (answer == 'y') //56
		{
			printf("Is the number less than 6? ");
			scanf_s(" %c", &answer);
			if (answer == 'y') //5
			{
				printf("Your number is 5");
			}
			else //6
			{
				printf("Your number is 6");
			}
		}
		else //78
		{
			printf("Is the number less than 8? ");
			scanf_s(" %c", &answer);
			if (answer == 'y') //7
			{
				printf("Your number is 7");
			}
			else //8
			{
				printf("Your number is 8");
			}
		}
	}*/

	//	4. Average, minimum, maximum, standard deviation.
	//	The program reads numbers from the user. The user must provide at least one number. Before asking for each subsequent number, the program should ask, whether it is the end of entering numbers. After entering the numbers, the program should display:
	//  -the number of entered numbers,
	//	-average of the entered numbers,
	//	-the minimum of the entered numbers,
	//	-the maximum of the entered numbers

	/*int count = 0, max = 0, min = INT_MAX, sum = 0;
	int input;
	char con;

	do
	{
		printf("Provide the number: ");
		scanf_s("%d", &input);
		
		if (input > max)
			max = input;
		if (input < min)
			min = input;

		count++;
		sum += input;

		printf("Do you want to continue(y/n)?: ");
		scanf_s(" %c", &con);
	} while (con != 'n');

	printf("Number of entered numbers: %d \nAverage of entered numbers: %d \nMinimum of entered numbers: %d \nMaximum of entered numbers: %d", count, sum/count, min, max);*/

	//	5. Equation solver for ax + b = c.Values a, b, and c can be hard - coded.

	/*double a = 2.0, b = -5.0, c = 10.0;

	printf("%.2f", (c - b) / a);*/

	//	-- -

	//	TASKS RELATED TO THE TOPICS COVERED SO FAR :

	//*COLLATZ CONJECTURE.Consider the following operation on an arbitrary
	//	positive integer :
	//-If the number is even, divide it by two.
	//	- If the number is odd, triple it and add one.
	//	Now form a sequence by performing this operation repeatedly.The Collatz
	//	conjecture states that the sequence will always reach 1, regardless of the
	//	initial number.However, this has not been proven.Check whether this is
	//	true for natural numbers from 1 to 100. For each, print the resulting
	//	sequence.

	/*int num;

	for (int i = 1; i <= 100; i++)
	{
		num = i;
		while (num > 1) {
			if (num % 2 == 0)
				num /= 2;
			else
				num = 3 * num + 1;
			printf("%d ", num);
		}
		printf("\n");
	}*/

	//	* APPROXIMATING _PI_.Suppose we can only perform addition, subtraction,
	//	multiplication, and division on real numbers.Write a program that uses
	//	these operations to approximate _Pi_ using Machin's formula
	//	(https://en.wikipedia.org/wiki/Machin-like_formula [1]):
	//[Pi = (16 / 5 - 4 / 239) - (1 / 3) * (16 / (5 ^ 3) - 4 / (239 ^ 3)) + (1 / 5) * (16 / (5 ^ 5) - 4 / (239 ^ 5)) -
	//	... .]

	double Pi = (16.0 / 5.0 - 4.0 / 239.0);
	bool next_pos = false;

	for (int i = 3; i < 100; i += 2)
		if (next_pos)
		{
			Pi += (1.0 / i) * (16.0 / pow(5.0, i) - 4.0 / pow(239.0, i));
			next_pos = false;
		}
		else
		{
			Pi -= (1.0 / i) * (16.0 / pow(5.0, i) - 4.0 / pow(239.0, i));
			next_pos = true;
		}

	printf("%.10f", Pi);

	//	* FIXED - POINT ARITHMETIC(not obligatory, for programming enthusiasts).
	//	Using the "_double_" type, in the previous problem we get an accuracy of
	//	about 16 significant digits(we should get _Pi_ =
	//		3.14159265358979323846264338...).Is it possible to get a better
	//	approximation using only integer calculations(_long long int_) ?



	//	*NUMERICAL INTEGRATION.Write a program that approximates the integral of
	//	a function using the rectangle method :
	//-Calculate ∫(_x_² + 2_x_ + 1) _dx_ from 0 to 5;
	//-Divide the interval[0, 5] into _n_ subintervals;
	//-Use the left - endpoint, right - endpoint, and midpoint methods;
	//-Compare the results with the exact value(analytical solution);
	//-Show how the approximation improves as _n_ increases.




	return 0;
}