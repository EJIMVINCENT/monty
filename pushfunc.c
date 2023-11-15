#include "monty.h"


/**
 * pushfunc - add node to the stack or queue
 *
 * @list: pointer to stack list
 * @montyD: pointer to m struct
 *
 */

void pushfunc(stack_t **list, m *montyD)
{
	int n, j = 0, flag = 0;

	if (montyD->arg)
	{
		if (montyD->arg[0] == '-')
			j++;
		for (; montyD->arg[j] != '\0'; j++)
		{
			if (montyD->arg[j] > '9' || montyD->arg[j] < '0')
			{
				flag = 1; 
				break;
			}
		}
		if (flag == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", montyD->lineNum);
			fclose(montyD->file);
			free(montyD->line);
			freeNode(*list);
			exit(EXIT_FAILURE);  
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", montyD->lineNum);
		fclose(montyD->file);
		free(montyD->line);
		freeNode(*list);
		exit(EXIT_FAILURE); 
	}
	n = atoi(montyD->arg);
	if (montyD->isQ)
		addNodeEnd(list, n);
	else
		addNodeStart(list, n);
}
