#pragma once

#include <stdint.h>
#include <openssl/bn.h>

char *vernam_cipher_encrypt(const char *message, const char *key);
char *vernam_cipher_decode(const char *message, const char *key);

char *vigenere_cipher_encrypt(const char *message, const char *key);
char *vigenere_cipher_decode(const char *message, const char *key);

char *rand_BBS(uint64_t seed, uint64_t p, uint64_t q, int bit_num_len);


int my_modulo(int number, int modulo);
