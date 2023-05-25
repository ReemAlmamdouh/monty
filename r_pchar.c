#include "monty.h"
/**
 * r_pchar - prints char
 * @head: stack head
 * @line_number: line number
 * Return: no return
*/
void r_pchar(stack_t **head, unsigned int line counter)
{
	stack_t *h;

	h = *head;
	if (!h)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		fclose(sub.file);
		free(sub.lncont);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	if (h->n > 127 || h->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		fclose(sub.file);
		free(sub.lncont);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", h->n);
}
