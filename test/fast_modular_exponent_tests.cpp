#include "catch2/catch.hpp"
#include <chrono>
#include <iostream>

extern "C"
{
	#include "../src/fastModularExponent/fast_modular_exponent.h"
	#include <time.h>
	#include <stdlib.h>
	#include <cstring>
	// #include <stdint.h>
	#include <stdio.h>
	#include <unistd.h>
} 

SCENARIO("Modular exponent calculations for different data")
{
	GIVEN("Base, exponent and modulo numbers")
	{
		unsigned long long base = 9, exponent, modulo; 
		int mod_exp;
		
		WHEN("Modulo and exponent are equal to 10")
		{
			exponent = 1234567890;
			modulo = 1112223334;
			THEN("Calculate modular exponent")
			{
				auto start = std::chrono::high_resolution_clock::now();
				mod_exp = modular_exponent(base, exponent, modulo);	

				auto finish = std::chrono::high_resolution_clock::now();

				std::chrono::duration<double> time_elapsed = finish - start;

				std::cout <<  "Time elapsed for modulo = " << modulo << " and exponent = " << exponent << " is: " <<  time_elapsed.count() << "s\n";
				REQUIRE(mod_exp == 1088685045);
			}
		}

		WHEN("Modulo and exponent are equal to 20")
		{
			exponent = 11730660234088087986;
			modulo = 35059902377451195011;
			
			THEN("Calculate modular exponent")
			{
				auto start = std::chrono::high_resolution_clock::now();
				mod_exp = modular_exponent(base, exponent, modulo);
				sleep(1);
				auto finish = std::chrono::high_resolution_clock::now();

				std::chrono::duration<double> time_elapsed = finish - start;

				std::cout <<  "Time elapsed for modulo = " << modulo << " and exponent = " << exponent << " is: " <<  time_elapsed.count() << "s\n";
				REQUIRE(mod_exp == 1481527529988120112);
			}		
		}

		WHEN("Modulo and exponent are equal to 50")
		{
			exponent = 50;
			modulo = 50;
			
			THEN("Calculate modular exponent")
			{
				auto start = std::chrono::high_resolution_clock::now();
				mod_exp = modular_exponent(base, exponent, modulo);
				sleep(1);
				auto finish = std::chrono::high_resolution_clock::now();

				std::chrono::duration<double> time_elapsed = finish - start;

				std::cout <<  "Time elapsed for modulo = " << modulo << " and exponent = " << exponent << " is: " <<  time_elapsed.count() << "s\n";
				REQUIRE(mod_exp == 1);
			}
		}
		
		WHEN("Modulo and exponent are equal to 100")
		{
			exponent = 100;
			modulo = 100;
			
			THEN("Calculate modular exponent")
			{
				auto start = std::chrono::high_resolution_clock::now();
				mod_exp = modular_exponent(base, exponent, modulo);	
				sleep(1);
				auto finish = std::chrono::high_resolution_clock::now();

				std::chrono::duration<double> time_elapsed = finish - start;

				std::cout <<  "Time elapsed for modulo = " << modulo << " and exponent = " << exponent << " is: " <<  time_elapsed.count() << "s\n";
				REQUIRE(mod_exp == 1);
			}
		}
	}
}