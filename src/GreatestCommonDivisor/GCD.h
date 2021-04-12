#pragma once
#include <stdbool.h>
#include <stdint.h>

int gcd_euclid_sub(int a, int b);
uint64_t gcd_euclid_mod(uint64_t a, uint64_t b);
int gcd_stein(int a, int b);
uint64_t gcd_euclid_extended(uint64_t a, uint64_t b, int64_t* x, int64_t* y);

bool is_even(int number);
