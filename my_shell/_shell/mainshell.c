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
	char *input, *tokens;
	size_t n;
	ssize_t char_read = 0;
    
	(void)ac;
    
	while(1)
	{
		_puts("$Shell$ ");
    
		char_read = getline(&input, &n, stdin);
		if (char_read == -1)
		{
        		_puts("\n\nDisconneted\nExiting Shell... ");
			return(-1);
		}
		/*_printf("%s", lineptr);*/
		/*    free(lineptr); */
	}

	av = strsplit(input);
	_execute(av);
	
	/* Deleted from here & cp to token+exec.c */
	return (0);
}
