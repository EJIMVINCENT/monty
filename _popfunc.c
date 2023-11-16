#include "monty.h"

/**
 * popfunc - removes a value from the top of a stack
 *
 * @stack: a doubly linked list
 * @montyD: pointer to m
 *
 */

void popfunc(stack_t **stack, m *montyD)
{
	stack_t *current = *stack;

	if ((current == NULL) || (stack == NULL))
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", montyD->lineNum);
		fclose(montyD->file);
		free(montyD->line);
		freeNode(*stack);
		exit(EXIT_FAILURE);
	}
	*stack = current->next;
	if (current->next != NULL)
		current->next->prev = NULL;
	free(current);
}
