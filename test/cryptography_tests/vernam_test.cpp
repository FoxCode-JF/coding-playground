#include "../catch2/catch.hpp"
#include <stdio.h>
#include <string.h>

extern "C"
{
	#include "../../src/cryptography/my_crypto.h"
}

// SCENARIO("Vernam cipher encrypt and decode")
// {
// 	GIVEN("Number to encrypt and key")
// 	{
// 		int number = 134782021;
// 		int key = 123456789;
// 		int encrypted_message;

// 		WHEN("Number not encrypted")
// 		{
// 			THEN("encrypt")
// 			{
// 				int expected = 257118544;
// 				encrypted_message = vernam_cipher(number, key);
// 				printf("number: %d key: %d encrypted msg: %d\n", number, key, encrypted_message);
// 				REQUIRE(expected == encrypted_message);

// 				WHEN("Number encrypted")
// 				{
// 					THEN("Decode")
// 					{
// 						int decoded_message = vernam_cipher(encrypted_message, key);
// 						printf("number: %d key: %d decoded msg: %d\n", number, key, decoded_message);
// 						REQUIRE(decoded_message == number);
// 					}
// 				}
// 			}
// 		}	
// 	}
// }

SCENARIO("Vernam cipher encrypt and decode")
{
	GIVEN("Number to encrypt and key")
	{
		char* message = "BLABLA";
		char* key = "SWINKE";
		char* encrypted_message;

		WHEN("Number not encrypted")
		{
			THEN("encrypt")
			{
				char* expected = "THIOVE";
				encrypted_message = vernam_cipher_encrypt(message, key);
				printf("message: %s key: %s encrypted msg: %s\n", message, key, encrypted_message);

				REQUIRE(strncmp(encrypted_message, expected, 6) == 0);

				WHEN("Number encrypted")
				{
					THEN("Decode")
					{
						char* decoded_message = vernam_cipher_decode(encrypted_message, key);
						printf("message: %s key: %s decoded msg: %s\n", message, key, decoded_message);
						REQUIRE(strncmp(message, decoded_message, 6) == 0);
					}
				}
			}
		}	
	}
}