#include "hash_tables.h"

/**
 * hash_table_delete - Function to delete a hash table
 * @ht: The hash table
 */
void hash_table_delete(hash_table_t *ht)
{
	unsigned long int itr;
	hash_node_t *node, *temp_ptr;

	if (ht == NULL)
		return;

	for (itr = 0; itr < ht->size; itr++)
	{
		node = ht->array[itr];
		while (node != NULL)
		{
			temp_ptr = node->next;
			free(node->key);
			free(node->value);
			free(node);

			node = temp_ptr;
		}
	}
	free(ht->array);
	free(ht);
}
