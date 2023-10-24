#include "lists.h"

/**
 * free_listint_safe -  Function to free a linked list
 * @h: Pointer to the head pointer
 * Return: The size of freed list
 */
size_t free_listint_safe(listint_t **h)
{
	size_t count = 0;
	int h_next;
	listint_t *tmpPtr;

	if (h == NULL || *h == NULL)
		return (0);

	while (*h != NULL)
	{
		h_next = *h - (*h)->next;

		if (h_next > 0)
		{
			tmpPtr = (*h)->next;
			free(*h);
			*h = tmpPtr;
			count++;
		}
		else
		{
			free(*h);
			*h = NULL;
			count++;
			break;
		}
	}

	*h = NULL;

	return (count);
}
