#include "sort.h"

/**
 *bubble_sort - sorts array
 *@array: The array to be sorted.
 *@size: size of the array
 *
 * Return: Nothing
 */
void bubble_sort(int *array, size_t size)
{
	bool swapped;
	size_t i = 0, j;

	do {
	swapped = false;
	for (j = 0; j < size - 1 - i; j++)
	{
		if (array[i] > array[i + 1])
		{
			temp = array[i];
			array[i] = array[i + 1];
			array[i + 1] = temp;
			print_array(array, size);
			swapped = true;
		}
	}
	i++;
	} while (swapped);
}
