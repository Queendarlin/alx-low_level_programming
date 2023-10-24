#include "lists.h"

/**
 * free_listint_safe -  Function to free a linked list
 * @h: Pointer to the head pointer
 * Return: The size of freed list
 */
size_t free_listint_safe(listint_t **h)
{
	size_t num_nodes = 0;
	listint_t *tempPtr;

	if (h == NULL)
		return (0);

	while (*h != NULL)
	{
		tempPtr = *h;
		*h = (*h)->next;
		free(tempPtr);
		num_nodes++;
	}

	*h = NULL;

	return (num_nodes);
}
