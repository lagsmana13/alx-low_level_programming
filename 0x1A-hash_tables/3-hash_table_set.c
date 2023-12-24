#include "hash_tables.h"

/**
 * hash_table_set - Add or update an element in a hash table.
 * @ht: A pointer to the hash table.
 * @key: The key to add - cannot be an empty string.
 * @value: The value associated with key.
 *
 * Return: Upon failure - 0.
 *         Otherwise - 1.
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
    hash_node_t *new;
    char *value_copy;
    unsigned long int index, i;

    /* Check if the hash table or key is NULL or empty */
    if (ht == NULL || key == NULL || *key == '\0')
        return (0);

    /* Check if the value is NULL */
    if (value == NULL)
        return (0);

    /* Create a copy of the value */
    value_copy = strdup(value);
    if (value_copy == NULL)
        return (0);

    /* Calculate the index of the key using the hash function */
    index = key_index((const unsigned char *)key, ht->size);

    /* Search for the key in the hash table */
    for (i = index; ht->array[i]; i++)
    {
        /* If the key is found, update the value and return */
        if (strcmp(ht->array[i]->key, key) == 0)
        {
            free(ht->array[i]->value);
            ht->array[i]->value = value_copy;
            return (1);
        }
    }

    /* If the key is not found, create a new node and add it to the hash table */
    new = malloc(sizeof(hash_node_t));
    if (new == NULL)
    {
        free(value_copy);
        return (0);
    }

    /* Copy the key and value into the new node */
    new->key = strdup(key);
    if (new->key == NULL)
    {
        free(new);
        return (0);
    }
    new->value = value_copy;

    /* Add the new node to the hash table */
    new->next = ht->array[index];
    ht->array[index] = new;

    /* Return success */
    return (1);
}
