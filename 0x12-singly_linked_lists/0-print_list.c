#include "lists.h"

/**
 * print_list - Function to print the elements of a list
 * @h: Pointer to the first node of the singly linked list
 * Return: The nodes number
 */
size_t print_list(const list_t *h)
{
	size_t num_nodes = 0;

	while (h != NULL)
	{
		if (h->str == NULL)

			printf("[%d] %s\n", 0, "(nil)");
		else
			printf("[%d] %s\n", h->len, h->str);

		h = h->next;
		  num_nodes++;
	}
	return (num_nodes);
}
