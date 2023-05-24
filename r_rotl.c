#include "monty.h"
/**
  *r_rotl- function that rotates stack
  *@head: stack head
  *@line_counter: line_number
  *Return: no return
 */
void r_rotl(stack_t **head,  __attribute__((unused)) unsigned int line_counter)
{
	stack_t *tmp = *head, *aux;

	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	aux = (*head)->next;
	aux->prev = NULL;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = *head;
	(*head)->next = NULL;
	(*head)->prev = tmp;
	(*head) = aux;
}
