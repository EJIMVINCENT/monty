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
		{"push", pushfunc}, {"pall", pallfunc},
		{"pint", pintfunc}, {"add", addfunc},
		{"sub", subfunc}, {"swap", swapfunc},
		{"div", divfunc}, {"mul", mulfunc},
		{"pop", popfunc}, {"mod", modfunc},
		{"nop", nopfunc}, {"pchar", pcharfunc},
		{"pstr", pstrfunc}, {"rotl", rot1func},
		{"rotr", rotrfunc}, {"queue", queuefunc},
		{"stack", stackfunc}, {NULL, NULL}
	};

	command = strtok(montyD->line, DELIM);
	if (command && command[0] == '#')
		return;

	montyD->arg = strtok(NULL, DELIM);

	for (i = 0; opCom[i].opcode && command; i++)
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
