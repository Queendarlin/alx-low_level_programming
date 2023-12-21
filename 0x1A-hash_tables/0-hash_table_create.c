#include "hash_tables.h"

/**
 * hash_table_create - Function to create a hash table
 * @size: The size of the array
 * Return: Pointer to the newly created hash table or NULL if error
 */
hash_table_t *hash_table_create(unsigned long int size)
{
	unsigned long int index;
	hash_table_t *new_hash_table;

	new_hash_table = malloc(sizeof(hash_table_t));

	if (new_hash_table == NULL)
		return (NULL);

	new_hash_table->array = malloc(sizeof(hash_node_t *) * size);

	if (new_hash_table->array == NULL)
	{
		free(new_hash_table);
		return (NULL);
	}

	for (index = 0; index < size; index++)
		new_hash_table->array[index] = NULL;

	new_hash_table->size = size;

	return (new_hash_table);
}
