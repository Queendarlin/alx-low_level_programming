#include "lists.h"

/**
 * dlistint_len - Function to return the number of elements in a linked list
 * @h: The pointer to the head of the list
 * Return: The number of elements
 */
size_t dlistint_len(const dlistint_t *h)
{
	size_t num_elements = 0;

	while (h != NULL)
	{
		h = h->next;
		num_elements++;
	}

	return (num_elements);
}
