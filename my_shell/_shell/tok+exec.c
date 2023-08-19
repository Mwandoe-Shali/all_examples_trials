#include "shell.h"

/**
 * strsplit - Splits a string into an array of strings using a delimiter
 * @input: The input string to split
 * Return: An array of strings, or NULL on failure
 */
char **strsplit(char *input)
{
	char *input_copy, *tokens;
	char **av;
	int j;
	int token_num = 0;
	const char *delimiter = " ";

	input_copy = malloc(sizeof(char *) * (_strlen(input) + 1));
	if (input_copy == NULL)
	{
		perror("Error:");
		return (-1);
	}
	_strcpy(input_copy, input);
    
	tokens = strtok(input, delimiter);
    
	while (tokens)
	{
		token_num++;
		tokens = strtok(NULL, delimiter);
	}
	token_num++;
    
	av = malloc(sizeof(char *) * token_num);
    
	tokens = strtok(input_copy, delimiter);
    
	for(j=0; tokens != NULL; j++)
	{
		av[j] = malloc(sizeof(char *) * strlen(tokens));
		_strcpy(av[j], tokens);
		tokens = strtok(NULL, delimiter);
		/*printf("%s\n", argv[j]);*/
	}
	av[j] = NULL;

	return (av);
}


/**
 * execute - executes a command
 * @argv: array of arguments
 */
void _execute(char **av)
{

	int ret, status;

	if (av)
	{
		
		if (!av || !av[0])
			return;
		ret = fork();
		if (ret == -1)
		{
			perror(_getenv("_")); /*kunahii function getenv nimetoa kwa brian sijui nitaieka aje*/
		}
		
		if (ret == 0)
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
		wait(&status);
	}
}
