#include "lists.h"

/**
 * free_list - Fuction to free a linked list
 * @head: Pointer to first node
 */
void free_list(list_t *head)
{
	list_t *holder;

	while (head)
	{
		holder = head->next;
		free(head->str);
		free(head);
		head = holder;
	}
}
