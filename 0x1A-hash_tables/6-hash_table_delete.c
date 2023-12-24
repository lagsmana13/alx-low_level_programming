#include "hash_tables.h"

/**
 * hash_table_delete - Deletes a hash table.
 * @ht: A pointer to a hash table.
 */
void hash_table_delete(hash_table_t *ht)
{
    hash_node_t *node, *tmp;
    unsigned long int i;

    /* Check if the hash table is NULL */
    if (ht == NULL)
        return;

    /* Iterate over the hash table array */
    for (i = 0; i < ht->size; i++)
    {
        /* If there are nodes in the current linked list */
        if (ht->array[i] != NULL)
        {
            /* Iterate over the linked list */
            node = ht->array[i];
            while (node != NULL)
            {
                /* Free the key and value of the current node */
                free(node->key);
                free(node->value);

                /* Free the current node */
                tmp = node->next;
                free(node);

                /* Move to the next node */
                node = tmp;
            }
        }
    }

    /* Free the hash table array */
    free(ht->array);

    /* Free the hash table structure */
    free(ht);
}
