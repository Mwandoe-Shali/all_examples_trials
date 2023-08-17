#include "shell.h"

/**
* main - main shell program
* @ac: argument counter
* @av: command to be executed
*
* Return 0 on success.
*/
int main(int ac, char **av)
{
	char *lineptr, *lineptr_copy, *tokens;
	size_t n;
	int j;
	int token_num = 0;
	const char *delimiter = " ";
	ssize_t char_read = 0;
    
	(void)ac;
    
	while(1)
	{
		_puts("$Shell$ ");
    
		char_read = getline(&lineptr, &n, stdin);
		if (char_read == -1)
		{
        		_puts("\n\nDisconneted\nExiting Shell... ");
			return(-1);
		}
		_printf("%s", lineptr);
		/*    free(lineptr); */
	}
	lineptr_copy = malloc(sizeof(char *) * char_read);
	if (lineptr_copy == NULL)
	{
		perror("Error:");
		return (-1);
	}
	_strcpy(lineptr_copy, lineptr);
    
	tokens = strtok(lineptr, delimiter);
    
	while (tokens)
	{
		token_num++;
		tokens = strtok(NULL, delimiter);
	}
	token_num++;
    
	av = malloc(sizeof(char *) * token_num);
    
	tokens = strtok(lineptr_copy, delimiter);
    
	for(j=0; tokens != NULL; j++)
	{
		av[j] = malloc(sizeof(char *) * strlen(tokens));
		_strcpy(av[j], tokens);
		tokens = strtok(NULL, delimiter);
		/*printf("%s\n", argv[j]);*/
	}
	av[j] = NULL;

	if (av)
	{
		if ((execve(av[j], av, NULL)) == -1)
		{
			perror("Error with execve: ");
			return (-1);
		}
		else
		{
			execve(av[j], av, NULL);
			return (0);
		}
	}
	return (0);
}
