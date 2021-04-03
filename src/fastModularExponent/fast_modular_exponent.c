#include "fast_modular_exponent.h"
#include <stdint.h>
#include <stdio.h>
#include <openssl/ssl.h>

// static uint64_t decimal_to_binary(uint64_t decimal);
static uint64_t bit_shift_right(uint64_t number);
static uint8_t get_binary_least_significant_bit(uint64_t number);

int modular_exponent(uint64_t base,  uint64_t exponent, uint64_t modulo)
{
	// uint64_t binary_exponent = decimal_to_binary(exponent);

	uint32_t result = 1;

	uint64_t tmp = exponent;
	uint64_t kw = base;
	// if (1 & exponent) 
	// {
	// 	result = base;
	// }

	while (tmp != 0)
	{
		
		uint8_t current_bit = get_binary_least_significant_bit(tmp);
		printf("%d\n", current_bit);
		
		if (current_bit == 1)
		{
			printf("kw: %ld\n", kw);
			result = (result * kw) % modulo; 
		}

		kw = (kw * kw) % modulo;
		// printf("%ld\n", kw);

		tmp = bit_shift_right(tmp);
	}
	return result;
}	


// int modular_exponent(int b, int e, int m)
// {
// 	int result = 1;
// 	if (1 & e)
// 		result = b;
// 	while (1) {
// 		if (!e) break;
// 		// e >>= 1;
// 		e = bit_shift_right(e);
// 		b = (b * b) % m;
// 		printf("%d\n", (e & 1));

// 		if (e & 1)
// 		{
// 			printf("%d\n", result);
// 			result = (result * b) % m;
// 		}
// 	}
// 	return result;
// }

// static uint64_t decimal_to_binary(uint64_t decimal)
// {
// 	if (decimal == 0) return 0;
// 	if (decimal == 1) return 1;

// 	uint64_t binary = decimal % 2 + 10 * decimal_to_binary(decimal / 2);
// 	return binary;
// }

static uint64_t bit_shift_right(uint64_t number)
{
	return (number >> 1);
}

static uint8_t get_binary_least_significant_bit(uint64_t number)
{
	return (number & 1);
}