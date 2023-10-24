#include "lists.h"

/**
 * insert_nodeint_at_index - Function to insert a new node at a given position
 * @head: Pointer to the head pointer
 * @idx: The index of the list where the new node shoud be added
 * @n: The integer data of the nodes
 * Return: The address of the new node on success or NULL on failure
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *add_new;
	unsigned int itr;
	listint_t *tempPtr = *head;

	add_new = malloc(sizeof(listint_t));
	if (add_new == NULL || head == NULL)
		return (NULL);

	add_new->n = n;
	add_new->next = NULL;

	if (idx == 0)
	{
		add_new->next = *head;
		*head = add_new;
		return (add_new);
	}
	for (itr = 0; tempPtr && itr < idx - 1; itr++)
		tempPtr = tempPtr->next;

	if (tempPtr != NULL)
	{
		add_new->next = tempPtr->next;
		tempPtr->next = add_new;
		return (add_new);
	}
	return (NULL);
}
