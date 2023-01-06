#include "hash_tables.h"

/**
 * hash_table_get - function that retrieves a value
 * @ht: pointer to the hash table
 * @key: pointer to desired key
 * Description: 4. >>> ht['betty']
 * Return: see below
 * upon success, value associated with the key
 * upon fail, NULL if key is not found
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	/* declare variable for index & pointer to it */
	unsigned long int index = 0;
	hash_node_t *current = NULL;
	/* if hash table or key is not valid */
	if ((ht == NULL) || (key == NULL))
	{
		return (NULL);
	}
	/* find index to retrieve the value from */
	index = key_index((const unsigned char *)key, ht->size);
	/* set pointer to the index */
	current = ht->array[index];
	/* iterate through the linked list to find the key */
	while (current != NULL)
	{
		if (strcmp(current->key, key) == 0)
		{
			return (current->value);
		}
		current = current->next;
	}
	/* if key isn't found, return NULL */
	return (NULL);
}
