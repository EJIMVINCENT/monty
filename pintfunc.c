#include "monty.h"

/**
 * pintfunc - prints the top of the list
 *
 * @list: pointer stack_t struct head
 * @montyD: pointer to m struct head
 *
 */

void pintfunc(stack_t **list, m *montyD)
{
	if (*list == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", montyD->lineNum);
		fclose(montyD->file);
		free(montyD->line);
		freeNode(*list);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*list)->n);
}
