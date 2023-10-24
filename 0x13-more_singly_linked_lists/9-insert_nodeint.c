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

