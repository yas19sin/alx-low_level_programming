#include "lists.h"
/**
 * sum_listint - Returns the sum of all the data (n) of a listint_t list.
 * @head: A pointer to the head of the list.
 * Return: The sum of all data in the list.
*/
int sum_listint(listint_t *head)
{
	int sum = 0;

	while (head != NULL)
	{
		sum += head->n;
		head = head->next;
	}

	return (sum);
}
