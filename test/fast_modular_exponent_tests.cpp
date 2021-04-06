#include "catch2/catch.hpp"
#include <chrono>
#include <iostream>
extern "C"
{
	#include "../src/fastModularExponent/fast_modular_exponent.h"
	#include <time.h>
	#include <stdlib.h>
	#include <cstring>
	#include <stdio.h>
	#include <unistd.h>
	#include <openssl/bn.h>
} 

SCENARIO("Modular exponent calculations for different data, small numbers up to 19 decimal digits")
{
	GIVEN("Base, exponent and modulo numbers")
	{
		unsigned long long base = 9, exponent, modulo; 
		int mod_exp;
		
		WHEN("Modulo and exponent are equal to 10")
		{
			exponent = 10;
			modulo = 10;
			THEN("Calculate modular exponent")
			{
				auto start = std::chrono::high_resolution_clock::now();
				mod_exp = modular_exponent(base, exponent, modulo);	

				auto finish = std::chrono::high_resolution_clock::now();

				std::chrono::duration<double> time_elapsed = finish - start;

				std::cout <<  "Time elapsed for modulo = " << modulo << " and exponent = " << exponent << " is: " <<  time_elapsed.count() << "s\n";
				REQUIRE(mod_exp == 1);
			}
		}

		WHEN("Modulo and exponent are equal to 20")
		{
			exponent = 20;
			modulo = 20;
			
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


SCENARIO("Modular exponent calculations for different data, big numbers over 19 decimal digits")
{
	printf("Modular exponent calculations for different data, big numbers over 19 decimal digits\n");
	GIVEN("Base, exponent and modulo numbers")
	{
		BIGNUM *base = BN_new();
		BIGNUM *exponent = BN_new();
		BIGNUM *modulo = BN_new();

		BN_set_word(base, 9);
		char *mod_exp;
		
		bool result;

		WHEN("Modulo and exponent has 10 decimal digits")
		{
			BN_set_word(exponent, 1234567890);
			BN_set_word(modulo, 1112223334);

			THEN("Calculate modular exponent")
			{
				auto start = std::chrono::high_resolution_clock::now();
				mod_exp = bn_modular_exponent(base, exponent, modulo);
				auto finish = std::chrono::high_resolution_clock::now();
				std::chrono::duration<double> time_elapsed = finish - start;

				std::cout <<  "10 digits:\nTime elapsed for modulo = " << modulo << " and exponent = " << exponent << " is: " <<  time_elapsed.count() << "s\n";

				if (strncmp(mod_exp, "1088685045", 10) == 0)
				{
					result = true;
				} else
				{
					result = false;
				}

				REQUIRE(result == true);
			}
		}

		WHEN("Modulo and exponent has 20 decimal digits")
		{
			BN_dec2bn(&exponent, "16866202799495648465");
			BN_dec2bn(&modulo, "65897945633223821102");

			THEN("Calculate modular exponent")
			{
				auto start = std::chrono::high_resolution_clock::now();
				mod_exp = bn_modular_exponent(base, exponent, modulo);
				auto finish = std::chrono::high_resolution_clock::now();

				std::chrono::duration<double> time_elapsed = finish - start;

				std::cout <<  "20 digits:\nTime elapsed for modulo = " << modulo << " and exponent = " << exponent << " is: " <<  time_elapsed.count() << "s\n";
				
				if (strncmp(mod_exp, "27564747379476302061", 20) == 0)
				{
					result = true;
				} else
				{
					result = false;
				}

				REQUIRE(result == true);
			}		
		}

		WHEN("Modulo and exponent has 50 decimal digits")
		{
			BN_dec2bn(&exponent, "76771013218886665574646934038600200424530046162925");
			BN_dec2bn(&modulo, "31276144066096266060809931544723830593932835237671");
			
			THEN("Calculate modular exponent")
			{
				auto start = std::chrono::high_resolution_clock::now();
				mod_exp = bn_modular_exponent(base, exponent, modulo);
				auto finish = std::chrono::high_resolution_clock::now();

				std::chrono::duration<double> time_elapsed = finish - start;

				std::cout <<  "50 digits:\nTime elapsed for modulo = " << modulo << " and exponent = " << exponent << " is: " <<  time_elapsed.count() << "s\n";
				
				if (strncmp(mod_exp, "18226771669712045108107677234929674891773917939342", 50) == 0)
				{
					result = true;
				} else
				{
					result = false;
				}

				REQUIRE(result == true);
			}
		}
		
		WHEN("Modulo and exponent has 100 decimal digits")
		{
			BN_dec2bn(&exponent, "8397394316658760843120685354286824904111910001177231645501177071047815741050895010456162628378832896");
			BN_dec2bn(&modulo, "4544848064466894403956938381602437013403979470627315107923583449047834516130428575289324738589860401");
			
			THEN("Calculate modular exponent")
			{
				auto start = std::chrono::high_resolution_clock::now();
				mod_exp = bn_modular_exponent(base, exponent, modulo);
				auto finish = std::chrono::high_resolution_clock::now();

				std::chrono::duration<double> time_elapsed = finish - start;

				std::cout <<  "100 digits:\nTime elapsed for modulo = " << modulo << " and exponent = " << exponent << " is: " <<  time_elapsed.count() << "s\n";
				
				if (strncmp(mod_exp, "2378676031500756902035880378521825998394312919527710189319930222821729573015581929177623268247898196", 100) == 0)
				{
					result = true;
				} else
				{
					result = false;
				}

				REQUIRE(result == true);
			}
		}

		WHEN("Modulo and exponent has 200 decimal digits")
		{
			BN_dec2bn(&exponent, "20351147419974382852717662585547176565068778817457239064483048581887697953187228563487010424560098476231592596314040478081702966480260530554122670905585774889820210003799095289401103755657247021051406");
			BN_dec2bn(&modulo, "19014536550329804702421042552883759198457957708826933730787636085619229625525487388257016019240089057249337572954773662029142992229586150653821968505542433414328266323340004011251976948438750214993856");
			
			THEN("Calculate modular exponent")
			{
				auto start = std::chrono::high_resolution_clock::now();
				mod_exp = bn_modular_exponent(base, exponent, modulo);
				auto finish = std::chrono::high_resolution_clock::now();

				std::chrono::duration<double> time_elapsed = finish - start;

				std::cout <<  "200 digits:\nTime elapsed for modulo = " << modulo << " and exponent = " << exponent << " is: " <<  time_elapsed.count() << "s\n";
				
				if (strncmp(mod_exp, "4363486280382601507383491614854656022235439785640361907258871438427616529709056815059200870603810281594521070907065242314626099253919391472038857440456585485316046079035162701761114336425058616662129", 100) == 0)
				{
					result = true;
				} else
				{
					result = false;
				}

				REQUIRE(result == true);
			}
		}
	}
}