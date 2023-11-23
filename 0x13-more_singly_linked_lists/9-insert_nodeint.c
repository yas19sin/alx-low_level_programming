#include "lists.h"
/**
 * insert_nodeint_at_index - Inserts a new node at a given position.
 * @head: A pointer to the pointer to the head of the list.
 * @idx: The index of the node to insert, starting at 0.
 * @n: The data to be added to the new node.
 * Return: The address of the new node, or NULL if it failed.
*/
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *new_node, *temp;
	unsigned int i = 0;

	if (*head == NULL && idx != 0)
		return (NULL);

	if (idx != 0)
	{
		temp = *head;

		for (; i < idx - 1 && temp != NULL; i++)
			temp = temp->next;

		if (temp == NULL)
			return (NULL);
	}

	new_node = malloc(sizeof(listint_t));

	if (new_node == NULL)
		return (NULL);

	new_node->n = n;

	if (index == 0)
	{
		new_node->next = *head;
		*head = new_node;
		return (new_node);
	}

	new_node->next = temp->next;
	temp->next = new_node;

	return (new_node);
}
