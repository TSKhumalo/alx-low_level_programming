#include "hash_tables.h"

/**
 * hash_table_set - function that adds an element to the hash table and
 * in case of collision, a new element is always added to the beginning
 * @ht: pointer to the hash table
 * @key: key cannot be an empty string
 * @value: value can be an empty string & must be duplicated
 * Description: 3. >>> ht['betty'] = 'holberton'
 * Return: see below
 * 1. upon success, 1
 * 2. upon fail, 0
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	/* declare pointers for linked list & variable for index */
	hash_node_t *new_node = NULL, *current = NULL;
	unsigned long int index;
	/* if hash table or key is not valid */
	if (!ht || !key)
		return (0);
	/* create a node for new key/value pair */
	new_node = malloc(sizeof(hash_node_t));
	if (new_node == NULL)
		return (0);
	new_node->key = strdup(key);
	new_node->value = strdup(value);
	new_node->next = NULL;
	/* find index the key/value pair should be inserted into */
	index = key_index((const unsigned char *)key, ht->size);
	/* set pointer to the index */
	current = ht->array[index];
	/* if index is empty, then insert new node it */
	if (current == NULL)
	{
		new_node->next = ht->array[index];
		ht->array[index] = new_node;
		return (1);
	}
	/* if a key is already at the index, then update value */
	if (current->key == new_node->key)
	{
		free(current->value);
		current->value = new_node->value;
		return (1);
	}
	return (0);
}
