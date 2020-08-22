#include <string.h>
#include <stdlib.h>
#include "lists.h"

/**
 * free_dlistint - Free a list
 *
 * @head: A pointer to the first element of the list
 */
void free_dlistint(dlistint_t *head)
{
	dlistint_t *aux;
	dlistint_t *p;

	aux = head;
	while (aux != NULL)
	{
		p = aux->next;
		free(aux);
		aux = p;
	}
}
