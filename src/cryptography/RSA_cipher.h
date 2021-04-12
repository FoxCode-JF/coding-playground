#pragma once

#include <stdint.h>

void RSA_init(uint64_t p, uint64_t q);
uint64_t get_private_key();
uint64_t get_public_key();
uint64_t RSA_encrypt(uint64_t message, uint64_t p, uint64_t q);
uint64_t RSA_decrypt(uint64_t message, uint64_t p, uint64_t q);
