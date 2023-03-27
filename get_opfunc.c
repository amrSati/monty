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
		{"pop", _pop},
		{NULL, NULL}
	};

	for (i = 0; ops[i].opcode; i++)
		if (!strcmp(opcode, ops[i].opcode))
			break;

	return (ops[i].operation);
}
