#include "lists.h"

/**
 * free_dlistint - Frees a dlistint_t list.
 * @head: Pointer to the head of the list.
 *
 * This function frees the memory allocated for a dlistint_t list.
 */
void free_dlistint(dlistint_t *head)
{
	while (head != NULL)
	{
		dlistint_t *next = head->next;
		free(head);
		head = next;
	}
}
