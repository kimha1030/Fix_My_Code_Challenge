#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - Delete a node at a specific index from a list
 *
 * @head: A pointer to the first element of a list
 * @index: The index of the node to delete
 *
 * Return: 1 on success, -1 on failure
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *saved_head = NULL;
	dlistint_t *aux;
	unsigned int p, cont;

	aux = *head;
	if (*head == NULL)
	{
		return (-1);
	}
	cont = dlistint_len(*head);
	if (index >= cont)
	{
		return (-1);
	}
	if (index == 0 && cont > 0)
	{
		saved_head = *head;
		*head = (*head)->next;
		free(saved_head);
		return (1);
	}
	if (cont != 1)
		(*head)->prev = NULL;
	p = 0;
	while (p < index)
	{
		aux = aux->next;
		p++;
	}
	aux->prev->next = aux->next;
	if (index != cont - 1)
	{
		aux->next->prev = aux->prev;
	}
	free(aux);
	return (1);
}

/**
 * dlistint_len - prints number elements of a dlist_t listint.
 * @h: pointer to head
 * Return: i
 */
size_t dlistint_len(const dlistint_t *h)
{
	int i;
	const dlistint_t *aux = h;

	for (i = 0; aux != NULL; i++)
		aux = aux->next;
	return (i);
}
