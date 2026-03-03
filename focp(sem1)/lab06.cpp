#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//1. Structures describing(in a 2 - D space) :
//	-point,
//	-square(two points),
//	-circle(point and radius).

struct point
{
	double x, y;
};

struct square
{
	point p1, p2;
};

struct circle
{
	point center;
	double r;
};

struct complex
{
	double re, im;
};

complex add(complex c1, complex c2)
{
	complex res;
	res.re = c1.re + c2.re;
	res.im = c1.im + c2.im;

	return res;
}

complex subtract(complex c1, complex c2)
{
	complex res;
	res.re = c1.re - c2.re;
	res.im = c1.im - c2.im;

	return res;
}

complex multiply(complex c1, complex c2)
{
	complex res;
	res.re = c1.re * c2.re - c1.im * c2.im;
	res.im = c1.re * c2.im + c1.im * c2.re;

	return res;
}

complex divide(complex c1, complex c2)
{
	complex conjugate = c2, res;
	conjugate.im *= -1;
	c1 = multiply(c1, conjugate);
	c2 = multiply(c2, conjugate);

	res.re = c1.re / c2.re;
	res.im = c1.im / c2.re;

	return res;
}

complex create_complex(double re, double im) 
{
	complex res;
	res.re = re;
	res.im = im;
	
	return res;
}

const char* aster(int n) 
{
	static char tab[50];
	int i;
	
	for (i = 0; i < n; i++)
		tab[i] = '*';

	tab[i] = '\0';

	return tab;
}

//2. Functions returning :
//-distance between two points(function parameters : two points),
//-middle point between two points(function parameters : two points),
//-area of a square(function parameter : a square),
//-square with the biggest area(function parameters : two squares),
//-area of a circle(function parameter : a circle).

double dist(point p1, point p2)
{
	return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

point mid_point(point p1, point p2)
{
	point p;
	p.x = (p1.x + p2.x) / 2;
	p.y = (p1.y + p2.y) / 2;

	return p;
}

double sq_area(square sq)
{
	return abs((int)(sq.p1.x - sq.p2.x)) * abs((int)(sq.p1.y - sq.p2.y));
}

square bigger_square(square sq1, square sq2)
{
	return sq_area(sq1) > sq_area(sq2) ? sq1 : sq2;
}

double circle_area(circle c)
{
	return 3.14 * c.r * c.r;
}

//The program should :
//a) Create:
//-an array of N = 1000 (N - defined / constant) points(random values of coordinates),
//-an array of M = 500 squares(coordinates taken from array of pointers),
//-an array of P = 100 circles(centre points from taken from array of pointers, radiuses random),
//b) Call all functions(from point 2) for random points / squares / circles from the arrays.

int main()
{
	#define N 1000
	#define M 500
	#define P 100
	
	srand(time(NULL));

	point points[N];
	square squares[M];
	circle circles[P];

	for (int i = 0; i < N; i++)
	{
		point tmp;
		tmp.x = rand() % 100;
		tmp.y = rand() % 100;
		points[i] = tmp;
	}

	for (int i = 0; i < M-1; i++)
	{
		squares[i].p1 = points[i];
		squares[i].p2 = points[i+500];
	}

	for (int i = 0; i < P; i++)
	{
		circle tmp;
		tmp.center = points[i];
		tmp.r = rand() % 100;
		circles[i] = tmp;
	}

	printf("distance between (%.0f,%.0f) and (%.0f,%.0f) is %.0f\n", points[0].x, points[0].y, points[1].x, points[1].y, dist(points[0], points[1]));
	printf("mid point between (%.0f,%.0f) and (%.0f,%.0f) is (%.0f,%.0f)\n", points[0].x, points[0].y, points[1].x, points[1].y, mid_point(points[0], points[1]).x, mid_point(points[0], points[1]).y);
	printf("area of square [(%.0f,%.0f), (%.0f,%.0f)] is %.0f\n", squares[0].p1.x, squares[0].p1.y, squares[0].p2.x, squares[0].p2.y, sq_area(squares[0]));
	printf("bigger of squares [(%.0f,%.0f), (%.0f,%.0f)] and [(%.0f,%.0f), (%.0f,%.0f)] is [(%.0f,%.0f), (%.0f,%.0f)]\n", squares[0].p1.x, squares[0].p1.y, squares[0].p2.x, squares[0].p2.y, squares[1].p1.x, squares[1].p1.y, squares[1].p2.x, squares[1].p2.y, bigger_square(squares[0], squares[1]).p1.x, bigger_square(squares[0], squares[1]).p1.y, bigger_square(squares[0], squares[1]).p2.x, bigger_square(squares[0], squares[1]).p2.y);
	printf("area of circle [(%.0f,%.0f), %.0f] is %.0f\n", circles[0].center.x, circles[0].center.y, circles[0].r, circle_area(circles[1]));

	
	complex c1, c2;

	c1.re = 2;
	c1.im = 3;
	c2.re = 1;
	c2.im = -1;

	printf("%.2f + %.2fi\n", divide(c1, c2).re, divide(c1, c2).im);

	printf("%s\n", aster(10));

	return 0;
}