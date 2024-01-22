#include "sort.h"

/**
 * sift_down - Fixes a heap
 *
 * @array: The heap to fix
 * @root: The root of the heap
 * @end: The last index of the heap
 * @size: The size of the array
 * Return: Void
 */
void sift_down(int *array, size_t root, size_t end, size_t size)
{
	size_t left_child, right_child, swap;
	int temp;

	while ((left_child = (2 * root) + 1) <= end)
	{
		swap = root;
		right_child = left_child + 1;
		if (array[swap] < array[left_child])
			swap = left_child;
		if (right_child <= end && array[swap] < array[right_child])
			swap = right_child;
		if (swap == root)
			return;
		temp = array[root];
		array[root] = array[swap];
		array[swap] = temp;
		print_array(array, size);
		root = swap;
	}
}

/**
 * make_heap - Makes heap from an unsorted array
 *
 * @array: The Array to turn into a heap
 * @size: The size of array
 * Return: Void
 */
void make_heap(int *array, size_t size)
{
	size_t parent;

	for (parent = ((size - 1) - 1) / 2; 1; parent--)
	{
		sift_down(array, parent, size - 1, size);
		if (parent == 0)
			break;
	}
}

/**
 * heap_sort - Sort an array of integer in an ascending order
 * with the Heap sort algorithm
 *
 * @array: Array to sort
 * @size: Size of the array
 * Return: Void
 */
void heap_sort(int *array, size_t size)
{
	size_t end;
	int temp;

	if (array == NULL || size < 2)
		return;
	make_heap(array, size);
	end = size - 1;
	while (end > 0)
	{
		temp = array[end];
		array[end] = array[0];
		array[0] = temp;
		print_array(array, size);
		end--;
		sift_down(array, 0, end, size);
	}
}
