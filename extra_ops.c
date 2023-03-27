#include "monty.h"

/**
 * pchar - prints the char at the top of the stack
 * @stack: head of stack
 * @line_number: line number in bytecode file
 *
 * Return: non
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	if (*stack && ((*stack)->n >= 0 && (*stack)->n <= 127))
	{
		fprintf(stdout, "%c\n", (*stack)->n);
		return;
	}

	fprintf(stderr, "L%d: can't pchar, ", line_number);
	if (!(*stack))
		fprintf(stderr, "stack empty\n");
	else
		fprintf(stderr, "value out of range\n");

	free_driver();
	exit(EXIT_FAILURE);
}

/**
 * pstr - prints the string starting at the top of the stack
 * @stack: ...
 * @line_number: ...
 *
 * Description: The integer stored in each element of the stack is treated as
 * the ascii value of the character.
 * The string stops when either:
 *	- the stack is over
 *	- the value of the element is 0, or out of ascii range
 *
 * Return: ...
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	char *string;
	size_t size = 0;
	int i = 0;

	UNUSED(line_number);

	if (!tmp)
	{
		fprintf(stdout, "\n");
		return;
	}

	getsize(&size);

	string = malloc((sizeof(char) * size) + 1);
	if (string == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_driver();
		exit(EXIT_FAILURE);
	}
	memset(string, 0, size);

	for (; tmp && tmp->n; tmp = tmp->next, i++)
		string[i] = tmp->n;

	fprintf(stdout, "%s\n", string);
	free(string);
}
