#include "monty.h"
/**
 * r_div - divides top 2 elements
 * @head: stack head
 * @line_counter: line_number
 * Return: no return
*/
void r_div(stack_t **head, unsigned int line_counter)
{
	stack_t *h;
	int len = 0, aux;

	h = *head;
	while (h)
	{
		h = h->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_counter);
		fclose(sub.file);
		free(sub.lncont);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	if (h->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_counter);
		fclose(sub.file);
		free(sub.lncont);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	aux = h->next->n / h->n;
	h->next->n = aux;
	*head = h->next;
	free(h);
}