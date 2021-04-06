#pragma once

#include <stdint.h>
#include <openssl/bn.h>
#include <openssl/ossl_typ.h>

char *bn_modular_exponent(BIGNUM *base,  BIGNUM *exponent, BIGNUM *modulo);
int modular_exponent(uint64_t base,  uint64_t exponent, uint64_t modulo);
