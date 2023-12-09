#include "lists.h"

/**
 * dlistint_len - Returns the number of elements in a linked dlistint_t list.
 * @h: Pointer to the head of the list
 *
 * Return: Number of nodes in the list
 */
size_t dlistint_len(const dlistint_t *h)
{
	int counter = 0;

	if (h == NULL)
		return (counter);

	/* Traverse the list and count each node */
	while (h != NULL)
	{
		counter++;
		h = h->next;
	}

	return (counter);
}
