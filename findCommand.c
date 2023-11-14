#include "monty.h"



void findCom(stack_t **list, m *montyD)
{
	int i;
	instruction_t opCom[] =
	{
		{"push", pushfunc},
		{"pall", pallfunc},
		{NULL, NULL}
	};

	for (i = 0; opCom[i].f; i++)
	{
		if (strcmp(opCom[i].opcode, montyD->command[0]) == 0)
		{
				opCom[i].f(list, montyD);
				break;
		}
	}


}
