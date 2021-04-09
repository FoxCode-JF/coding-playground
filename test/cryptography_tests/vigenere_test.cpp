#include "../catch2/catch.hpp"
#include <stdio.h>
#include <string.h>

extern "C"
{
	#include "../../src/cryptography/my_crypto.h"
}

SCENARIO("Vigenere cipher encrypt and decode")
{
	GIVEN("Text to encrypt and key")
	{
		char* message = "ALGORYTMY";
		char* key = "OKNO";
		char* encrypted_message;

		WHEN("Number not encrypted")
		{
			THEN("encrypt")
			{
				char* expected = "OVTCFIGAM";
				encrypted_message = vigenere_cipher_encrypt(message, key);
				printf("message: %s key: %s encrypted msg: %s.\n", message, key, encrypted_message);

				REQUIRE(strcmp(encrypted_message, expected) == 0);

				WHEN("Number encrypted")
				{
					THEN("Decode")
					{
						char* decoded_message = vigenere_cipher_decode(encrypted_message, key);
						printf("message: %s key: %s decoded msg: %s.\n", message, key, decoded_message);
						REQUIRE(strcmp(message, decoded_message) == 0);
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

				REQUIRE(strcmp(encrypted_message, expected) == 0);

				WHEN("Number encrypted")
				{
					THEN("Decode")
					{
						char* decoded_message = vernam_cipher_decode(encrypted_message, key);
						printf("message: %s key: %s decoded msg: %s\n", message, key, decoded_message);
						REQUIRE(strcmp(message, decoded_message) == 0);
					}
				}
			}
		}		
	}
}