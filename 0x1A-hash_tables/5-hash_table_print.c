#include "hash_tables.h"

/**
 * hash_table_print - Function to print a hash table
 * @ht: The hash table
 */
void hash_table_print(const hash_table_t *ht)
{
	unsigned long int itr;
	hash_node_t *node_ptr;
	int check_first;

	if (ht == NULL)
		return;

	printf("{");
	for (itr = 0; itr < ht->size; itr++)
	{
		node_ptr = ht->array[itr];
		while (node_ptr != NULL)
		{
			if (!check_first)
				printf(", ");
			printf("'%s': '%s'", node_ptr->key, node_ptr->value);
			check_first = 0;
			node_ptr = node_ptr->next;
		}
	}
	printf("}\n");
}
