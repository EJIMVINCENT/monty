#include "monty.h"

/**
 * executeCom - executes a command
 *
 * @list: pointer to a stack_t struct
 * @montyD: pointer to m struct
 *
 */

void executeCom(stack_t **list, m *montyD)
{
	char *command;
	int i;
	instruction_t opCom[] = {
		{"push", pushfunc},
		{"pall", pallfunc},
		{"pint", pintfunc},
		{"add", addfunc},
		{"sub", subfunc},
		{"swap", swapfunc},
		{"div", divfunc},
		{"mul", mulfunc},
		{"pop", popfunc},
		{"mod", modfunc},
		{"nop", nopfunc},
<<<<<<< HEAD
		{"pchar", pcharfunc},
		{"pstr", pstrfunc},
=======
		{"rot1", rot1func},
>>>>>>> 6dd0d2477acaa9ffbdd9bfe6c356c7f84650cda5
		{NULL, NULL}
	};

	command = strtok(montyD->line, DELIM);
	if (command && command[0] == '#')
		return;

	montyD->arg = strtok(NULL, DELIM);

	for (i = 0; opCom[i].f && command; i++)
	{
		if (strcmp(opCom[i].opcode, command) == 0)
		{
			opCom[i].f(list, montyD);
			return;
		}
	}
	if (command && opCom[i].f == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", montyD->lineNum, command);
		fclose(montyD->file);
		free(montyD->line);
		freeNode(*list);
		exit(EXIT_FAILURE);
	}
}
