#include "catch2/catch.hpp"

extern "C"
{
	#include "../src/bubbleSort/bubble_sort.h"
	#include <time.h>
	#include <stdlib.h>
	#include <cstring>
}





#define ARRAY_SIZE 15

/*	
 *	
 *	
 */

SCENARIO("Sort list of n integers")
{
	GIVEN("List of integers")
	{
		const int array_to_copy[] = {12, 11, 2, 2, 89, 34, 189, 100, 3, 19, 103, 1000, 333, 666, 123};

		int *array = (int*)malloc(ARRAY_SIZE * sizeof(int)); 
		memcpy(array, array_to_copy, ARRAY_SIZE * sizeof(array[0]));

		WHEN("array not sorted")
		{
			bubble_sort(&array, ARRAY_SIZE);
			// print_array(array, ARRAY_SIZE);

			THEN("Array is sorted")
			{

				int *array_sorted = (int*)malloc(ARRAY_SIZE * sizeof(int)); 
				int array_sorted_to_copy[] =  {2, 2, 3, 11, 12, 19, 34, 89, 100, 103, 123, 189, 333, 666, 1000};
				memcpy(array_sorted, array_sorted_to_copy, ARRAY_SIZE * sizeof(array_sorted[0]));
				
				REQUIRE(is_array_equal(array, array_sorted, ARRAY_SIZE));
			}

		}
	}
}