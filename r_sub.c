#include "monty.h"
/**
  *r_sub- sustration
  *@head: stack head
  *@line_number: line number
  *Return: no return
 */
void r_sub(stack_t **head, unsigned int line_number)
{
	stack_t *aux;
	int sus, nodes;

	aux = *head;
	for (nodes = 0; aux != NULL; nodes++)
		aux = aux->next;
	if (nodes < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		fclose(sub.file);
		free(sub.lncont);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	aux = *head;
	sus = aux->next->n - aux->n;
	aux->next->n = sus;
	*head = aux->next;
	free(aux);
i}
