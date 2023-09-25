#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 * in ascending order using Insertion Sort algorithm.
 * @list: A pointer to a pointer to the head of the list.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current_node, *key_node, *new_node, *tmp;

	if (!list || !(*list) || !((*list)->next))
		return;

	key_node = (*list);
		current_node = (*list)->next;

	while (current_node)
	{
		new_node = current_node->next;

		while (key_node && current_node->n < key_node->n)
		{
			key_node->prev->next = key_node->next;

			if (key_node->prev)
				key_node->prev->next = current_node;
			else
				*list = key_node;
			if (current_node->next)
				current_node->next->prev = key_node;
			tmp = current_node->next;
			current_node->next = key_node;
			current_node->prev = key_node->prev;
			key_node->next = tmp;
			key_node->prev = current_node;
			print_list(*list);
			key_node = current_node->prev;
		}
		current_node = new_node;
		if (current_node)
			key_node = current_node->prev;
	}
}
