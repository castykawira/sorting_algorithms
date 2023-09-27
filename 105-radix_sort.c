#include "sort.h"

/**
 * radix_counting_sort - Function that sorts digits of an array of integers
 * in an ascending order using the counting sort algo.
 * @array: An array of integers
 * @size: The size of the array
 * @dig: The significant digit to sort on
 * @buf: A buffer to store the sorted array.
 */

void radix_counting_sort(int *array, size_t size, int dig, int *buf)
{
	int count[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	size_t i;

	for (i = 0; i < size; i++)
		count[(array[i] / dig) % 10] += 1;

	for (i = 0; i < 10; i++)
		count[i] += count[i - 1];

	for (i = size - 1; (int)i >= 0; i--)
	{
		buf[count[(array[i] / dig) % 10] - 1] = array[i];
		count[(array[i] / dig) % 10] -= 1;
	}

	for (i = 0; i < size; i++)
		array[i] = buf[i];
}

/**
 * radix_sort - Function that sorts an array of integers in ascending order
 * using the radix sort algorithm
 * @array: An array of integers
 * @size: The size of the array
 */

void radix_sort(int *array, size_t size)
{
	int max, dig, *buf;

	if (array == NULL || size < 2)
		return;

	buf = malloc(sizeof(int)  * size);
	if (buf == NULL)
		return;

	max = max_get(size, array);
	for (dig = 1; max / dig > 0; dig *= 10)
	{
		radix_counting_sort(array, size, dig, buf);
		print_array(array, size);
	}

	free(buf);
}

/**
 * max_get - Function that gets the maximum value i an array of integers
 * @array: The array
 * @size: The size of the array to sort
 *
 * Return: The maximum integer in the array
 */

int max_get(int size, int *array)
{
	int i, max;

	for (max = array[0], i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	return (max);
}
