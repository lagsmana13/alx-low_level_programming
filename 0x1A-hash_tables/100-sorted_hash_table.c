#include "hash_tables.h"

shash_table_t *shash_table_create(unsigned long int size);
int shash_table_set(shash_table_t *ht, const char *key, const char *value);
char *shash_table_get(const shash_table_t *ht, const char *key);
void shash_table_print(const shash_table_t *ht);
void shash_table_print_rev(const shash_table_t *ht);
void shash_table_delete(shash_table_t *ht);

/**
 * shash_table_create - Creates a sorted hash table.
 * @size: The size of new sorted hash table.
 *
 * Return: If an error occurs - NULL.
 *         Otherwise - a pointer to the new sorted hash table.
 */
shash_table_t *shash_table_create(unsigned long int size)
{
    shash_table_t *ht;
    unsigned long int i;

    /* Allocate memory for the sorted hash table structure */
    ht = malloc(sizeof(shash_table_t));
    if (ht == NULL)
        return (NULL);

    /* Set the size of the sorted hash table */
    ht->size = size;

    /* Allocate memory for the sorted hash table array */
    ht->array = malloc(sizeof(shash_node_t *) * size);
    if (ht->array == NULL)
    {
        free(ht);
        return (NULL);
    }

    /* Initialize all the elements of the sorted hash table array to NULL */
    for (i = 0; i < size; i++)
        ht->array[i] = NULL;

    /* Initialize the head and tail pointers of the sorted hash table */
    ht->shead = NULL;
    ht->stail = NULL;

    /* Return the pointer to the newly created sorted hash table */
    return (ht);
}

/**
 * shash_table_set - Adds an element to a sorted hash table.
 * @ht: A pointer to the sorted hash table.
 * @key: The key to add - cannot be an empty string.
 * @value: The value associated with key.
 *
 * Return: Upon failure - 0.
 *         Otherwise - 1.
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
    shash_node_t *new, *tmp;
    char *value_copy;
    unsigned long int index;

    /* Check if the sorted hash table or key is NULL or empty */
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

    /* Search for the key in the sorted hash table */
    tmp = ht->shead;
    while (tmp)
    {
        /* If the key is found, update the value and return */
        if (strcmp(tmp->key, key) == 0)
        {
            free(tmp->value);
            tmp->value = value_copy;
            return (1);
        }
        tmp = tmp->snext;
    }

    /* If the key is not found, create a new node and add it to the sorted hash table */
    new = malloc(sizeof(shash_node_t));
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

    /* Add the new node to the sorted hash table */
    new->next = ht->array[index];
    ht->array[index] = new;

    /* Insert the new node into the sorted linked list */
    if (ht->shead == NULL)
