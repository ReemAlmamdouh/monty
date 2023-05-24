#include "monty.h"
/**
 * r_pall - prints the stack
 * @head: stack head
 * @line_counter: not used
 * Return: no return
*/
void r_pall(stack_t **head, unsigned int line_counter)
{
	stack_t *h;
	(void)line_counter;

	h = *head;
	if (h == NULL)
		return;
	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}
