#include "GCD.h"
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <math.h>


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

uint64_t gcd_euclid_mod(uint64_t a, uint64_t b)
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

uint64_t gcd_euclid_extended(uint64_t a, uint64_t b, int64_t* x, int64_t* y)
{
    // Base Case
    if (a == 0)
    {
        *x = 0, *y = 1;
        return b;
    }
 
    int64_t x1, y1; // To store results of recursive call
    uint64_t gcd = gcd_euclid_extended(b % a, a, &x1, &y1);
 
    // Update x and y using results of recursive
    // call
    *x = y1 - (b / a) * x1;
    *y = x1;
 
    return gcd;
}

bool is_even(int number)
{
	return !(number % 2);
}
