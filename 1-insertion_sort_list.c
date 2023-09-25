#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 * in ascending order using Insertion Sort algorithm.
 * @list: A pointer to a pointer to the head of the list.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current_node, *key_node;

	if (!list || !(*list) || !((*list)->next))
		return;

	current_node = (*list)->next;

	while (current_node)
	{
		key_node = current_node;
		current_node = current_node->next;

		while (key_node->prev && key_node->n < key_node->prev->n)
		{
			key_node->prev->next = key_node->next;

			if (key_node->next)
				key_node->next->prev = key_node->prev;

			key_node->next = key_node->prev;
			key_node->prev = key_node->prev->prev;

			if (key_node->prev)
				key_node->prev->next = key_node;
			else
				*list = key_node;

			key_node->next->prev = key_node;
			print_list(*list);
		}
	}
}
