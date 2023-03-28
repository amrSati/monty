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
		malloc_error();

	memset(string, 0, size);

	for (; tmp && tmp->n; tmp = tmp->next, i++)
	{
		if (tmp->n < 1 || tmp->n > 127)
			break;

		string[i] = tmp->n;
	}

	fprintf(stdout, "%s\n", string);
	free(string);
}

/**
 * rotl - rotates the stack to the top
 * @stack: ...
 * @line_number: ...
 *
 * Description: The top element of the stack becomes the last one,
 *	and the second top element becomes the top of stack.
 *	rotl never fails.
 *
 * Return: ...
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *top, *last;

	UNUSED(line_number);

	if (!(*stack))
		return;

	top = *stack;
	last = (*stack)->next;
	while (last && last->next)
		last = last->next;

	if (!last)
		return;

	*stack = (*stack)->next;
	(*stack)->prev = NULL;

	top->next = NULL;
	top->prev = last;
	last->next = top;
}

/**
 * rotr - rotates the stack to the bottom
 * @stack: ...
 * @line_number: ...
 *
 * Description: The last element of the stack becomes
 * the top element of the stack
 *
 * Return: ...
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *top, *bottom;

	UNUSED(line_number);

	if (!(*stack))
		return;

	top = *stack;
	bottom = (*stack)->next;
	while (bottom && bottom->next)
		bottom = bottom->next;

	if (!bottom)
		return;

	bottom->next = top;
	top->prev = bottom;
	bottom->prev->next = NULL;
	bottom->prev = NULL;
	*stack = bottom;
}
