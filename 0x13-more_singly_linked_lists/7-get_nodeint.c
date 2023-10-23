#include "lists.h"

/**
 * get_nodeint_at_index - Fuction to return the nth node of a linked list
 * @head: Pointer to the first node of the list
 * @index: Index of the node
 * Return: The nth node on success, or Null on failure
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int count_node = 0;

	while (head != NULL)
	{
		if (count_node == index)
			return (head);
		head = head->next;
		count_node++;
	}
	return (NULL);
}
