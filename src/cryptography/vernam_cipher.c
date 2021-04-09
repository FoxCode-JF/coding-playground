#include "my_crypto.h"

int vernam_cipher(int number, int key)
{
	return number ^ key;
}
