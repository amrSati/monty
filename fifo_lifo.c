#include "monty.h"

/**
 * lifo - implementation of stack opcode
 * @stack: head of stack
 * @line_number: line number in bytecode file
 *
 * Description: The opcode "stack" sets the format of the data
 * to a stack (LIFO).
 *	This is the default behavior of the program.
 *	The front of the queue becomes the top of the stack.
 *
 * Return: nothing
 */
void lifo(stack_t **stack, unsigned int line_number)
{
	UNUSED(line_number);
	UNUSED(stack);

	driver->islifo = 1;
}

/**
 * queue - sets the format of the data to a queue (FIFO)
 * @stack: ...
 * @line_number: ...
 *
 * Description: The top of the stack becomes the front of the queue.
 * Return: ...
 */
void queue(stack_t **stack, unsigned int line_number)
{
	UNUSED(line_number);
	UNUSED(stack);

	driver->islifo = 0;
}

/**
 * enqueue - inserts element into queue
 * @stack: ...
 * @n: element
 *
 * Return: pointer to new node
 */
stack_t *enqueue(stack_t **stack, int n)
{
	stack_t *tmp = *stack, *node;

	node = malloc(sizeof(stack_t));
	if (!node)
		malloc_error();

	node->n = n;
	node->next = NULL;

	if (!(*stack))
	{
		node->prev = NULL;
		*stack = node;
	}
	else
	{
		while (tmp->next)
			tmp = tmp->next;

		tmp->next = node;
		node->prev = tmp;
	}

	return (node);
}
