#include "monty.h"

/**
 * _push - monty push operation
 * @stack: head of stack to push into
 * @line_number: line number in bytecode file
 *
 * Return: nothing
 */
void _push(stack_t **stack, unsigned int line_number)
{
	int n, i = 0;

	if (!driver->arg)
		push_usage_err(line_number);

	if (driver->arg[0] == '-')
		i++;

	for (; driver->arg[i]; i++)
		if (!isdigit(driver->arg[i]))
			push_usage_err(line_number);

	n = atoi(driver->arg);
	push(stack, n);
}

/**
 * pall - prints all elements of stack to stdout
 * @stack: head of stack
 * @line_number: line number in bytecode file
 *
 * Return: non
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	UNUSED(line_number);

	if (!tmp)
		return;

	fprintf(stdout, "%d\n", tmp->n);
	pall(&(tmp->next), line_number);
}

/**
 * pint - prints the value at the top of the stack
 * @stack: head of stack
 * @line_number: line number in bytecode file
 *
 * Return: non
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (!(*stack))
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	fprintf(stdout, "%d\n", (*stack)->n);
}
