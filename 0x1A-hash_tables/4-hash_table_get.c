#include "hash_tables.h"

/**
 * hash_table_get - Retrieve the value associated with
 *                  a key in a hash table.
 * @ht: A pointer to the hash table.
 * @key: The key to get the value of.
 *
 * Return: If the key cannot be matched - NULL.
 *         Otherwise - the value associated with key in ht.
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
    hash_node_t *node;
    unsigned long int index;

    /* Check if the hash table or key is NULL or empty */
    if (ht == NULL || key == NULL || *key == '\0')
        return (NULL);

    /* Calculate the index of the key using the hash function */
    index = key_index((const unsigned char *)key, ht->size);

    /* Check if the index is valid */
    if (index >= ht->size)
        return (NULL);

    /* Search for the key in the hash table */
    node = ht->array[index];
    while (node && strcmp(node->key, key) != 0)
        node = node->next;

    /* Return the value associated with the key, or NULL if the key is not found */
    return ((node == NULL) ? NULL : node->value);
}
