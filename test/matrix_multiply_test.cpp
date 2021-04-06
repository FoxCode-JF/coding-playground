#include "catch2/catch.hpp"

extern "C"
{
	#include "../src/matrixMultiply/matrix_multiply.h"
	#include <time.h>
	#include <stdlib.h>
	#include <cstring>
}

SCENARIO("Multiply two matrices of the same size")
{
	const int COLS_SIZE = 3;
	const int ROWS_SIZE = 3;
	GIVEN("Matrix A and B")
	{
		int A[ROWS_SIZE][COLS_SIZE] = {
			{4, 3, 0},
			{1, 2, 3},
			{1, 1, 1}
		};
		int B[ROWS_SIZE][COLS_SIZE] = {
			{0, 3, 0},
			{1, 0, 3},
			{1, 1, 0}
		};

		WHEN("Size of matrix n > 0")
		{
			THEN("Multiply matrices A and B")
			{
				int expected[ROWS_SIZE][COLS_SIZE] ={
					{3, 12, 9},
					{5, 6, 6},
					{2, 4, 3}
				};
								
				int *result = matrix_multiply(ROWS_SIZE, COLS_SIZE, (int*)A, (int*)B);
				
				bool is_expected_matrix = is_matrix_equal(ROWS_SIZE, COLS_SIZE, (int*)result, (int*)expected);

				REQUIRE(is_expected_matrix == true);
			}
		}

		WHEN("Size of matrix = 0")
		{
			THEN("Return NULL")
			{
				int *result = matrix_multiply(ROWS_SIZE, COLS_SIZE, (int*)A, (int*)B);
				// REQUIRE(result == NULL);
				FAIL("Implement!");

			}
		}
	}
}