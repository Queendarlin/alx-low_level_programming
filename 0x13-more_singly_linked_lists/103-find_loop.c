#include "lists.h"

/**
 * find_listint_loop - Function to find the loop in a linked list
 * @head: Pointer to first node of the list
 * Return: Address of the node where looping starts on success or NULL
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *one_node, *two_nodes;

	if (head == NULL)
		return (NULL);

	one_node = head;
	two_nodes = head;

	while (two_nodes && two_nodes->next)
	{
		one_node = one_node->next;
		two_nodes = two_nodes->next->next;

		if (one_node == two_nodes)
		{
			one_node = head;
			while (one_node != two_nodes)
			{
				one_node = one_node->next;
				two_nodes = two_nodes->next;
			}
			return (one_node);
		}
	}

	return (NULL);
}
