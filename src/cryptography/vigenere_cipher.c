#include "my_crypto.h"
#include <math.h>
#include <ctype.h>
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *vigenere_cipher_encrypt(const char *message, const char *key)
{
	int key_len = strlen(key);
	int msg_len = strlen(message);

	char* encoded_message;
	int* corresponding_number_message;
	int* corresponding_number_key;
	int modulo = 'Z' - 'A' + 1;

	corresponding_number_message = malloc(sizeof(int) * msg_len);
	corresponding_number_key = malloc(sizeof(int) * msg_len);
	encoded_message = calloc(msg_len + 1, sizeof(char));

	for (int i = 0; i < msg_len; ++i)
	{
		corresponding_number_message[i] = toupper(message[i]) - 'A';
		corresponding_number_key[i] = toupper(key[i % key_len]) - 'A';
		encoded_message[i] = ((corresponding_number_message[i] + corresponding_number_key[i]) % modulo) + 'A';
	}

	free(corresponding_number_key);
	free(corresponding_number_message);

	return encoded_message;
}

char *vigenere_cipher_decode(const char *message, const char *key)
{
	int key_len = strlen(key);
	int msg_len = strlen(message);

	char* encoded_message;
	int* corresponding_number_message;
	int* corresponding_number_key;
	int modulo = 'Z' - 'A' + 1;

	corresponding_number_message = malloc(sizeof(int) * msg_len);
	corresponding_number_key = malloc(sizeof(int) * msg_len);
	encoded_message = calloc(msg_len + 1, sizeof(char));

	for (int i = 0; i < msg_len; ++i)
	{
		corresponding_number_message[i] = toupper(message[i]) - 'A';
		corresponding_number_key[i] = toupper(key[i % key_len]) - 'A';
		encoded_message[i] = my_modulo((corresponding_number_message[i] - corresponding_number_key[i]), modulo) + 'A';
		printf("encoded_message: %s, length: %d\n", encoded_message, (int)strlen(encoded_message));
	}

	free(corresponding_number_key);
	free(corresponding_number_message);

	return encoded_message;
}