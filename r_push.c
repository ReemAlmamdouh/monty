#include "monty.h"

/**
 * r_push - pushes an element onto the stack
 * @stack: pointer to the top of the stack
 * @line_counter: current line number of the opcode in the Monty file
 */
void r_push(stack_t **stack, unsigned int line_counter)
{
	int n;

	if (sub.arg == NULL || !is_number(sub.arg))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_counter);
		free_stack(*stack);
		fclose(sub.file);
		free(sub.line);
		exit(EXIT_FAILURE);
	}

	n = atoi(sub.arg);
	if (add_node(stack, n) == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_stack(*stack);
		fclose(sub.file);
		free(sub.line);
		exit(EXIT_FAILURE);
	}
}

/**
 * is_number - checks if a string is a number
 * @str: string to check
 *
 * Return: 1 if string is a number, 0 otherwise
 */
int is_number(char *str)
{
	if (str == NULL || *str == '\0')
		return (0);

	if (*str == '-' || *str == '+')
		str++;

	while (*str != '\0')
	{
		if (*str < '0' || *str > '9')
			return (0);

		str++;
	}

	return (1);
}
