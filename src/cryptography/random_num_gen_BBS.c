
#include "my_crypto.h"
#include <openssl/bn.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <math.h>

static BIGNUM *generate_number(BIGNUM *seed, BIGNUM *M, BN_CTX *ctx);
static int get_lsb(BIGNUM *number);
/**
 * @brief      Function returns number of maximum value of 2^(bit_num_len)
 * 				details can be found: https://en.wikipedia.org/wiki/Blum_Blum_Shub
 *
 * @param[in]  seed         The n number that is co-prime to M = pq
 * @param[in]  p            prime number such that p mod 4 = 3
 * @param[in]  q            prime number such that q mod 4 = 3
 * @param[in]  bit_num_len  The bit number length
 *
 * @return     random number
 */
char *rand_BBS(uint64_t seed, uint64_t p, uint64_t q, int bit_num_len)
{
	int result;
	BIGNUM *bn_next_seed = BN_new();
	BIGNUM *bn_M = BN_new();
	BIGNUM *bn_p = BN_new();
	BIGNUM *bn_q = BN_new();
	BIGNUM *bn_result = BN_new();
	BN_CTX *ctx = BN_CTX_new();

	if ((unsigned long long int)p % 4 != 3 || (unsigned long long int)q % 4 !=3)
	{
		fprintf(stderr, "Wrong primes!\nChoose primes so that p % 4 == 3 and q % 4 == 3\n");
		return NULL;
	}

	if ((unsigned long long int)seed % (unsigned long long int)p == 0 || (unsigned long long int)seed % (unsigned long long int)q == 0)
	{
		fprintf(stderr, "Wrong seed!\nChoose seed so that it is co-prime to M = p * q\n");
		return NULL;
	}
	
	BN_set_word(bn_p, p);
	BN_set_word(bn_q, q);
	BN_set_word(bn_next_seed, seed);

	BN_mul(bn_M, bn_p, bn_q, ctx);

	for (int i = 0; i < bit_num_len; ++i)
	{
		bn_next_seed = generate_number(bn_next_seed, bn_M, ctx);

		if (get_lsb(bn_next_seed) == 1)
		{
			BN_set_bit(bn_result, i);
		}
	}

	BN_free(bn_next_seed);
	BN_free(bn_M);
	BN_free(bn_p);
	BN_free(bn_q);
	BN_CTX_free(ctx);

	return BN_bn2dec(bn_result);
}

static BIGNUM *generate_number(BIGNUM *seed, BIGNUM *M, BN_CTX *ctx)
{
	BIGNUM *result = BN_new();
	BN_mod_sqr(result, seed, M, ctx);
	return result;
}

static int get_lsb(BIGNUM *number)
{
	return BN_is_odd(number);
}