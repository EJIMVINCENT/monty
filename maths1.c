#include "monty.h"

/**
 * add_Op - adds the first two values in the stack
 * stores the result in the second element of the stack then pops first element
 * @stack: a doubly linked list
 * @montyD: poiter to m
 */
void add_Op(stack_t **stack, m *montyD)
{
	stack_t *node1 = *stack, *node2;

	if ((stack == NULL) || (node1 == NULL))
	{
		fprintf(stderr, "L%s: can't add, stack too short\n",
			montyD->line);
		exit(EXIT_FAILURE);
	}

	node2 = node1->next;
	if (node2 == NULL)
	{
		fprintf(stderr, "L%s: can't add, stack too short\n",
			montyD->line);
		exit(EXIT_FAILURE);
	}

	node2->n += node1->n;
	*stack = node2;
	node2->prev = NULL;
	free(node1);
}


/**
 * sub_Op - subtracts top element of stack from second element of stack
 * @stack: pointer to the stack
 * @montyD: pointer to m
 */
void sub_Op(stack_t **stack, m *montyD)
{
	stack_t *node1 = *stack, *node2;

	if ((stack == NULL) || (node1 == NULL))
	{
		fprintf(stderr, "L%s: can't sub, stack too short\n",
			montyD->line);
		exit(EXIT_FAILURE);
	}
	node2 = node1->next;
	if (node2 == NULL)
	{
		fprintf(stderr, "L%s: can't sub, stack too short\n",
			montyD->line);
		exit(EXIT_FAILURE);
	}
	node2->n -= node1->n;
	*stack = node2;
	node2->prev = NULL;
	free(node1);
}


/**
 * mul_Op - multiplies the second and first elements of the stack
 * @stack: pointer to the stack
 * @montyD: pointer to m
 */
void mul_Op(stack_t **stack, m *montyD)
{
	stack_t *node1 = *stack, *node2;

	if ((stack == NULL) || (node1 == NULL))
	{
		fprintf(stderr, "L%s: can't mul, stack too short\n",
			montyD->line);
		exit(EXIT_FAILURE);
	}
	node2 = node1->next;
	if (node2 == NULL)
	{
		fprintf(stderr, "L%s: can't mul, stack too short\n",
			montyD->line);
		exit(EXIT_FAILURE);
	}
	node2->n *= node1->n;
	*stack = node2;
	node2->prev = NULL;
	free(node1);
}


/**
 * div_Op -  divides the second element of stack by first element of stack
 * @stack: pointer to the stack
 * @montyD: pointer to m
 */
void div_Op(stack_t **stack, m *montyD)
{
	stack_t *node1 = *stack, *node2;

	if ((stack == NULL) || (node1 == NULL))
	{
		fprintf(stderr, "L%s: can't div, stack too short\n",
			montyD->line);
		exit(EXIT_FAILURE);
	}
	node2 = node1->next;
	if (node2 == NULL)
	{
		fprintf(stderr, "L%s: can't div, stack too short\n",
			montyD->line);
		exit(EXIT_FAILURE);
	}
	if (node1->n == 0)
	{
		fprintf(stderr, "L%s: division by zero\n", montyD->line);
		exit(EXIT_FAILURE);
	}
	node2->n /= node1->n;
	*stack = node2;
	node2->prev = NULL;
	free(node1);
}
