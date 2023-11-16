#include "monty.h"

/**
 * pstrfunc - prints the string starting at the top of the stack
 * @stack: pointer to the stack
 * @montyD: pointer to m
 */
void pstrfunc(stack_t **stack, m *montyD)
{
	stack_t *current = *stack;

	(void)montyD->lineNum;

	for (; current != NULL; current = current->next)
	{
		if ((current->n > 32) && (current->n < 127))
			printf("%c", current->n);
		else
			break;
	}
	printf("\n");
}
