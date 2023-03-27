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
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_driver();
		exit(EXIT_FAILURE);
	}

	node->n = el;
	node->prev = NULL;
	node->next = *top;
	*top = node;
	if (node->next)
		node->next->prev = node;

	return (node);
}

/**
 * pop - pops an element from top
 * @top: top of the stack
 *
 * Return: the data in the node (-101 on failure)
 */
int pop(stack_t **top)
{
	stack_t *tmp;
	int n;

	tmp = *top;
	*top = (*top)->next;
	n = tmp->n;
	free(tmp);
	tmp = NULL;

	if (*top)
		(*top)->prev = NULL;

	return (n);
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
