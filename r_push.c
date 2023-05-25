#include "monty.h"
/**
 * r_push - function that adds node to the stack
 * @head: stack head
 * @line_counter: line_number
 * Return: no return
*/
void r_push(stack_t **head, unsigned int line_counter)
{
        int n, f = 0, glab = 0;

        if (sub.arg)
        {
                if (sub.arg[0] == '-')
                        f++;
                for (; sub.arg[f] != '\0'; f++)
                {
                        if (sub.arg[f] > 57 || sub.arg[f] < 48)
                                glab = 1; }
                if (glab == 1)
                { fprintf(stderr, "L%d: usage: push integer\n", line_counter);
                        fclose(sub.file);
                        free(sub.lncont);
                        free_stack(*head);
                        exit(EXIT_FAILURE); }}
        else
        { fprintf(stderr, "L%d: usage: push integer\n", line_counter);
                fclose(sub.file);
                free(sub.lncont);
                free_stack(*head);
                exit(EXIT_FAILURE); }
        n = atoi(sub.arg);
        if (sub.lifi == 0)
                addnod(head, n);
        else
                addque(head, n);
}
