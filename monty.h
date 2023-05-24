#ifndef MONTY_H
#define MONTY_H

/* libraries */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
/**
 * struct sub_s - variables -args, file, line content
 * @file: pointer to monty file
 * @arg: value
 * @flag: flag change stack <-> queue
 * @lncont: line content
 * Description: it carries the variables
 */
typedef struct sub_s
{
	char *arg;
	FILE *file;
	char *lncont;
	int flag;
}  sub_t;
extern sub_t sub;

/* prototypes of functions */
char *_realloc(char *ptr, unsigned int old_size, unsigned int new_size);
ssize_t getstdin(char **lineptr, int file);
char  *clean_line(char *lncont);
void r_push(stack_t **head, unsigned int number);
void r_pall(stack_t **head, unsigned int number);
void r_pint(stack_t **head, unsigned int number);
int execute(char *lncont, stack_t **head, unsigned int line_counter, FILE *file);
void free_stack(stack_t *head);
void r_pop(stack_t **head, unsigned int line_counter);
void r_swap(stack_t **head, unsigned int line_counter);
void r_add(stack_t **head, unsigned int line_counter);
void r_nop(stack_t **head, unsigned int line_counter);
void r_sub(stack_t **head, unsigned int line_counter);
void r_div(stack_t **head, unsigned int line_counter);
void r_mul(stack_t **head, unsigned int line_counter);
void r_mod(stack_t **head, unsigned int line_counter);
void r_pchar(stack_t **head, unsigned int line_counter);
void r_pstr(stack_t **head, unsigned int line_counter);
void r_rotl(stack_t **head, unsigned int line_counter);
void r_rotr(stack_t **head, __attribute__((unused)) unsigned int line_counter);
void addnod(stack_t **head, int n);
void addque(stack_t **head, int n);
void f_queue(stack_t **head, unsigned int line_counter);
void f_stack(stack_t **head, unsigned int line_counter);
#endif
