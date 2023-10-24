#include "lists.h"

/**
 * reverse_listint - Fuction to reverse a linked list
 * @head: Pointer to the head pointer
 * Return: A pointer to the first node of the reversed list
 */
listint_t *reverse_listint(listint_t **head)
{
	listint_t *firstNode = NULL;
	listint_t *restNode = NULL;

	while (*head)
	{
		restNode = (*head)->next;
		(*head)->next = firstNode;
		firstNode = *head;
		*head = restNode;
	}

	*head = firstNode;

	return (*head);
}
