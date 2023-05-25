#include "monty.h"
/**
 * r_pall - Print list
 * @stack: Double linked list
 * @line_counter: File line execution
 */
void r_pall(stack_t **stack, unsigned int line_counter)
{
	stack_t *tmp = *stack;
	(void) line_counter;

	if (!tmp)
		return;
	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}

/**
 * r_push - Insert a new value in list
 * @stack: Double linked list
 * @line_counter: File line execution
 */
void r_push(stack_t **stack, unsigned int line_counter)
{
	stack_t *tmp = NULL, *tm = *stack;
	char *num;

	num = strtok(NULL, " \r\t\n");
	if (num == NULL || (_isdigit(num) != 0 && num[0] != '-'))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_counter);
		free_all();
		exit(EXIT_FAILURE);
	}
	tmp = malloc(sizeof(stack_t));
	if (!tmp)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_all();
		exit(EXIT_FAILURE);
	}
	tmp->n = atoi(num);
	if (var.MODE == 0 || !*stack)
	{
		tmp->next = *stack;
		tmp->prev = NULL;
		if (*stack)
			(*stack)->prev = tmp;
		*stack = tmp;
	}
	else
	{
		while (tm->next)
			tm = tm->next;
		tm->next = tmp;
		tmp->prev = tm;
		tmp->next = NULL;
	}
}

/**
 * r_pint - Print last node
 * @stack: Double linked list
 * @line_counter: File line execution
 */
void r_pint(stack_t **stack, unsigned int line_counter)
{
	if (!*stack)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_counter);
		free_all();
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

/**
* r_pop - Delete top of list
* @stack: Double linked list
* @line_counter: File line execution
*/
void r_pop(stack_t **stack, unsigned int line_counter)
{
	stack_t *tmp;

	if (!*stack)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_counter);
		free_all();
		exit(EXIT_FAILURE);
	}

	tmp = *stack;
	*stack = tmp->next;
	if (tmp->next)
		tmp->next->prev = NULL;
	free(tmp);
}
