#ifndef MONTY_H
#define MONTY_H

#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stddef.h>
#include <string.h>
#include <unistd.h>

#define DELIM " \t\n" 


/**
 * m - store the basic elements we are going to need
 *
 * @arg: a pointer to the current command
 * @line: pointer to the current line
 * @isQ: check if stack or Queue
 * @file: pointer to opened file
 * @lineNum: current line in the file
 *
 * Description: Store monty project basic commands
 *
 */

typedef struct monty
{
	char *arg;
	char *line;
	FILE *file;
	unsigned int lineNum;
	bool isQ;
} m;


/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 *
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 *
 */

typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 *
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 *
 */

typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, m *montyD);
} instruction_t;


void montyLoop(stack_t **list, m *montyD);

/* findCommand.c funcs */
void executeCom(stack_t **list, m *montyD);

/* parsecommand.c funcs */
int checkNum(char *s);

/* addNode_fucs.c */
void freeNode(stack_t *head);
void addNodeEnd(stack_t **head, int n);
void addNodeStart(stack_t **head, int n);

/* bytecode commands */
void pushfunc(stack_t **list, m *montyD);
void pallfunc(stack_t **list, m *montyD);
void pintfunc(stack_t **list, m *montyD);



#endif /* MONTY_H */
