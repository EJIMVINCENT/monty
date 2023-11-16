#include "monty.h"

/**
 * pcharfunc - prints the character at the top of the stack
 * @stack: pointer to the stack
 * @montyD: pointer to m
 */
void pcharfunc(stack_t **stack, m *montyD)
{
	stack_t *current = *stack;

	if ((stack == NULL) || (current == NULL))
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n",
			montyD->lineNum);
		exit(EXIT_FAILURE);
	}
	if ((current->n > 32) && (current->n < 127))
		printf("%c\n", current->n);
	else
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n",
			montyD->lineNum);
		exit(EXIT_FAILURE);
	}
}
