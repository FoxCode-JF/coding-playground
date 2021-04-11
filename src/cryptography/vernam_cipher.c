#include "my_crypto.h"
#include <math.h>
#include <ctype.h>
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *vernam_cipher_encrypt(const char *message, const char *key)
{
	int key_len = strlen(key);
	int msg_len = strlen(message);

	char* encoded_message;
	int* corresponding_number_message;
	int* corresponding_number_key;
	int modulo = 'Z' - 'A' + 1;

	if (msg_len != key_len)
	{
		fprintf(stderr, "%s\n", "Key length has to be the same as message length!");
		return NULL;
	}

	corresponding_number_message = malloc(sizeof(int) * msg_len);
	corresponding_number_key = malloc(sizeof(int) * msg_len);
	encoded_message = calloc(msg_len + 1, sizeof(char));
	
	for (int i = 0; i < msg_len; ++i)
	{
		corresponding_number_message[i] = toupper(message[i]) - 'A';
		corresponding_number_key[i] = toupper(key[i]) - 'A';
		encoded_message[i] = ((corresponding_number_message[i] + corresponding_number_key[i]) % modulo) + 'A';
	}

	free(corresponding_number_key);
	free(corresponding_number_message);

	return encoded_message;
}

char *vernam_cipher_decode(const char *message, const char *key)
{
	int key_len = strlen(key);
	int msg_len = strlen(message);

	char* encoded_message;
	int* corresponding_number_message;
	int* corresponding_number_key;
	int modulo = 'Z' - 'A' + 1;

	if (msg_len != key_len)
	{
		fprintf(stderr, "%s\n", "Key length has to be the same as message length!");
		return NULL;
	}

	corresponding_number_message = malloc(sizeof(int) * msg_len);
	corresponding_number_key = malloc(sizeof(int) * msg_len);
	encoded_message = calloc(msg_len + 1, sizeof(char));

	for (int i = 0; i < msg_len; ++i)
	{
		corresponding_number_message[i] = toupper(message[i]) - 'A';
		corresponding_number_key[i] = toupper(key[i]) - 'A';
		encoded_message[i] = my_modulo((corresponding_number_message[i] - corresponding_number_key[i]), modulo) + 'A';
	}

	free(corresponding_number_key);
	free(corresponding_number_message);

	return encoded_message;
}
