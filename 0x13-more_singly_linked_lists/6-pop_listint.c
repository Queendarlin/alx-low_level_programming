#include "lists.h"

/**
 * pop_listint - Function to delete the head node of a linked list
 * @head: Pointer to a head pointer
 * Return: The value of n
 */
int pop_listint(listint_t **head)
{
	listint_t *tempPtr;
	int data_n;

	if (*head == NULL)
		return (0);

	data_n = (*head)->n;
	tempPtr = *head;
	*head = (*head)->next;

	free(tempPtr);
	return (data_n);
}
