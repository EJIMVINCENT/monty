#include "monty.h"

/**
 * queuefunc - sets the format of the data to a queue (FIFO)
 * @stack: double pointer to the beginning of the stack
 * @montyD: pointer to m
 *
 * Return: void
 */
void queuefunc(stack_t **stack, m *montyD)
{
	(void)stack;
	(void)montyD->lineNum;
	montyD->isQ = 1;
}


/**
 * stackfunc - sets the format of the data to a stack (LIFO)
 * @stack: double pointer to the beginning of the stack
 * @montyD: pointer to m
 *
 * Return: void
 */
void stackfunc(stack_t **stack, m *montyD)
{
	(void)stack;
	(void)montyD->lineNum;
	montyD->isQ = 0;
}
