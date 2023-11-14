#include "monty.h"




void (findCom(char *command))(stack_t **, unsigned int)
{
	int i;
	instruction_t opCom[] =
	{
		{"push", pushfunc},
		{"pall", pallfunc},
		{NULL, NULL}
	};

	for (i = 0; opCom[i]; i++)
	{
		if (strcmp(opCom[i].opcode, command) == 0)
			break;
	}
	return (opCom[i].f);

}