#include "fast_modular_exponent.h"
#include <openssl/bn.h>
#include <stdint.h>
#include <stdio.h>

static uint64_t bit_shift_right(uint64_t number);
static uint8_t get_binary_least_significant_bit(uint64_t number);


char *bn_modular_exponent(BIGNUM *base,  BIGNUM *exponent, BIGNUM *modulo)
{
	// uint64_t binary_exponent = decimal_to_binary(exponent);

	BIGNUM *result = BN_new();
	BN_CTX *ctx = BN_CTX_new();
	
	BIGNUM *tmp = exponent;
	BIGNUM *kw = base;

	BN_set_word(result, 1);

	char *bn_to_print = BN_bn2dec(kw);

	bn_to_print = BN_bn2dec(exponent);

	while (!BN_is_zero(tmp))
	{
		int current_bit = BN_is_bit_set(tmp, 0);
		
		if (current_bit == 1)
		{
			BN_mul(result, result, kw, ctx);
			BN_nnmod(result, result, modulo, ctx); 
		}

		BN_mod_sqr(kw, kw, modulo, ctx);
		BN_rshift1(tmp, tmp);
	}
	char* str_result = BN_bn2dec(result);

	// Free the memory
	BN_free(result);
	BN_free(tmp);
	BN_free(kw);
	BN_CTX_free(ctx);

	return str_result;
}	


int modular_exponent(uint64_t base,  uint64_t exponent, uint64_t modulo)
{
	uint32_t result = 1;

	uint64_t tmp = exponent;
	uint64_t kw = base;

	while (tmp != 0)
	{
		uint8_t current_bit = get_binary_least_significant_bit(tmp);
		
		if (current_bit == 1)
		{
			result = (result * kw) % modulo; 
		}

		kw = (kw * kw) % modulo;

		tmp = bit_shift_right(tmp);
	}
	return result;
}	

static uint64_t bit_shift_right(uint64_t number)
{
	return (number >> 1);
}

static uint8_t get_binary_least_significant_bit(uint64_t number)
{
	return (number & 1);
}