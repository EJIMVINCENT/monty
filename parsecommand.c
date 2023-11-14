#include "monty.h"

void remComment(char *line)
{
	int i = 0;

	while (line[i])
	{
		if (line[i] == '#')
		{
			line[i] = '\0';
			break;
		}
		i++;
	}

	for (i = 0; line[i]; i++)
	{
		if (line[i] != ' ' || line[i] != '\t' || line != '\n')
			return (1)
	}
	return 0;


}

char **parseCom(char *line)
{
	char *temp;
	char **command;
	int i = 0;

	temp = trimLine(line);

	command = malloc(sizeof(char *) * 3)
	command[0] = strtok(temp, DELIM);
	while (command[i])
	{
		command[++i] = strtok(NULL, DELIM);
	}
	return (command)
}



char *trimLine(char *line)
{
	int i;

	for (i = 0; line[i]; i++)
	{
		if (line[i] != ' ' || line[i] != '\t' || line != '\n')
			break
	}
	return (&line[i]);
}

int checkNum(char *s)
{
	int i;

	for(i = 0; s[i]; i++)
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
	}
	return (1);
}