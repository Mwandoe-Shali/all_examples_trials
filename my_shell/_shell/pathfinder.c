#include "shell.h"

/**
 * _getenv - gets the value of the environment variable
 * @var_name: name of the environment variable
 * Return: value of the variable or NULL if not found
 */
char *_getenv(const char *var_name)
{
	int index, a;
	char *value;

	if (!var_name)
		return (NULL);

	for (index = 0; environ[index]; index++)
	{
		a = 0;
		if (var_name[a] == environ[index][a])
		{
			while (var_name[a])
			{
				if (var_name[a] != environ[index][a])
					break;
				a++;
			}
		if (var_name[a] == '\0')
		{
			value = (environ[index] + a + 1);
			return (value);
		}
		}
	}
	
	return (NULL);
}
