#include "monty.h"


/**
 * add_Op - adds the first two values in the stack
 * stores the result in the second element of the stack then pops first element
 * @stack: a doubly linked list
 * @line_number: line where opcode appears
 */
void add_Op(stack_t **stack, unsigned int line_number)
{
	stack_t *node1 = *stack, *node2;

	if ((stack == NULL) || (node1 == NULL))
	{
		fprintf(stderr, "L%u: can't add, stack too short\n",
			line_number);
		exit(EXIT_FAILURE);
	}

	node2 = node1->next;
	if (node2 == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n",
			line_number);
		exit(EXIT_FAILURE);
	}

	node2->n += node1->n;
	*stack = node2;
	node2->prev = NULL;
	free(node1);
}


/**
 * sub_Op - subtracts top element of stack from second element of stack
 * @stack: pointer to the stack
 * @line_number: line where opcode appears
 */
void sub_Op(stack_t **stack, unsigned int line_number)
{
	stack_t *node1 = *stack, *node2;

	if ((stack == NULL) || (node1 == NULL))
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n",
			line_number);
		exit(EXIT_FAILURE);
	}
	node2 = node1->next;
	if (node2 == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n",
			line_number);
		exit(EXIT_FAILURE);
	}
	node2->n -= node1->n;
	*stack = node2;
	node2->prev = NULL;
	free(node1);
}


/**
 * mul_Op - multiplies the second and first elements of the stack
 * @stack: pointer to the stack
 * @line_number: line where opcode appears
 */
void mul_Op(stack_t **stack, unsigned int line_number)
{
	stack_t *node1 = *stack, *node2;

	if ((stack == NULL) || (node1 == NULL))
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n",
			line_number);
		exit(EXIT_FAILURE);
	}
	node2 = node1->next;
	if (node2 == NULL)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n",
			line_number);
		exit(EXIT_FAILURE);
	}
	node2->n *= node1->n;
	*stack = node2;
	node2->prev = NULL;
	free(node1);
}


/**
 * div_Op -  divides the second element of stack by first element of stack
 * @stack: pointer to the stack
 * @line_number: line where opcode appears
 */
void div_Op(stack_t **stack, unsigned int line_number)
{
	stack_t *node1 = *stack, *node2;

	if ((stack == NULL) || (node1 == NULL))
	{
		fprintf(stderr, "L%u: can't div, stack too short\n",
			line_number);
		exit(EXIT_FAILURE);
	}
	node2 = node1->next;
	if (node2 == NULL)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n",
			line_number);
		exit(EXIT_FAILURE);
	}
	if (node1->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	node2->n /= node1->n;
	*stack = node2;
	node2->prev = NULL;
	free(node1);
}
