#include "monty.h"

/**
 * popfunc - removes a value from the top of a list
 *
 * @list: a doubly linked list
 * @montyD: pointer to m
 *
 */

void popfunc(stack_t **list, m *montyD)
{
	stack_t *temp = *list;

	if (*list == NULL)
	{
		fprintf(stderr, "L%s: can't pop an empty stack\n", montyD->line);
		fclose(montyD->file);
		free(montyD->line);
		freeNode(*list);
		exit(EXIT_FAILURE);
	}
	*list = temp->next;
	free(temp);
}


/**
 * swapfunc - swaps the first two values in the list
 *
 * @list: a doubly linked list
 * @montyD: pointer to m
 *
 */

void swapfunc(stack_t **list, m *montyD)
{
	stack_t *node1 = *list, *node2;

	if ((list == NULL) || (node1 == NULL))
	{
		fprintf(stderr, "L%s: can't swap, list too short\n",
			montyD->line);
		fclose(montyD->file);
		free(montyD->line);
		freeNode(*list);
		exit(EXIT_FAILURE);
	}
	node2 = node1->next;
	if (node2 == NULL)
	{
		fprintf(stderr, "L%s: can't swap, list too short\n",
			montyD->line);
		fclose(montyD->file);
		free(montyD->line);
		freeNode(*list);
		exit(EXIT_FAILURE);
	}

	if (node2->next == NULL)
	{
		node1->prev = node2;
		node2->next = node1;
		node1->next = NULL;
		node2->prev = NULL;
		*list = node2;
	}
	else
	{
		node1->next = node2->next;
		node2->next->prev = node1;
		node1->prev = node2;
		node2->next = node1;
		node2->prev = NULL;
		*list = node2;
	}
}


/**
 * modfunc - computes remainder of division of top second element by first
 * element of list
 *
 * @list: pointer to the list
 * @montyD: pointer to m
 *
 */

void modfunc(stack_t **list, m *montyD)
{
	stack_t *node1 = *list, *node2;

	if ((list == NULL) || (node1 == NULL))
	{
		fprintf(stderr, "L%s: can't mod, list too short\n",
			montyD->line);
		fclose(montyD->file);
		free(montyD->line);
		freeNode(*list);
		exit(EXIT_FAILURE);
	}
	node2 = node1->next;
	if (node2 == NULL)
	{
		fprintf(stderr, "L%s: can't mod, list too short\n",
			montyD->line);
		fclose(montyD->file);
		free(montyD->line);
		freeNode(*list);
		exit(EXIT_FAILURE);
	}
	if (node1->n == 0)
	{
		fprintf(stderr, "L%s: division by zero\n", montyD->line);
		fclose(montyD->file);
		free(montyD->line);
		freeNode(*list);
		exit(EXIT_FAILURE);
	}
	node2->n %= node1->n;
	*list = node2;
	node2->prev = NULL;
	free(node1);
}
