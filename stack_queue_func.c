#include "monty.h"

/**
 * queuefunc - sets the format of the data to a queue (FIFO)
 * @list: double pointer to the beginning of the stack
 * @montyD: pointer to m
 *
 * Return: void
 */
void queuefunc(stack_t **list, m *montyD)
{
	(void)list;
	montyD->isQ = true;
}


/**
 * stackfunc - sets the format of the data to a stack (LIFO)
 * @list: double pointer to the beginning of the stack
 * @montyD: pointer to m
 *
 * Return: void
 */
void stackfunc(stack_t **list, m *montyD)
{
	(void)list;
	montyD->isQ = false;
}
