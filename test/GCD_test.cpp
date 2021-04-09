#include "catch2/catch.hpp"
#include <stdio.h>

extern "C"
{
	#include "../src/GreatestCommonDivisor/GCD.h"
}



SCENARIO("Test algorithms to calculate greatest common divisor")
{
	GIVEN("Two numbers a and b")
	{
		int a = 123568;
		int b = 13402;
		int a_b_gcd = 2;
		WHEN("Algorithm used is euclid algorithm implemented in a loop using subtraction")
		{
			THEN("calculate greatest common divisor of a and b")
			{
				int result = gcd_euclid_sub(a, b);
				REQUIRE(result == a_b_gcd);
			}
		}

		WHEN("Algorithm used is euclid algorithm implemented with recursion using modulo operator")
		{
			THEN("calculate greatest common divisor of a and b")
			{
				int result = gcd_euclid_mod(a, b);
				REQUIRE(result == a_b_gcd);
			}
		}

		WHEN("Algorithm used is stein algorithm")
		{
			THEN("calculate greatest common divisor of a and b")
			{
				int result = gcd_stein(a, b);

				REQUIRE(result == a_b_gcd);
			}
		}
	}
}