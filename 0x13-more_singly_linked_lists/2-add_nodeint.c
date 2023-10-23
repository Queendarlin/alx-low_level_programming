#include "lists.h"

/**
 * add_nodeint - Function to add a new node at the beginning of a list
 * @head: Pointer to the head pointer
 * @n: Number of elements
 * Return: The address of the new element on success or NULL on failure
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *add_new;

	add_new = malloc(sizeof(listint_t));
	if (add_new == NULL)
		return (NULL);
	add_new->n = n;
	add_new->next = *head;
	*head = add_new;

	return (add_new);
}
