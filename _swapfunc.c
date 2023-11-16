#include "monty.h"

/**
 * swapfunc - swaps the first two values in the stack
 *
 * @stack: a doubly linked list
 * @montyD: pointer to m
 *
 */

void swapfunc(stack_t **stack, m *montyD)
{
	stack_t *node1 = *stack, *node2;

	if ((stack == NULL) || (node1 == NULL))
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n",
			montyD->lineNum);
		fclose(montyD->file);
		free(montyD->line);
		freeNode(*stack);
		exit(EXIT_FAILURE);
	}
	node2 = node1->next;
	if (node2 == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n",
			montyD->lineNum);
		fclose(montyD->file);
		free(montyD->line);
		freeNode(*stack);
		exit(EXIT_FAILURE);
	}

	if (node2->next == NULL)
	{
		node1->prev = node2;
		node2->next = node1;
		node1->next = NULL;
		node2->prev = NULL;
		*stack = node2;
	}
	else
	{
		node1->next = node2->next;
		node2->next->prev = node1;
		node1->prev = node2;
		node2->next = node1;
		node2->prev = NULL;
		*stack = node2;
	}
}
