#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * TMerge - Sorts and merges the sub arrays in source
 * @start: Starting index (inclusive) for the left sub array
 * @middle: End index (exclusive) for the left sub array and
 * starting index (inclusive) for the right sub array
 * @end: End index (exclusive) for the right sub array
 * @dest: Destination for data
 * @source: Source of data
 *
 * Return: void
 */

void TMerge(size_t start, size_t middle, size_t end, int *dest, int *source)
{
	size_t i, j, k;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(source + start, middle - start);
	printf("[right]: ");
	print_array(source + middle, end - middle);
	i = start;
	j = middle;
	for (k = start; k < end; k++)
	{
		if (i < middle && (j >= end || source[i] <= source[j]))
		{
			dest[k] = source[i];
			i++;
		}
		else
		{
			dest[k] = source[j];
			j++;
		}
	}
	printf("[Done]: ");
	print_array(dest + start, end - start);
}

/**
 * TSplitMerge - recursively splits the array and merges the sorted arrays
 * @start: starting index (inclusive)
 * @end: end index (exclusive)
 * @array: the array to sort
 * @copy: a copy of the array
 *
 * Return: void
 */
void TSplitMerge(size_t start, size_t end, int *array, int *copy)
{
	size_t middle;

	if (end - start < 2)
		return;
	middle = (start + end) / 2;
	TSplitMerge(start, middle, array, copy);
	TSplitMerge(middle, end, array, copy);
	TMerge(start, middle, end, array, copy);
	for (middle = start; middle < end; middle++)
		copy[middle] = array[middle];
}

/**
 * merge_sort - sorts an array of integers in ascending order using the
 * Merge sort algorithm
 * @array: array to sort
 * @size: size of the array
 *
 * Return: void
 */
void merge_sort(int *array, size_t size)
{
	size_t i;
	int *copy;

	if (array == NULL || size < 2)
		return;
	copy = malloc(sizeof(int) * size);
	if (copy == NULL)
		return;
	for (i = 0; i < size; i++)
		copy[i] = array[i];
	TSplitMerge(0, size, array, copy);
	free(copy);
}
