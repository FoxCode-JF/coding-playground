#include "GCD.h"
#include <stdbool.h>
#include <stdio.h>
#include <math.h>

// static bool is_even(int number);

int gcd_euclid_sub(int a, int b)
{
	while(a != b)
	{
		if (a > b)
		{
			a = a - b;
		} else
		{
			b = b - a;
		}
	}
	return a;
}

int gcd_euclid_mod(int a, int b)
{
	if (a % b == 0)
	{
		return b;
	} else
	{
		return gcd_euclid_mod(b, a % b);
	}
}

int gcd_stein(int a, int b)
{
	int exponent = 0;

	while(is_even(a) && is_even(b))
	{
		exponent++;
		a = a / 2;
		b = b / 2;
	}

	while(a != b)
	{
		while(is_even(a))
		{
			a = a / 2;
		}	

		while(is_even(b))
		{
			b = b / 2;
		}

		if (a > b)
		{
			a = a - b;
		} else if (a < b)
		{
			b = b - a;
		}
	}
	return a * pow(2, exponent);
}

bool is_even(int number)
{
	return !(number % 2);
}