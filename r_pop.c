#include "monty.h"
/**
 * r_pop - prints top
 * @head: stack head
 * @line_counter: line_number
 * Return: no return
*/
void r_pop(stack_t **head, unsigned int line_counter)
{
	stack_t *h;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_counter);
		fclose(sub.file);
		free(sub.lncont);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	*head = h->next;
	free(h);
}
