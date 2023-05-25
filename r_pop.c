#include "monty.h"
/**
 * r_pop - prints top
 * @head: stack head
 * @line_number: line number
 * Return: no return
*/
void r_pop(stack_t **head, unsigned int line_number)
{
	stack_t *h;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		fclose(sub.file);
		free(sub.lncont);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	*head = h->next;
	free(h);
}
