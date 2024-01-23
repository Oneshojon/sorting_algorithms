#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * partition - Finds the partition for the quicksort using the Hoare scheme
 *
 * @array: The array to sort
 * @low: The lowest index of the partition to sort
 * @high: The highest index of the partition to sort
 * @size: The size of the array
 * Return: Index of the partition
 */
size_t partition(int *array, ssize_t low, ssize_t high, size_t size)
{
	int swap, pivot;

	pivot = array[high];
	while (low <= high)
	{
		while (array[low] < pivot)
			low++;
		while (array[high] > pivot)
			high--;
		if (low <= high)
		{
			if (low != high)
			{
				swap = array[low];
				array[low] = array[high];
				array[high] = swap;
				print_array(array, size);
			}
			low++;
			high--;
		}
	}
	return (high);
}

/**
 * quicksort - Sorts partition of an array of integers
 *
 * @array: The array to sort
 * @low: The lowest index of the partition to sort
 * @high: The highest index of the partition to sort
 * @size: size of the array
 * Return: Void
 */
void quicksort(int *array, ssize_t low, ssize_t high, size_t size)
{
	ssize_t pivot;

	if (low < high)
	{
		pivot = partition(array, low, high, size);
		quicksort(array, low, pivot, size);
		quicksort(array, pivot + 1, high, size);
	}
}

/**
 * quick_sort_hoare - This sorts an array of integers in ascending order
 * using the Quick sort algorithm
 *
 * @array: The array to sort
 * @size: The size of the array
 * Return: Void
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quicksort(array, 0, size - 1, size);
}
