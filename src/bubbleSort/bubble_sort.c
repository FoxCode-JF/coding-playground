#include "bubble_sort.h"
#include <stdio.h>

void bubble_sort(int **array, int array_size)
{
	for (int i = 0; i < array_size; ++i)
	{
		for (int j = 0; j < array_size - 1; ++j)
		{
			if ((*array)[j] > (*array)[j + 1])
			{
				int tmp = (*array)[j];
				(*array)[j] = (*array)[j + 1];
				(*array)[j + 1] = tmp;
			}
		}
	}
};

bool is_array_equal(const int *first_array, const int *second_array, int array_size)
{
	for (int i = 0; i < array_size; ++i)
	{
		if(first_array[i] != second_array[i])
		{
			return false;
		}
	}
	return true;
};

void print_array(const int *array, int array_size)
{
	for (int i = 0; i < array_size; ++i)
	{
		printf("[%d ]", array[i]);
	}
	printf("\n");
}
