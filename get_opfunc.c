#include "monty.h"

/**
 * get_opfunc - finds the op function that matches the given opcode
 * @opcode: opcode string
 *
 * Return: op function (if found)
 */
opfunc get_opfunc(char *opcode)
{
	int i;
	instruction_t ops[] = {
		{"push", _push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", _div},
		{"mul", mul},
		{"mod", mod},
		{NULL, NULL}
	};

	for (i = 0; ops[i].opcode; i++)
		if (!strcmp(opcode, ops[i].opcode))
			break;

	return (ops[i].operation);
}
