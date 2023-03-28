#include "monty.h"

struct global_var *driver;

/**
 * main - monty bytecode interpreter
 * @argc: number of arguments (must be 2)
 * @argv: array of arguments
 *
 * Return: EXIT_SUCCESS on success
 */
int main(int argc, char **argv)
{
	opfunc operation;
	FILE *bc_file;
	char *token;
	size_t line_size = 0;
	ssize_t read;

	check_usage(&bc_file, argc, argv);

	driver_init(bc_file);

	read = getline(&(driver->line), &line_size, bc_file);
	while (read != -1)
	{
		token = strtok(driver->line, " \t\n");
		if (token && *token != '#')
		{
			operation = get_opfunc(token);
			if (!operation)
			{
				fprintf(stderr, "L%d: ", driver->line_number);
				fprintf(stderr, "unknown instruction %s\n", token);
				free_driver();
				exit(EXIT_FAILURE);
			}
			driver->arg = strtok(NULL, " \t\n");

			operation(&(driver->head), driver->line_number);
		}

		driver->line_number++;
		read = getline(&(driver->line), &line_size, bc_file);
	}


	free_driver();
	exit(EXIT_SUCCESS);
}
