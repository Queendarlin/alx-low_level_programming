#include "lists.h"

/**
 * list_len - Function to return the number of elements in a linked list
 * @h: The pointer to te first node of the linked list
 * Return: The number of elements in the linked list
 */
size_t list_len(const list_t *h)
{
	size_t num_elements = 0;

	while (h != NULL)
	{
		h = h->next;
		num_elements++;
	}
	return (num_elements);
}
