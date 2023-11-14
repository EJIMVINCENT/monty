#include "monty.h"





char *_readline(char **line, int *len, FILE *inputFile)
{
	int r;

	r = getline(line, len, inputFile);
	if (r == -1)
	{
		free(*line);
		return (NULL);
	}

	return (line);
}
