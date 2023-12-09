#include "lists.h"

/**
 * delete_dnodeint_at_index - Deletes the node at the given index of a linked list.
 * @head: Pointer to pointer to the head of the linked list.
 * @index: Index of the node that should be deleted. Index starts at 0.
 *
 * Return: If the deletion succeeded, return 1. If it failed, return -1.
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *current = *head;
	dlistint_t *previous = NULL;
	unsigned int count = 0;

	while (current != NULL)
	{
		if (count == index)
		{
			if (previous == NULL)
			{
				*head = current->next;
				if (*head != NULL)
					(*head)->prev = NULL;
			}
			else
			{
				previous->next = current->next;
				if (current->next != NULL)
					current->next->prev = previous;
			}
			free(current);
			return (1);
		}
		previous = current;
		current = current->next;
		count++;
	}

	return (-1);
}
