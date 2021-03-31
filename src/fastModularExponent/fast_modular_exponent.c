#include "fast_modular_exponent.h"
#include <stdint.h>

// static uint64_t decimal_to_binary(uint64_t decimal);
static uint8_t bit_shift_right(uint64_t number);
static uint8_t get_binary_least_significant_bit(uint64_t number);

int modular_exponent(uint64_t number,  uint64_t exponent, uint64_t modulo)
{
	// uint64_t binary_exponent = decimal_to_binary(exponent);

	uint32_t result = 1;

	uint64_t tmp = exponent;
	uint64_t kw = number;

	while (tmp != 0)
	{
		uint8_t current_bit = get_binary_least_significant_bit(tmp);

		if (current_bit == 1)
		{
			result = (result * kw) % modulo; 
		}

		kw = kw * kw;

		tmp = bit_shift_right(tmp);
	}
	return result;
}	

// static uint64_t decimal_to_binary(uint64_t decimal)
// {
// 	if (decimal == 0) return 0;
// 	if (decimal == 1) return 1;

// 	uint64_t binary = decimal % 2 + 10 * decimal_to_binary(decimal / 2);
// 	return binary;
// }

static uint8_t bit_shift_right(uint64_t number)
{
	return number / 2;
}

static uint8_t get_binary_least_significant_bit(uint64_t number)
{
	return number % 2;
}