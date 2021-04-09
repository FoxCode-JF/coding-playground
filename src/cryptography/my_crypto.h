#pragma once

// int vernam_cipher(int number, int key);
char *vernam_cipher_encrypt(const char *message, const char *key);
char *vernam_cipher_decode(const char *message, const char *key);