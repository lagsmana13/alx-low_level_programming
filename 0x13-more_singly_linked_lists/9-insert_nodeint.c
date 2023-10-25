#include "lists.h"

/**
 * insert_nodeint_at_index - inserts a new node in a linked list,
 * at a given position
 * @head: pointer to the first node in the list
 * @idx: index where the new node is added
 * @n: data to insert in the new node
 *
 * Return: pointer to the new node, or NULL
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
  unsigned int i;
  listint_t *k;
  listint_t *tem = *head;

  k = malloc(sizeof(listint_t));
  if (!k || !head)
    return (NULL);

  k->n = n;
  k->next = NULL;

  if (idx == 0)
    {
      k->next = *head;
      *head = k;
      return (k);
    }

  for (i = 0; tem && i < idx; i++)
    {
      if (i == idx - 1)
	{
	  k->next = tem->next;
	  tem->next = k;
	  return (k);
	}
      else
	tem = tem->next;
    }

  return (NULL);
}

