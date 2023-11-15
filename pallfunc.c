#include "monty.h"


/**
 * pallfunc - prints the stack.
 * @list: stack list
 * @montyD: pointer to m structure
 *
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
