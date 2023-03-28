#include "monty.h"

/**
 * push - pushes element into stack
 * @top: top of stack
 * @el: element to push
 *
 * Return: node that pushed to stack (on success)
 */
stack_t *push(stack_t **top, int el)
{
	stack_t *node = NULL;

	node = malloc(sizeof(stack_t));
	if (!node)
		malloc_error();

	node->n = el;
	node->prev = NULL;
	node->next = *top;
	*top = node;
	if (node->next)
		node->next->prev = node;

	return (node);
}

/**
 * pop - removes the element at the top of the stack
 * @stack: head of stack
 * @line_number: line number in bytecode file
 *
 * Return: non
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (!(*stack))
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		free_driver();
		exit(EXIT_FAILURE);
	}

	tmp = *stack;
	*stack = (*stack)->next;
	if (*stack)
		(*stack)->prev = NULL;

	free(tmp);
	tmp = NULL;
}

/**
 * free_stack - frees stack from memory
 * @top: top of stack
 *
 * Return: nothing
 */
void free_stack(stack_t *top)
{
	if (!top)
		return;

	free_stack(top->next);

	free(top);
}
