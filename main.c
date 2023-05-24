#include "monty.h"
sub_t sub = {NULL, NULL, NULL, 0};
/**
* main - interpreter
* @argc: no of arguments
* @argv: location
* Return: 0 on success
*/
int main(int argc, char *argv[])
{
	char *lncont;
	FILE *file;
	size_t size = 0;
	ssize_t scan_line = 1;
	stack_t *stack = NULL;
	unsigned int line_counter = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	sub.file = file;
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (scan_line > 0)
	{
		lncont = NULL;
		scan_line = getline(&lncont, &size, file);
		sub.lncont = lncont;
		line_counter++;
		if (scan_line > 0)
		{
			execute(lncont, &stack, line_counter, file);
		}
		free(lncont);
	}
	free_stack(stack);
	fclose(file);
return (0);
}
