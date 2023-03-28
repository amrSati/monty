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
		push_error(line_number);

	if (driver->arg[0] == '-')
		i++;

	for (; driver->arg[i]; i++)
		if (!isdigit(driver->arg[i]))
			push_error(line_number);

	n = atoi(driver->arg);
	if (driver->islifo)
		push(stack, n);
	else
		enqueue(stack, n);
}

/**
 * pall - prints all elements of stack to stdout
 * @stack: ...
 * @line_number: ...
 *
 * Return: ...
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
 * @stack: ...
 * @line_number: ...
 *
 * Return: ...
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

/**
 * swap - swaps the top two elements of the stack
 * @stack: ...
 * @line_number: ...
 *
 * Return: ...
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *first, *second;

	if (*stack && (*stack)->next)
	{
		first = *stack;
		second = (*stack)->next;

		if (second->next)
			second->next->prev = first;

		first->next = second->next;
		second->next = first;
		first->prev = second;
		second->prev = NULL;
		*stack = second;
		return;
	}

	fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
	free_driver();
	exit(EXIT_FAILURE);
}

/**
 * nop - doesn't do anything
 * @stack: ...
 * @line_number: ...
 *
 * Return: non
 */
void nop(stack_t **stack, unsigned int line_number)
{
	UNUSED(stack);
	UNUSED(line_number);
}
