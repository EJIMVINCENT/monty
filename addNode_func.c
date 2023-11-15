#include "monty.h"

/**
 * addNodeStart - adds a node to the head of a linked list
 *
 * @head: head of the list
 * @n: number to be added
 *
 */

void addNodeStart(stack_t **head, int n)
{
	stack_t *new;

	if (head == NULL)
		return;

	new = malloc(sizeof(stack_t));
	if (!new)
		return;

	new->n = n;
	new->prev = NULL;
	new->next = *head;
	*head = new;
	if (new->next != NULL)
		new->next->prev = new;

}

/**
 * addNodeEnd - adds a node to the head of a linked
 * (QUEUE)
 *
 * @head: head of the list
 * @n: number to be added
 *
 */


void addNodeEnd(stack_t **head, int n)
{
	stack_t *new, *temp = *head;

	if (!head)
		return;
	new = malloc(sizeof(stack_t));
	if (!new)
		return;

	new->n = n;
	new->next = NULL;
	if (*head == NULL)
	{
		*head = new;
		(*head)->prev = NULL;
		return;
	}

	while (temp->next)
		temp = temp->next;
	temp->next = new;
	new->prev = temp;
}


/**
 * freeNode - free a linked list
 *
 * @head: head of the list
 *
 */

void freeNode(stack_t *head)
{
	stack_t *temp;

	while (head)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}
