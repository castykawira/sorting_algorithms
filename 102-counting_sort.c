#include "sort.h"

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


/**
 * counting_sort - Function that sorts an array of integers in ascending order
 * using the counting sort algorithm
 * @array: The array of integers
 * @size: The size of the array
 *
 */

void counting_sort(int *array, size_t size)
{
	int *count, *sorted, max, i;

	if (array == NULL || size < 2)
		return;

	sorted = malloc(sizeof(int) * size);
	if (sorted == NULL)
		return;
	max = max_get(size, array);
	count = malloc(sizeof(int) * (max + 1));
	if (count == NULL)
	{
		free(sorted);
		return;
	}

	for (i = 0; i < (max + 1); i++)
		count[i] = 0;
	for (i = 0; i < (int)size; i++)
		count[array[i]] += 1;
	for (i = 0; i < (max + 1); i++)
		count[i] += count[i - 1];
	print_array(count, max + 1);

	for (i = 0; i < (int)size; i++)
	{
		sorted[count[array[i]] - 1] = array[i];
		count[array[i]] -= 1;
	}

	for (i =0; i < (int)size; i++)
		array[i] = sorted[i];

	free(sorted);
	free(count);
}
