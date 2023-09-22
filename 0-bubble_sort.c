#include "sort.h"

/**
 * bubble_sort - implements the Bubble Sort algorithm
 * @array: The array to be sorted.
 * @size: Number of elements in the array.
 */
void bubble_sort(int *array, size_t size)
{
	size_t m, p;
	int temp;

	if (array == NULL || size < 2)
		return;

	for (m = 0; m < size - 1; m++)
		for (p = 0; p < size - 1; p++)
		{
			if (array[p] > array[p + 1])
			{
				temp = array[p];
				array[p] = array[p + 1];
				array[p + 1] = temp;

				print_array(array, size);
			}
		}
}
