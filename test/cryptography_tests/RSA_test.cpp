#include "../catch2/catch.hpp"

extern "C"
{
	#include "../../src/cryptography/RSA_cipher.h"
	#include <stdint.h>
	#include <stdio.h>
}

SCENARIO("Vernam cipher encrypt and decode")
{
	GIVEN("Message to send and two prime numbers p and q")
	{
		uint64_t message = 12;
		uint64_t p = 11;
		uint64_t q = 31;

		WHEN("RSA public and private key initialized")
		{
			RSA_init(p, q);
			uint64_t private_key = get_private_key();
			uint64_t public_key = get_public_key();
			uint64_t n = p * q;

			printf("public: %ld, private: %ld\n", public_key, private_key);
			
			THEN("encrypt")
			{
				uint64_t expected = 123;
				uint64_t encrypted_message = RSA_encrypt(message, n, public_key);
				printf("message: %ld, public_key: %ld encrypted msg: %ld\n", message, public_key, encrypted_message);


				WHEN("Number encrypted")
				{
					THEN("Decode")
					{
						uint64_t decoded_message = RSA_decrypt(encrypted_message, n, private_key);
						printf("message: %ld private_key: %ld decoded msg: %ld\n", message, private_key, decoded_message);
						REQUIRE(decoded_message == message);
					}
				}
			}
		}	
	}
}