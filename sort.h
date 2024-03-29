#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void print_list(const listint_t *list);
void print_array(const int *array, size_t size);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void merge_sort(int *array, size_t size);
void heap_sort(int *array, size_t size);
void quick_sort_hoare(int *array, size_t size);
void sort_deck(deck_node_t **deck);

/** quick sort **/
int lumoto_partition(int arr[], int low, int high, size_t size);
void quick_sort_helper(int arr[], int low, int high, size_t size);
void quick_sort(int *arr, size_t size);

int find_max(int array[], size_t size);
void counting_sort(int *array, size_t size);

int getCantRep(int num);
void radix_sort(int *array, size_t size);


void selection_sort(int *array, size_t size);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);


#endif
