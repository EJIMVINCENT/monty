#include "monty.h"

/**
 * rotrfunc - Rotates the bottom value of a stack_t linked list to the top.
 *
 * @list: A pointer to the head node of a stack_t linked list.
 * @montyD: pointer to the m struct.
 *
 */

void rotrfunc(stack_t **list, m *montyD)
{
	stack_t *bottom;

	(void)montyD;
	if ( !list || !(*list) || (*list)->next == NULL)
		return;


	bottom = (*list)->next;
	while (bottom->next != NULL)
		bottom = bottom->next;

	bottom->prev->next = NULL;
	(*list)->prev = bottom;
	bottom->prev = NULL;
	bottom->next = *list;
}