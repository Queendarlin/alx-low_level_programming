#include "lists.h"

/**
 * add_nodeint_end - Function to add a new node to the end of the list
 * @head: Pointer to the head pointer
 * @n: Integer value to add to the new node
 * Return: The address of the new element on success, or NULL on failure
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *temp_node;
	listint_t *currentNode;

	temp_node = malloc(sizeof(listint_t));
	if (temp_node == NULL)
		return (NULL);

	temp_node->n = n;
	temp_node->next = NULL;

	if (*head == NULL)
		*head = temp_node;
	else
	{
		currentNode = *head;
		while (currentNode->next != NULL)
		{
			currentNode = currentNode->next;
		}
		currentNode->next = temp_node;
	}
	return (temp_node);
}
