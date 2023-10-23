#include "lists.h"

/**
 * print_listint - Function to print all element of a list
 * @h: A pointer to the first node of the list
 * Return: The elements of the nodes
 */
size_t print_listint(const listint_t *h)
{
	size_t print_elements = 0;

	while (h != NULL)
	{
		printf("%d\n", h->n);
		h = h->next;
		print_elements++;
	}
	return (print_elements);
}
