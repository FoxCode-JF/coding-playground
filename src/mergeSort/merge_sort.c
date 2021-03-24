#include "merge_sort.h"

#include <stdio.h>


int main(int argc, char const *argv[])
{
	int arr[] = { 12, 11, 13, 5, 6, 7 };
    int arr_size = sizeof(arr) / sizeof(arr[0]);
 
    printf("Given array is \n");
    print_array(arr, arr_size);
 
    merge_sort(arr, 0, arr_size - 1);
 
    printf("Sorted array is \n");
    print_array(arr, arr_size);

	return 0;
}

void print_array(const int *array, int array_size)
{
	for (int i = 0; i < array_size; ++i)
	{
		printf("[%d ]", array[i]);
	}
	printf("\n");
}

void merge_sort(int array[], int left_part_index, int right_part_index)
{
	if (left_part_index >= right_part_index)
	{
		return;
	}
	int middle_point = left_part_index + (right_part_index - left_part_index) / 2;

	merge_sort(array, left_part_index, middle_point);
	merge_sort(array, middle_point + 1, right_part_index);
	merge(array, left_part_index, middle_point, right_part_index);
}


void merge(int array[], int left_part_index, int middle_point, int right_part_index)
{
	int left_array_len = middle_point - left_part_index + 1;
	int right_array_len = right_part_index - middle_point;

	int left_array[left_array_len];
	int right_array[right_array_len];

	for (int i = 0; i < left_array_len; ++i)
	{
		left_array[i] = array[left_part_index + i];
	}

	for (int i = 0; i < right_array_len; ++i)
	{
		right_array[i] = array[middle_point + i + 1];
	}

	printf("Left array len: %d\n", left_array_len);
	print_array(left_array, left_array_len);

	printf("Right array len: %d\n", right_array_len);
	print_array(right_array, right_array_len);

	int current_left_idx = 0;
	int current_right_idx = 0;
	int current_merged_idx = left_part_index;

	while (current_left_idx < left_array_len && current_right_idx < right_array_len)
	{
		if (left_array[current_left_idx] <= right_array[current_right_idx])
		{
			array[current_merged_idx] = left_array[current_left_idx];
			current_left_idx++;
		} else 
		{
			array[current_merged_idx] = right_array[current_right_idx];
			current_right_idx++;
		}
		current_merged_idx++;
	}
	while (current_left_idx < left_array_len)
	{
		array[current_merged_idx] = left_array[current_left_idx];
		current_left_idx++;
		current_merged_idx++;
	}

	while (current_right_idx < right_array_len)
	{
		array[current_merged_idx] = right_array[current_right_idx];
		current_right_idx++;
		current_merged_idx++;
	}

}