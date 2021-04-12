#include "RSA_cipher.h"
#include "../GreatestCommonDivisor/GCD.h"
#include "../fastModularExponent/fast_modular_exponent.h"
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <time.h>
#include <math.h>

static uint64_t get_random_from_range(uint64_t lower, uint64_t upper);
static uint64_t find_mod_inverse(uint64_t number, uint64_t modulo);
static bool is_coprime(uint64_t a, uint64_t b);

uint64_t d;
uint64_t e;
uint64_t n;

void RSA_init(uint64_t p, uint64_t q)
{
	uint64_t n = p * q;
	uint64_t totient = (p - 1) * (q - 1);

	do
	{
		d = get_random_from_range(0, totient);
	} while(!is_coprime(d, totient));
	e = find_mod_inverse(d, totient);
}

uint64_t RSA_encrypt(uint64_t message, uint64_t n, uint64_t e)
{
	return modular_exponent(message, e, n);
}

uint64_t RSA_decrypt(uint64_t encrypted_message,uint64_t n, uint64_t d)
{
	return modular_exponent(encrypted_message, d, n);
}

uint64_t get_private_key()
{
	return d;
}

uint64_t get_public_key()
{
	return e;
}

static uint64_t find_mod_inverse(uint64_t number, uint64_t modulo)
{
	    int64_t x, y;
	    uint64_t g = gcd_euclid_extended(number, modulo, &x, &y);
	    if (g != 1)
	        printf("Inverse does not exist");
	    else
	    {
	        uint64_t res = (x + modulo) % modulo;
	        return res;
	    }
	return 0;
}

static uint64_t get_random_from_range(uint64_t lower, uint64_t upper)
{
	uint64_t random_num = (rand() % (upper - lower + 1)) + lower; 
	return random_num;
}

static bool is_coprime(uint64_t a, uint64_t b)
{
	if (gcd_euclid_mod(a, b) == 1)
		return true;
	else
	{
		return false;
	}
}

