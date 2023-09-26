#include "sort.h"

/**
 * swap_int - Function that swaps two integers in an array
 * @a: First integer
 * @b: Second integer
 */

void swap_int(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * shell_sort - Implements the shell sort algorithm sorting
 * 		an array of integers in ascending order
 * @array: The array of integers to sort
 * @n: Size of the array
 */

void shell_sort(int *array, size_t n)
{
	size_t interval, i, j;

	if (array == NULL || n < 2)
		return;

	for (interval = 1; interval < (n / 3);)
		interval = interval * 3 + 1;

	for (; interval >= 1; interval /= 3)
	{
		for (i = interval; i < n; i++)
		{
			j = i;
			while (j >= interval && array[j - interval] > array[j])
			{
				swap_int(array + j, array + (j - interval));
				j -= interval;
			}
		}
		print_array(array, n);
	}
}
