#include "monty.h"


/**
 * rot1func - Rotates the top value of a stack_t linked head to the bottom.
 *
 * @head: A pointer to the top mode node of a stack_t linked head.
 * @montyD: The current working line number of a Monty bytecodes file.
 *
 */

void rot1func(stack_t **head, m *montyD)
{
	stack_t *temp, *bottom;

	(void)montyD;
	
	if (!head || !(*head) || (*head)->next == NULL)
		return;

	temp = *head;
	(*head) = (*head)->next;
	bottom = temp->next;
	while (bottom->next != NULL)
		bottom = bottom->next;


	(*head)->prev = NULL;
	bottom->next = temp;
	temp->next = NULL;
	temp->prev = bottom;
}
