#include "matrix_multiply.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

static void print_matrix(int cols, int rows, int* matrix);

/**
 * @brief      Multiplies two matrices A x B of size cols x rows, assuming they can be multiplied
 *
 * @param[in]  cols  The number of columns
 * @param[in]  rows  The number of rows
 * @param      A     Matrix A
 * @param      B     Matrix B
 *
 * @return     Returns a pointer to result
 */
int* matrix_multiply(int cols, int rows, int* A, int* B)
{
	int *result = calloc(cols * rows, sizeof(int));
	for (int i = 0; i < cols; ++i)
	{
		for (int j = 0; j < rows; ++j)
		{
			int sum = 0;
			for (int k = 0; k < cols; ++k)
			{
				*((result + i * rows) + j) += ((*((A + i * rows) + k))) * (*((B + k * cols) + j));
			}		
		}
	}
	printf("%s\n", "A:");
	print_matrix(cols, rows, A);
	printf("%s\n", "B:");
	print_matrix(cols, rows, B);
	printf("%s\n", "result matrix:");
	print_matrix(cols, rows, result);
	return result;
}


bool is_matrix_equal(int cols, int rows, int* A, int* B)
{
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j)
		{
			if (*((A + i) + j) != *((B + i) + j))
			{
				return false;
			}
		}
	}
	return true;
}

static void print_matrix(int cols, int rows, int* matrix) 
{
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j)
		{
			printf("%d, ", *((matrix + i*rows) + j));
		}
		printf("\n");
	}
}