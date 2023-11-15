#include "monty.h"

/**
 * pop_Op - removes a value from the top of a stack
 * @stack: a doubly linked list
 * @montyD: pointer to m
 */
void pop_Op(stack_t **stack, m *montyD)
{
	stack_t *current = *stack;

	if ((current == NULL) || (stack == NULL))
	{
		fprintf(stderr, "L%s: can't pop an empty stack\n",
			montyD->line);
		exit(EXIT_FAILURE);
	}
	*stack = current->next;
	if (current->next != NULL)
		current->next->prev = NULL;
	free(current);
}


/**
 * swap_Op - swaps the first two values in the stack
 * @stack: a doubly linked list
 * @montyD: pointer to m
 */
void swap_Op(stack_t **stack, m *montyD)
{
	stack_t *node1 = *stack, *node2;

	if ((stack == NULL) || (node1 == NULL))
	{
		fprintf(stderr, "L%s: can't swap, stack too short\n",
			montyD->line);
		exit(EXIT_FAILURE);
	}
	node2 = node1->next;
	if (node2 == NULL)
	{
		fprintf(stderr, "L%s: can't swap, stack too short\n",
			montyD->line);
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


/**
 * mod_Op - computes remainder of division of top second element by first
 * element of stack
 * @stack: pointer to the stack
 * @montyD: pointer to m
 */
void mod_Op(stack_t **stack, m *montyD)
{
	stack_t *node1 = *stack, *node2;

	if ((stack == NULL) || (node1 == NULL))
	{
		fprintf(stderr, "L%s: can't mod, stack too short\n",
			montyD->line);
		exit(EXIT_FAILURE);
	}
	node2 = node1->next;
	if (node2 == NULL)
	{
		fprintf(stderr, "L%s: can't mod, stack too short\n",
			montyD->line);
		exit(EXIT_FAILURE);
	}
	if (node1->n == 0)
	{
		fprintf(stderr, "L%s: division by zero\n", montyD->line);
		exit(EXIT_FAILURE);
	}
	node2->n %= node1->n;
	*stack = node2;
	node2->prev = NULL;
	free(node1);
}
