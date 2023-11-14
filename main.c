#include "monty.h"






int main(int ac, char *argv[])
{
	stack_t *list;
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





void montyLoop(stack_t **list, m *montyD)
{
	char *line = NULL;
	int len = 0;
	int check;

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

		findCom(list, montyD);
		free (line);
	}
}
