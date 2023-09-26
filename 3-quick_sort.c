#include "sort.h"

/**
 * lomuto_partition - Partitions the array using Lomuto partition scheme.
 * @array: The array to be partitioned.
 * @low: The lower index of the subarray to be partitioned.
 * @high: The higher index of the subarray to be partitioned.
 * @size: The size of the array.
 * Return: The index of the pivot element after partitioning.
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot;
	int i;
	int j;
	int tmp;

	pivot = array[high];
	i = low;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			tmp = array[i];
			array[i] = array[j];
			array[j] = tmp;
			if (array[i] != array[j])
				print_array(array, size);
			i++;
		}
	}
	tmp = array[i];
	array[i] = array[high];
	array[high] = tmp;
	if (array[i] != array[high])
		print_array(array, size);
	return (i);
}

/**
 * quicksort - Recursively sorts a subarray of integers using Quick Sort.
 * @array: The array to be sorted.
 * @low: The lower index of the subarray.
 * @high: The higher index of the subarray.
 * @size: The size of the array.
 */
void quicksort(int *array, int low, int high, size_t size)
{
	int pivot_index;

	if (low < high)
	{
		pivot_index = lomuto_partition(array, low, high, size);

		quicksort(array, low, pivot_index - 1, size);
		quicksort(array, pivot_index + 1, high, size);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order using Quick Sort.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quicksort(array, 0, size - 1, size);
}
