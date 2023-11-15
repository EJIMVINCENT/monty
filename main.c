#include "monty.h"

/**
 * main - program Entry point
 *
 * @ac: argument count
 * @argv: argument vector
 *
 * Return: Always returns 0
 */




int main(int ac, char *argv[])
{
	stack_t *list = NULL;
	m montyD = {NULL, NULL, NULL, 0, false};

	if (ac != 2)
	{
		fprintf(stderr, "%s\n", "USAGE: monty file");
		exit(EXIT_FAILURE);
	}

	montyD.file = fopen(argv[1], "r");
	if (montyD.file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	montyLoop(&list, &montyD);
	return (0);
}

/**
 * montyLoop - Code main loop
 *
 * @list: pointer to stack_t node
 * @montyD: pointer to m struct.
 *
 */

void montyLoop(stack_t **list, m *montyD)
{
	char *line;
	size_t len = 0;
	int check = 1;

	while (check > 0)
	{
		line = NULL;
		check = getline(&line, &len, montyD->file);
		montyD->line = line;
		montyD->lineNum++;
		if (check > 0)
			executeCom(list, montyD);
		free(line);

	}
	freeNode(*list);
	fclose(montyD->file);
}
