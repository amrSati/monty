#include "monty.h"

/**
 * add - adds the top two elements of the stack
 * @stack: head of stack
 * @line_number: line number in bytecode file
 *
 * Description: The result is stored in the second top element of the stack,
 * and the top element is removed, so that at the end:
 * - The top element of the stack contains the result
 * - The stack is one element shorter
 *
 * Return: non
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (*stack && (*stack)->next)
	{
		tmp = *stack;
		tmp->next->n += tmp->n;
		tmp->next->prev = NULL;
		*stack = (*stack)->next;
		free(tmp);
		tmp = NULL;
		return;
	}

	fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
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
