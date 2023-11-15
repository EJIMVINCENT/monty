#include "monty.h"


/**
 * popfunc - removes the top element of the stack.
 *
 * @list: pointer to stack_t struct
 * @montyD: line_number
 *
 */

void popfunc(stack_t **list, m *montyD)
{
	stack_t *temp;

	if (*list == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", montyD->lineNum);
		fclose(montyD->file);
		free(montyD->line);
		freeNode(*list);
		exit(EXIT_FAILURE);
	}
	temp = *list;
	*list = temp->next;
	free(temp);
}

