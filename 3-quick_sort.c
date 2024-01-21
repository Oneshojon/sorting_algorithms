#include "sort.h"
/**
 * lumoto_partition - splits the array.
 * @arr: The main array
 * @low: The first element
 * @high: The last element.
 * @size: The size of the array
 *
 * Return: 0
 */
int lumoto_partition(int arr[], int low, int high, size_t size)
{
	int pivot = arr[high];
	int i = 0, j = 0, temp;

	i = low;
	for (j = low; j < high; ++j)
	{
		if (arr[j] < pivot)
		{
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;

			if (temp != arr[i])
				print_array(arr, size);
			++i;
		}
	}
	temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;

	if (temp != arr[i])
		print_array(arr, size);
	return (i);
}
/**
 * quick_sort_helper - splits the array.
 * @arr: The main array
 * @low: The first element
 * @high: The last element.
 * @size: The size of the array
 *
 * Return: 0
 */
void quick_sort_helper(int arr[], int low, int high, size_t size)
{
	int pi;

	if (low < high)
	{
		pi = lumoto_partition(arr, low, high, size);
		quick_sort_helper(arr, low, pi - 1, size);
		quick_sort_helper(arr, pi + 1, high, size);
	}
}

/**
 * quick_sort - Wrapper function to call quick_sort_helper
 * @arr: The array
 * @size: size of the array
 *
 * Return: Nothing
 */
void quick_sort(int *arr, size_t size)
{
	if (arr == NULL || size < 2)
	{
		return;
	}
	quick_sort_helper(arr, 0, size - 1, size);
}
