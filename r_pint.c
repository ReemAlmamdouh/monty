#include "monty.h"
/**
 * r_pint - prints top
 * @head: stack head
 * @line_number: line number
 * Return: no return
*/
void r_pint(stack_t **head, unsigned int line_number)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		fclose(sub.file);
		free(sub.lncont);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}
