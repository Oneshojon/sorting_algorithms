#include "sort.h"

/**
 * counting_sort - Sorts an array of integers in ascending order.
 * @array: The array
 * @size: Size of the array.
 *
 * Return: Nothing
 */
void counting_sort(int *array, size_t size)
{
	int i = 1, max, *count, *temp;

	if (!array || size < 2)
		return;
	max = find_max(array, size);
	temp = malloc(sizeof(int) * size);
	if (!temp)
		return;
	count = malloc(sizeof(int) * size);
	if (!count)
	{
		free(temp);
		return;
	}
	for (i = 0; i <= max; i++)
		count[i] = 0;
	for (i = 0; i < (int) size; i++)
		count[array[i]]++;
	for (i = 1; i <= max; i++)
		count[i] = count[i - 1] + count[i];
	print_array(count, max + 1);
	for (i = 0; i < (int) size; i++)
	{
		temp[count[array[i]] - 1] = array[i];
		count[array[i]]--;
	}
	for (i = 0; i < (int) size; i++)
		array[i] = temp[i];

	free(count);
	free(temp);
	count = temp = NULL;
}

/**
 * find_max - Finds the maximum value in a list.
 * @array: A list of integers.
 * @size: The length of the list
 *
 * Return: The maximum value.
 */
int find_max(int array[], size_t size)
{
	int max = array[0];
	size_t i;

	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return (max);
}
