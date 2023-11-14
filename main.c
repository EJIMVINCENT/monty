#include "monty.h"






int main(int ac, char *argv[])
{
	FILE *input;
	stack_t list;

	if (ac != 2)
	{
		fprintf(stderr, "%s\n", "USAGE: monty file");
		exit(EXIT_FAILURE);
	}

	input = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	montyLoop(&list, input);
}





int montyLoop(stack_t *list, FILE *input)
{
	char *line;
	size_t len;

	list->line = _readline(&line, &len, input);
	
	while (list->line)
	{
		
	}
}
