#include "../catch2/catch.hpp"
#include <stdio.h>
#include <string.h>

extern "C"
{
	#include "../../src/cryptography/my_crypto.h"
}

SCENARIO("Vernam cipher encrypt and decode")
{
	GIVEN("Text to encrypt and key")
	{
		char* message = "BLABLA";
		char* key = "SWINKE";
		char* encrypted_message;

		WHEN("Single word not encrypted")
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

		WHEN("Sentence not encrypted")
		{
			THEN("encrypt")
			{
				message = "I like trains";
				char* expected = "THIOVE";
				encrypted_message = vernam_cipher_encrypt(message, key);
				printf("message: %s key: %s encrypted msg: %s\n", message, key, encrypted_message);

				REQUIRE(strncmp(encrypted_message, expected, 6) == 0);

				WHEN("Message encrypted")
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