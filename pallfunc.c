#include "monty.h"


/**
 * _pall - prints the stack.
 * @list: stack list
 * @counter: .
 * Return: .
*/
void pallfunc(stack_t **list, m *montyD)
{
	stack_t *h;
	(void)montyD;

	h = *list;
	if (h == NULL)
		return;
	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}
