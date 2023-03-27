#include "monty.h"

/**
 * math_err - prints math opcodes errors
 * @op: opcode error
 * @line_number: line number
 *
 * Return: non
 */
void math_err(const char *op, unsigned int line_number)
{
	fprintf(stderr, "L%d: can't %s, stack too short\n", line_number, op);
	free_driver();
	exit(EXIT_FAILURE);
}

/**
 * div_err - prints division by zero error
 * @line_number: line number
 *
 * Return: non
 */
void div_err(unsigned int line_number)
{
	fprintf(stderr, "L%d: division by zero\n", line_number);
	free_driver();
	exit(EXIT_FAILURE);
}
