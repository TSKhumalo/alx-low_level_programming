#include "hash_tables.h"

/**
 * hash_table_create - function that creates a hash table
 * @size: size of the array
 * Description: 0. >>> ht = {}
 * Return: see below
 * upon success, pointer to the newly created hash table
 * upon fail, NULL
 */
hash_table_t *hash_table_create(unsigned long int size)
{
	/* declare variables for iteration & hash table */
	unsigned long int iterate = 0;
	hash_table_t *table = NULL;
	/* if there's no valid size, return NULL */
	if (size <= 0)
	{
		return (NULL);
	}
	/* allocate memory for hash table */
	table = malloc(sizeof(hash_table_t));
	if (table == NULL)
	{
		return (NULL);
	}
	/* allocate memory for array */
	table->array = malloc(sizeof(hash_node_t *) * size);
	if (table->array == NULL)
	{
		free(table);
		return (NULL);
	}
	/* assign the size to the array */
	table->size = size;
	/* assign NULL into each cell */
	for (; iterate < size; iterate++)
	{
		table->array[iterate] = NULL;
	}
	/* return pointer to hash table */
	return (table);
}
