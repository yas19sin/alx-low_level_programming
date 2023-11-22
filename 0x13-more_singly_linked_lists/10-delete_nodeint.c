#include "lists.h"
/**
 * delete_nodeint_at_index - Deletes the node at a given position.
 * @head: A pointer to the pointer to the head of the list.
 * @index: The index of the node to delete, starting at 0.
 * Return: 1 if succeeded, -1 if it failed.
*/
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *temp, *del;
	unsigned int i = 0;

	if (head == NULL || *head == NULL)
		return (-1);

	temp = *head;

	if (index == 0)
	{
		*head = temp->next;
		free(temp);
		return (1);
	}

	while (temp != NULL && i < index - 1)
	{
		temp = temp->next;
		i++;
	}

	if (temp == NULL || temp->next == NULL)
		return (-1);

	del = temp->next;
	temp->next = del->next;
	free(del);

	return (1);
}
