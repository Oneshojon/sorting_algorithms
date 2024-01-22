#include <stdio.h>
#include "sort.h"

/**
 * print_parse - Prints value of array
 * @array: The array to be printed
 * @text: The text to be printed alongside values
 * @low: Lower bound
 * @high: Upper bound
 */
void print_parse(int *array, const char *text, size_t low, size_t high)
{
	size_t i;
	char *separator = "";

	printf("[%s]: ", text);
	for (i = low; i <= high; i++)
	{
		printf("%s%d", separator, array[i]);
		separator = ", ";
	}
	printf("\n");
}

/**
 * join_parse - Joins and sort values in the array parsed
 * @arr: Array to be sorted
 * @low: Starting index of the array passed
 * @high: Ending index of the array passed
 * @mid: Midpoint of the split array
 * @copy: Array to store sorted values
 */
void join_parse(int *arr, size_t low, size_t high, size_t mid, int *copy)
{
	size_t hiStart = mid + 1, newIndex, loStart = low, i;

	printf("merging...\n");
	print_parse(arr, "left", low, mid);
	print_parse(arr, "right", mid + 1, high);

	for (newIndex = low; newIndex <= high; newIndex++)  /* Fill sorted values */
	{
		if ((loStart <= mid && arr[loStart] <= arr[hiStart]) || hiStart > high)
			copy[newIndex] = arr[loStart++];
		else
			copy[newIndex] = arr[hiStart++];
	}

	for (i = low; i <= high; i++)  /* Update initial array with sorted arr */
		arr[i] = copy[i];

	print_parse(arr, "Done", low, high);
}

/**
 * parser - Recursively perform merge sort with the given array
 * @array: Array to be sorted
 * @lb: Lower bound
 * @ub: Upper bound
 * @copy: Array to store sorted values
 */
void parser(int *array, size_t lb, size_t ub, int *copy)
{
	size_t mid;

	if (lb < ub)
	{
		mid = lb + (ub - lb) / 2;

		parser(array, lb, mid, copy);
		parser(array, mid + 1, ub, copy);

		join_parse(array, lb, ub, mid, copy);
	}
}

/**
 * merge-sort - The application of the merge sort algorithm
 * to sort an array of integers
 * @array: Array to be sorted
 * @size: Size of the array
 */
void merge_sort(int *array, size_t size)
{
	int *clone;

	if (!array || size < 2) /* Only one value or less in array */
		return;

	clone = malloc(sizeof(int) * size);
	if (!clone)
		return;

	parser(array, 0, size - 1, clone);
	free(clone);
}
