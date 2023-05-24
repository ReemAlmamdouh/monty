#include "monty.h"
/**
 * r_queue - prints the top
 * @head: stack head
 * @line_counter: line_number
 * Return: no return
*/
void r_queue(stack_t **head, unsigned int line_counter)
{
	(void)head;
	(void)line_counter;
	sub.lifi = 1;
}

/**
 * addque - adds node to tail
 * @n: new_value
 * @head: head of the stack
 * Return: no return
*/
void addque(stack_t **head, int n)
{
	stack_t *new_node, *aux;

	aux = *head;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error\n");
	}
	new_node->n = n;
	new_node->next = NULL;
	if (aux)
	{
		while (aux->next)
			aux = aux->next;
	}
	if (!aux)
	{
		*head = new_node;
		new_node->prev = NULL;
	}
	else
	{
		aux->next = new_node;
		new_node->prev = aux;
	}
}
