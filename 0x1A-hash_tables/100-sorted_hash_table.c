#include "hash_tables.h"

/**
 * shash_table_create - Function to create a sorted hash table
 * @size: The size of the array
 * Return: A pointer to the created hash table, or NULL on failure
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *ht;
	unsigned long int itr;

	ht = malloc(sizeof(shash_table_t));
	if (ht == NULL)
		return (NULL);

	ht->size = size;
	ht->array = malloc(sizeof(shash_node_t *) * size);
	if (ht->array == NULL)

		return (NULL);

	for (itr = 0; itr < size; itr++)
		ht->array[itr] = NULL;

	ht->shead = NULL;
	ht->stail = NULL;

	return (ht);
}

#include "hash_tables.h"

/**
 * sorted_list - function for insert new node in sorted
 * @ht: pointer to sorted hash table
 * @new_node: pew node to insert
 *
 */
void sorted_list(shash_table_t *ht, shash_node_t *new_node)
{
	shash_node_t *snode = ht->shead;

	if (snode == NULL)
	{
		ht->shead = ht->stail = new_node;
		new_node->snext = new_node->sprev = NULL;
		return;
	}
	do {
		if (strcmp(new_node->key, snode->key) < 0)
		{
			new_node->snext = snode;
			new_node->sprev = snode->sprev;

			if (!snode->sprev)
				ht->shead = new_node;
			else
				snode->sprev->snext = new_node;
			snode->sprev = new_node;
			return;
		}
		snode = snode->snext;
	} while (snode);
	new_node->sprev = ht->stail;
	new_node->snext = ht->stail->snext;
	ht->stail->snext = new_node;
	ht->stail = new_node;
}

/**
 * shash_table_set - Function to add an element to the sorted hash table
 * @ht: The hash table
 * @key: The key
 * @value: The value associated with the key
 * Return: 1 on success, 0 on failure
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index = 0;
	char *copy_value, *copy_key;
	shash_node_t  *node, *new_node;

	if (!ht || !key || !*key || !value)
		return (0);
	copy_value = strdup(value);
	if (!copy_value)
		return (0);
	index = key_index((const unsigned char *)key, ht->size);
	node = ht->array[index];

	while (node)
	{
		if (!strcmp(key, node->key))
		{
			free(node->value);
			node->value = copy_value;
			return (1);
		}
		node = node->next;
	}
	new_node = calloc(1, sizeof(shash_node_t));
	if (new_node == NULL)
	{
		free(copy_value);
		return (0);
	}
	copy_key = strdup(key);
	if (!copy_key)
		return (0);
	new_node->key = copy_key;
	new_node->value = copy_value;
	new_node->next = ht->array[index];
	ht->array[index] = new_node;
	sorted_list(ht, new_node);
	return (1);
}
/**
 * shash_table_get - Retrieves a value associated with a key
 * @ht: The hash table
 * @key: The key to search for
 * Return: The value associated with the key, or NULL if key couldn't be found
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	unsigned long int index;
	shash_node_t *node;

	if (ht == NULL || key == NULL || *key == '\0')
		return (NULL);

	index = key_index((const unsigned char *)key, ht->size);
	if (index >= ht->size)
		return (NULL);

	node = ht->shead;
	while (node != NULL && strcmp(node->key, key) != 0)
		node = node->snext;

	return ((node == NULL) ? NULL : node->value);
}
/**
 * shash_table_print - Prints the sorted hash table
 * @ht: The hash table
 */
void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *node;

	if (ht == NULL)
		return;

	node = ht->shead;

	printf("{");
	while (node != NULL)
	{
		printf("'%s': '%s'", node->key, node->value);
		node = node->snext;
		if (node != NULL)
			printf(", ");
	}
	printf("}\n");
}

/**
 * shash_table_print_rev - Prints the sorted hash table in reverse order
 * @ht: The hash table
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *node;

	if (ht == NULL)
		return;

	node = ht->stail;

	printf("{");
	while (node != NULL)
	{
		printf("'%s': '%s'", node->key, node->value);
		node = node->sprev;
		if (node != NULL)
			printf(", ");
	}
	printf("}\n");
}

/**
 * shash_table_delete - Function to delete a sorted hash table
 * @ht: The hash table to delete
 */
void shash_table_delete(shash_table_t *ht)
{
	shash_node_t *node, *temp_ptr;
	shash_table_t *head = ht;

	if (ht == NULL)
		return;

	node = ht->shead;

	while (node)
	{
		temp_ptr = node->snext;
		free(node->key);
		free(node->value);
		free(node);
		node = temp_ptr;
	}

	free(ht->array);
	free(head);
}
