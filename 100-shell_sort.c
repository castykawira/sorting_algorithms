#include "sort.h"

/**
 * swap_int - Swap two integers in an array.
 * @a: The first integer
 * @b: The second integer
 */

void swap_int(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * shell_sort - Function that sorts an array of integers in ascending
 * order using the shell sort algorithm
 * @array: An array of integers.
 * @size: The size
 */

void shell_sort(int *array, size_t size)
{
	size_t interval, i, j;

	if (array == NULL || size < 2)
		return;

	for (interval = 1; interval < (size / 3);)
		interval = interval * 3 + 1;

	for (; interval >= 1; interval /= 3)
	{
		for (i = interval; i < size; i++)
		{
			j = i;
			while (j >= interval && array[j - interval] > array[j])
			{
				swap_int(array + j, array + (j - interval));
				j -= interval;
			}
		}
		print_array(array, size);
	}
}
