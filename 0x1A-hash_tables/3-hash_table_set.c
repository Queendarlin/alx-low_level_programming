#include "hash_tables.h"

/**
 * hash_table_set - Function to add an element to the hash table
 * @ht: Hash table to add the key/value to
 * @key: The key
 * @value: The value of the key
 * Return: 1 if it succeeded, 0 otherwise
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	hash_node_t *new_node, *temp_ptr;

	if (ht == NULL || key == NULL || *key == '\0')
		return (0);

	index = key_index((unsigned char *)key, ht->size);

	temp_ptr = ht->array[index];
	while (temp_ptr != NULL)
	{
		if (strcmp(temp_ptr->key, key) == 0)
		{
			free(temp_ptr->value);
			temp_ptr->value = strdup(value);
			if (temp_ptr->value == NULL)
				return (0);
		}
		temp_ptr = temp_ptr->next;
	}
	new_node = malloc(sizeof(hash_node_t));
	if (new_node == NULL)
		return (0);

	new_node->key = strdup(key);
	new_node->value = strdup(value);

	new_node->next = ht->array[index];
	ht->array[index] = new_node;

	return (1);
}
