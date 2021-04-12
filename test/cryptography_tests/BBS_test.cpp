#include "../catch2/catch.hpp"
#include <stdint.h>
#include <stdio.h>

extern "C"
{
	#include "../../src/cryptography/my_crypto.h"
	#include <openssl/bn.h>
	#include <string.h>
}


SCENARIO("test BSS random number generator")
{
	GIVEN("Two prime numbers and seed")
	{
		uint64_t p = 7;
		uint64_t q = 11;
		uint64_t seed = 5;

		THEN("Calculate pseudo random number")
		{
			char * random_number = rand_BBS(seed, p, q, 5);
			printf("random_number: %s\n", random_number);
			REQUIRE(strcmp(random_number, "19") == 0);
		}
	}
}