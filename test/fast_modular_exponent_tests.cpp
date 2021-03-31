#include "catch2/catch.hpp"
#include <stdint.h>

extern "C"
{
	#include "../src/fastModularExponent/fast_modular_exponent.h"
	#include <time.h>
	#include <stdlib.h>
	#include <cstring>
}

// TODO: Implement 

SCENARIO("Modular exponent calculations for different data")
{
	GIVEN("Base, exponent and modulo numbers")
	{
		uint64_t base = 9, exponent, modulo; 
		int mod_exp;
		
		WHEN("Modulo and exponent are equal to 10")
		{
			exponent = 10;
			modulo = 10;
			THEN("Calculate modular exponent")
			{
				mod_exp = modular_exponent(base, exponent, modulo);			
				REQUIRE(mod_exp == 1);
			}
		}

		WHEN("Modulo and exponent are equal to 20")
		{
			exponent = 20;
			modulo = 20;
			
			THEN("Calculate modular exponent")
			{
				mod_exp = modular_exponent(base, exponent, modulo);			
				REQUIRE(mod_exp == 1);
			}		
		}

		WHEN("Modulo and exponent are equal to 50")
		{
			exponent = 50;
			modulo = 50;
			
			THEN("Calculate modular exponent")
			{
				mod_exp = modular_exponent(base, exponent, modulo);
				REQUIRE(mod_exp == 1);
			}
		}
		
		WHEN("Modulo and exponent are equal to 100")
		{
			exponent = 100;
			modulo = 100;
			
			THEN("Calculate modular exponent")
			{
				mod_exp = modular_exponent(base, exponent, modulo);			
				REQUIRE(mod_exp == 1);
			}
		}
	}
}