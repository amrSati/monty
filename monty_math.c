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
	if (*stack && (*stack)->next)
	{
		math_op(stack, 1);
		return;
	}

	math_error("add", line_number);
}

/**
 * sub - subtracts th top element from the second of the stack
 * @stack: ...
 * @line_number: ...
 *
 * Return: ...
 */
void sub(stack_t **stack, unsigned int line_number)
{
	if (*stack && (*stack)->next)
	{
		math_op(stack, 2);
		return;
	}

	math_error("sub", line_number);
}

/**
 * _div - divides the second top element by the top element of the stack
 * @stack: ...
 * @line_number: ...
 *
 * Return: ...
 */
void _div(stack_t **stack, unsigned int line_number)
{
	if (*stack && (*stack)->next)
	{
		if (!(*stack)->n)
			div_error(line_number);

		math_op(stack, 3);
		return;
	}

	math_error("div", line_number);
}

/**
 * mul - multiplies the second top element with the top of the stack
 * @stack: ...
 * @line_number: ...
 *
 * Return: ...
 */
void mul(stack_t **stack, unsigned int line_number)
{
	if (*stack && (*stack)->next)
	{
		math_op(stack, 4);
		return;
	}

	math_error("mul", line_number);
}

/**
 * mod - computes the rest of the division of the second top element by the top
 * @stack: ...
 * @line_number: ...
 *
 * Return: ...
 */
void mod(stack_t **stack, unsigned int line_number)
{
	if (*stack && (*stack)->next)
	{
		if (!(*stack)->n)
			div_error(line_number);

		math_op(stack, 5);
		return;
	}

	math_error("mod", line_number);
}
