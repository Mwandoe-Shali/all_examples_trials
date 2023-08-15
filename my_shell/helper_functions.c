#include "shell.h"

/**
 * _strlen - Returns the length of a string
 * @s: Pointer to the string
 * Return: Length of the string
 */
size_t _strlen(const char *str)
{
	size_t counter = 0;

	while (*str != '\0')
	{
		counter++;
		str++;
	}

	return (counter);
}

/**
 *_strcpy -Copy a string from src to dest
 *@dest: Pointer to the destination address
 *@src: Ponter to the source address
 *Return: char copy of the string
 */
char *_strcpy(char *dest, const char *src)
{
	int i;

	for (i = 0; src[i] != '\0'; i++)
		dest[i] = src[i];

	dest[i] = '\0';

	return (dest);
}

/**
 * _memcpy - Copies the contents of the source string to the destination string.
 *
 * @dest: A pointer to the destination string.
 * @src: A pointer to the source string.
 * @n: The number of bytes to copy.
 *
 * Return: A pointer to the destination string.
 */
void *_memcpy(void *dest, const void *src, size_t n)
{
	/* Check the parameters */
	if (dest == NULL || src == NULL)
		return NULL;

	/* Copy the bytes */
	char *d = (char *) dest;
	const char *s = (const char *) src;
	for (size_t i = 0; i < n; i++)
		d[i] = s[i];

	/* Return the destination string */
	return (dest);
}


/**
 * _strdup - Duplicates a string.
 * @str: Pointer to the source string.
 *
 * Return: Pointer to the duplicated string, or NULL if memory allocation fails.
 */
char *_strdup(const char *str)
{
	size_t len = _strlen(str) + 1;
	
	char *dest = (char *) malloc(sizeof(char) * len);
	if (dest == NULL)
		return NULL;

	_memcpy(dest, str, len);

	return dest;
}
