#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stddef.h>
#include <string.h>

#define DELIM " \t" 


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

/**
 * m - store the basic elements we are going to need
 *
 * @command: a pointer to the current command
 * @line: pointer to the current line
 * @isQ: check if stack or Queue
 *
 * Description: Store monty project basic comands
 *
 */

typedef struct monty
{
	char **command;
	char *line;
	FILE *file;
	unsigned int lineNum;
	bool isQ;
} m;


void montyLoop(stack_t **list, m *montyD);
char *_readline(char **line, int *len, FILE *inputFile);

/* findCommand.c funcs */
void (*findCom(char *command))(stack_t **, m *);

/* parsecommand.c funcs */
char *trimLine(char *line);
char **parseCom(char *line);
void remComment(char *line);
int checkNum(char *s);

/* addNode_fucs.c */
void freeNode(stack_t *head);
void addNodeEnd(stack_t **head, int n);
void addNodesStart(stack_t **head, int n);

/* opCodeCommands1.c */
void pushfunc(stack_t **list, m *montyD);
void pallfunc(stack_t **list, m *montyD);



#endif /* MONTY_H */
