#include "monty.h"






int main(int ac, char *argv[])
{
	stack_t list;
	m montyD = {NULL, NULL, false, NULL, 0};

	if (ac != 2)
	{
		fprintf(stderr, "%s\n", "USAGE: monty file");
		exit(EXIT_FAILURE);
	}

	montyD. = fopen(argv[1], "r");
	if (montyD.file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	montyLoop(&list, &montyD);
}





void montyLoop(stack_t *list, m *montyD)
{
	char *line = NULL;
	size_t len = 0;
	int check;
	void (*func)(stack_t **, unsigned int);

	while (1)
	{
		montyD->line = _readline(&line, &len, montyD->file);
		montyD->lineNum++;
		if (montyD->line == NULL)
			break;

		check = remComment(montyD->line);
		 if (!check)
		 	continue;
		montyD->command = parseCom(montyD->line);
		func = findCom(montyD->command[0]);
			if (!func)
				continue;
		func(&list, montyD);
		free (line);
	}
}
