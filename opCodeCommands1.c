#include "monty.h"




void pushfunc(stack_t **list, m *montyD)
{
	int n; 

	if (!montyD->command[1] || !checkNum(montyD->command[1]))
	{
		fprintf(stderr, "L%d: usage: push integer\n", montyD->lineNum);
		fclose(montyD->file);
		free(montyD->line);
		free(montyD->command);
		freeNode(*list);
		exit(EXIT_FAILURE);
	}
	n = atoi(montyD->command[1]);

	if (montyD->isQ)
		addNodeEnd(list, n);
	else
		addNodeStart(list, n);

}

