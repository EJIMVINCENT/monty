<<<<<<< HEAD
#include "monty.h"



void executeCom(stack_t **list, m *montyD)
{
	char *command;
	int i;
	instruction_t opCom[] =
	{
		{"push", pushfunc},
		{"pall", pallfunc},
		{"add", addfunc},
		{"sub", subfunc},
		{"swap", swapfunc},
		{"div", divfunc},
		{"mul", mulfunc},
		{"pop", popfunc},
		{"mod", modfunc},
		{"nop", nopfunc},
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
=======
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
		{"pop", popfunc},
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
>>>>>>> b7ef294a5a3fd34e2f2a9372482bc103ddfd4ad8
