#include "monty.h"
/**
 * r_pint - prints top
 * @head: stack head
 * @line_counter: line_number
 * Return: no return
*/
void r_pint(stack_t **head, unsigned int line_counter)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_counter);
		fclose(sub.file);
		free(sub.lncont);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}
