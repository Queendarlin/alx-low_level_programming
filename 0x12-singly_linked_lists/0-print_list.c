#include "lists.h"

/**
 * print_list - Function to print the elements of a list
 * @h: Pointer to the first node of the singly linked list
 * Return: The nodes number
 */
size_t print_list(const list_t *h)
{
	int index;

	if (h == NULL)
		return (0);
	for (index = 1; h->next != NULL; index++)
	{
		if (h->str == NULL)
			printf("[%u] %s\n", h->len, "(nil)");
		else
			printf("[%u] %s\n", h->len, h->str);
		h = h->next;
	}
	 printf("[%u] %s\n", h->len, h->str);
	return (index);
}
