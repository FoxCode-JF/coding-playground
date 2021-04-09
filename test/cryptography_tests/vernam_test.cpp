#include "../catch2/catch.hpp"
#include <stdio.h>

extern "C"
{
	#include "../../src/cryptography/my_crypto.h"
}

SCENARIO("Vernam cipher encrypt and decode")
{
	GIVEN("Number to encrypt and key")
	{
		int number = 134782021;
		int key = 123456789;
		int encrypted_message;

		WHEN("Number not encrypted")
		{
			THEN("encrypt")
			{
				int expected = 257118544;
				encrypted_message = vernam_cipher(number, key);
				printf("number: %d key: %d encrypted msg: %d\n", number, key, encrypted_message);
				REQUIRE(expected == encrypted_message);

				WHEN("Number encrypted")
				{
					THEN("Decode")
					{
						int decoded_message = vernam_cipher(encrypted_message, key);
						printf("number: %d key: %d decoded msg: %d\n", number, key, decoded_message);
						REQUIRE(decoded_message == number);
					}
				}
			}
		}	
	}
}