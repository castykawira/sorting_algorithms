#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
/**
 * struct listint_s - Doubly linked list node
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list.
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

/* Function prototypes */
void bubble_sort(int *array, size_t size);
void print_array(const int *array, size_t size);
void insertion_sort_list(listint_t **list);
void print_list(const listint_t *list);
void selection_sort(int *array, size_t size);
void shell_sort(int *array, size_t n);
void swap_int(int *a, int *b);
void cocktail_sort_list(listint_t **list);
void swap_behind(listint_t **head, listint_t **tail, listint_t **shaker);
void swap_ahead(listint_t **head, listint_t **tail, listint_t **shaker);
int lomuto_partition(int *array, int low, int high, size_t size);
void quicksort(int *array, int low, int high, size_t size);
void quick_sort(int *array, size_t size);
int max_get(int size, int *array);
void counting_sort(int *array, size_t size);
void radix_sort(int *array, size_t size);
void radix_counting_sort(int *array, size_t size, int dig, int *buf);

#endif /* SORT_H */
