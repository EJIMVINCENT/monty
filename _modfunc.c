#include "monty.h"


/**
 * modfunc - computes remainder of division of top second element by first
 * element of stack
 *
 * @stack: pointer to the stack
 * @montyD: pointer to m
 *
 */

void modfunc(stack_t **stack, m *montyD)
{
	stack_t *node1 = *stack, *node2;

	if ((stack == NULL) || (node1 == NULL))
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n",
			montyD->lineNum);
		fclose(montyD->file);
		free(montyD->line);
		freeNode(*stack);
		exit(EXIT_FAILURE);
	}
	node2 = node1->next;
	if (node2 == NULL)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n",
			montyD->lineNum);
		fclose(montyD->file);
		free(montyD->line);
		freeNode(*stack);
		exit(EXIT_FAILURE);
	}
	if (node1->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", montyD->lineNum);
		fclose(montyD->file);
		free(montyD->line);
		freeNode(*stack);
		exit(EXIT_FAILURE);
	}
	node2->n %= node1->n;
	*stack = node2;
	node2->prev = NULL;
	free(node1);
}
