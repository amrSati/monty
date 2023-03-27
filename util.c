#include "monty.h"

FILE *check_usage(FILE **bc_file, int argc, char **argv)
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	*bc_file = fopen(*(argv + 1), "r");
	if (*bc_file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", *(argv + 1));
		exit(EXIT_FAILURE);
	}

	return (*bc_file);
}

/**
 * driver_init - initializes global variable structure
 * @bc_file: bytecodes file pointer
 *
 * Return: nothing
 */
void driver_init(FILE *bc_file)
{
	driver = malloc(sizeof(struct global_var));
	if (!driver)
	{
		fprintf(stderr, "Can't allocate memory");
		fclose(bc_file);
		exit(EXIT_FAILURE);
	}

	driver->bc_file = bc_file;
	driver->line_number = 1;
	driver->head = NULL;
	driver->arg = NULL;
	driver->line = NULL;
}

/**
 * free_driver - frees global variable from memory
 *
 * Return: nothing
 */
void free_driver(void)
{
	fclose(driver->bc_file);
	free_stack(driver->head);
	free(driver->line);
	free(driver);
}

/**
 * push_usage_err - prints push usage error msg
 * @line_number: line number
 *
 * Return: nothing
 */
void push_usage_err(unsigned int line_number)
{
	fprintf(stderr, "L%d: usage: push integer\n", line_number);
	exit(EXIT_FAILURE);
}

/**
 * math_op - does the math operation based on the given flag
 * @stack: head of stack
 * @op: flag to choose the correct operator
 *
 * Return: non
 */
void math_op(stack_t **stack, unsigned int op)
{
	switch (op)
	{
		case 1:
			(*stack)->next->n += (*stack)->n;
			break;
		case 2:
			(*stack)->next->n -= (*stack)->n;
			break;
		default:
			break;
	}

	*stack = (*stack)->next;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
