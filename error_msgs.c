#include "monty.h"

/**
 * push_error - prints push usage error msg
 * @line_number: line number
 *
 * Return: nothing
 */
void push_error(unsigned int line_number)
{
	fprintf(stderr, "L%d: usage: push integer\n", line_number);
	exit(EXIT_FAILURE);
}

/**
 * math_error - prints math opcodes errors
 * @op: opcode error
 * @line_number: line number
 *
 * Return: non
 */
void math_error(const char *op, unsigned int line_number)
{
	fprintf(stderr, "L%d: can't %s, stack too short\n", line_number, op);
	free_driver();
	exit(EXIT_FAILURE);
}

/**
 * div_error - prints division by zero error
 * @line_number: line number
 *
 * Return: non
 */
void div_error(unsigned int line_number)
{
	fprintf(stderr, "L%d: division by zero\n", line_number);
	free_driver();
	exit(EXIT_FAILURE);
}

/**
 * malloc_error - prints malloc failure error
 *
 * Return: ...
 */
void malloc_error(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	free_driver();
	exit(EXIT_FAILURE);
}
