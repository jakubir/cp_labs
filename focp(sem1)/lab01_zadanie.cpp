//Write a complete C program that outputs a conversion table from kilograms(kg) to stones(st)
//and pounds(lb) for every second integer value of kilogram in the range from 50 to 100. Use while
//or for loop.Stones should be integers.Output one decimal place for values of pounds.Assume
//that : 1 lb = 0.4536 kg, 1 st = 14 lb.
//Example output(for the beginning of the range) :
//	50 kg = 7 st 12.2 lb
//	52 kg = 8 st 2.6 lb
//	54 kg = 8 st 7.0 lb

#include <stdio.h>

int main()
{
	int kg;
	float st, lb;

	for (kg = 50; kg <= 100; kg+=2)
	{
		lb = kg / 0.4536;
		st = 0.0;

		while (lb > 14) {
			st++;
			lb -= 14;
		}

		printf("%d kg = %.0f st %.1f lb \n", kg, st, lb);
	}

	return 0;
}