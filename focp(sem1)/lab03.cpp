#include <stdio.h>

int main()
{
	//int x = 21 & 13; 
	///*
	//10101 
	//01101
	//00101 = 5
	//*/
	//printf("%d\n", x);
	//x = 4 | 22 > 3;
	///*
	//100
	//001 22 > 3
	//101 = 5
	//*/
	//printf("%d\n", x);
	//x = 4 || 22 > 3;
	///*
	//1
	//*/
	//printf("%d\n", x);
	//x = 1 << 4;
	///*
	//10000 = 16
	//*/
	//printf("%d\n", x);
	//x = ~15;
	///*
	//01111
	//10000 = -16
	//*/
	//printf("%d\n", x);
	//x = 54 ^ 33;
	///*
	//110110
	//100001
	//010111 = 23
	//*/
	//printf("%d\n", x);
	//x = 8 >> 2 | 10 << 4;
	///*
	//00000010
	//10100000
	//10100010 = 162
	//*/
	//printf("%d\n", x);
	//x = 3 + 8 > 6 ^ 4;
	///*
	//11 > 6 = 1
	//001
	//100
	//101 = 5
	//*/
	//printf("%d\n", x);
	//x = !3 > 4 | 8 + 5;
	///*
	//0 > 4 = 0
	//0 | 13 = 13
	//*/
	//printf("%d\n", x);
	//x = ~3 > -4 && 5 < 10;
	///*
	//~3 = -4
	//-4 > -4 = 0
	//0
	//*/
	//printf("%d\n", x);
	//int a = 5, b = 3, c = 2, d = 8;
	//int result1 = a + b * c - d / c % b;
	///*
	//5 + 6 - 1 = 10
	//*/
	//printf("%d\n", result1);
	//int result2 = !a & b | c ^ ~d;
	///*
	//00000 = !a & b
	//01000 = 8
	//10111 = -16 + 7 = -9
	//00010
	//10111
	//10101 = -16 + 5 = -11
	//*/
	//printf("%d\n", result2);
	//int result3 = a++ + --b * c;
	///*
	//5 + 2 * 2 = 9
	//*/
	//printf("%d\n", result3);
	//int result4 = a > b && c < d || !b;
	///*
	//6 > 2 && 2 < 8 = 1
	//*/
	//printf("%d\n", result4);

	/*int in;

	printf("enter the number: ");
	scanf_s(" %d", &in);

	if (in % 2 == 0 && in > 5 && in < 105 || in % 2 == 1 && in > 50 && in < 500)
		printf("a condition is true");
	if (in % 3 == 0 && in > 500 && in % 2 != 0)
		printf("b condition is true");
	if (in >= 100 && (3&in) == 0)
		printf("c condition is true");*/

	int in = 10;
	int mask = 0b10000000;

	for (int i = 7; i >= 0; i--)
	{
		int res = in & mask;
		mask >>= 1;
		printf("%d", res>>i);
	}



	return 0;
}