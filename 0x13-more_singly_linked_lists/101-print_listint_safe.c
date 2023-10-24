#include "lists.h"

/**
 * count_nodes_in_loop - Count nodes in a looped list
 * @head: A pointer to the first node of the list
 * Return: Number of nodes in the loop
 */
size_t count_nodes_in_loop(const listint_t *head)
{
	const listint_t *one_nodePtr, *two_nodesPtr;
	size_t nodes = 1;

	if (head == NULL || head->next == NULL)
		return (0);

	one_nodePtr = head->next;
	two_nodesPtr = (head->next)->next;

	while (two_nodesPtr)
	{
		if (one_nodePtr == two_nodesPtr)
		{
			one_nodePtr = head;
			while (one_nodePtr != two_nodesPtr)
			{
				nodes++;
				one_nodePtr = one_nodePtr->next;
				two_nodesPtr = two_nodesPtr->next;
			}

			one_nodePtr = one_nodePtr->next;
			while (one_nodePtr != two_nodesPtr)
			{
				nodes++;
				one_nodePtr = one_nodePtr->next;
			}

			return (nodes);
		}

		one_nodePtr = one_nodePtr->next;
		two_nodesPtr = (two_nodesPtr->next)->next;
	}

	return (0);
}

/**
 * print_listint_safe - Function to print a linked list
 * @head: Pointer to the first node of the list
 * Return: The number of nodes in the list
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t nodes = count_nodes_in_loop(head);

	if (nodes == 0)
	{
		while (head != NULL)
		{
			printf("[%p] %d\n", (void *)head, head->n);
			head = head->next;
			nodes++;
		}
	}
	else
	{
		size_t index = 0;

		while (index < nodes)
		{
			printf("[%p] %d\n", (void *)head, head->n);
			head = head->next;
			index++;
		}

		printf("-> [%p] %d\n", (void *)head, head->n);
	}

	return (nodes);
}
