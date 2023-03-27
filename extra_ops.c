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
