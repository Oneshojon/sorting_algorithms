#include "sort.h"

/**
 * nodes_swap - This swaps the nodes in a list
 * @list: First node in doubly linked list
 * @first: The address of first node
 * @second: The address of second node
 */

void nodes_swap(listint_t **list, listint_t *first, listint_t *second)
{
	if (!first->prev)  /** At the first node **/
		*list = second;
	else
		first->prev->next = second;

	second->prev = first->prev;

	if (second->next)  /** At the second node **/
		second->next->prev = first;

	first->prev = second;
	first->next = second->next;
	second->next = first;
}

/**
 * cocktail_sort_list - Cocktail sort algorithm application
 * to sort numbers
 *
 * @list: First node of doubly linked list
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *future;
	int swapped = 1;

	if (!list || !(*list) || !(*list)->next) /** Only one node **/
		return;

	future = *list;
	while (swapped)
	{
		swapped = 0;
		while (future->next)  /** Traverse forward **/
		{
			if (future->n > future->next->n)
			{
				nodes_swap(list, future, future->next);
				print_list(*list);
				swapped = 1;
				continue;
			}
			future = future->next;
		}

		if (!swapped)  /** List is sorted **/
			break;

		swapped = 0;
		while (future->prev)  /** Traverse backward **/
		{
			if (future->n < future->prev->n)
			{
				nodes_swap(list, future->prev, future);
				print_list(*list);
				swapped = 1;
				continue;
			}
			future = future->prev;
		}
	}
}
