#ifndef SEARCH_ALGOS_H
#define SEARCH_ALGOS_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**
 * struct listint_s - singly connected list
 *
 * @n: Digit
 * @index: Position of the node in the list
 * @next: Reference to the subsequent node
 *
 * Details: singly connected list node framework
 */
typedef struct listint_s
{
	int n;
	size_t index;
	struct listint_s *next;
} listint_t;

/**
 * struct skiplist_s - Singly connected list with an express lane
 *
 * @n: Digit
 * @index: Position of the node in the list
 * @next: Reference to the subsequent node
 * @express: Reference to the subsequent node in the express lane
 *
 * Details: singly connected list node framework with an express lane
 */
typedef struct skiplist_s
{
	int n;
	size_t index;
	struct skiplist_s *next;
	struct skiplist_s *express;
} skiplist_t;

int linear_search(int *array, size_t size, int value);
int binary_search(int *array, size_t size, int value);
int jump_search(int *array, size_t size, int value);
int interpolation_search(int *array, size_t size, int value);
int exponential_search(int *array, size_t size, int value);
int advanced_binary(int *array, size_t size, int value);

#endif
