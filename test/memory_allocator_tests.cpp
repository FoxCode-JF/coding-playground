#include "catch2/catch.hpp"

extern "C"
{
	#include "../src/bubbleSort/bubble_sort.h"
	#include <time.h>
	#include <stdlib.h>
	#include <cstring>
}



SCENARIO("Allocate memory of size 5")
{
	GIVEN("Memory block size")
	{
		size_t mem_block_size = 5;
		WHEN("")
		{

			THEN("")
			{
				FAIL("Implement malloc test!");
			}

		}
	}
}