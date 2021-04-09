#pragma once

char *vernam_cipher_encrypt(const char *message, const char *key);
char *vernam_cipher_decode(const char *message, const char *key);

char *vigenere_cipher_encrypt(const char *message, const char *key);
char *vigenere_cipher_decode(const char *message, const char *key);



int my_modulo(int number, int modulo);