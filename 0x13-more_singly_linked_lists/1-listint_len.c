#include "lists.h"

/**
 * listint_len - Function to return the number of elements in a linked lists
 * @h: Pointer to the first node of the list
 * Return: The number of elements in the list
 */
size_t listint_len(const listint_t *h)
{
	size_t num_elements = 0;

	while (h != NULL)
	{
		h = h->next;
		num_elements++;
	}
	return (num_elements);
}
