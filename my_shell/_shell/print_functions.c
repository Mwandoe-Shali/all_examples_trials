#include "shell.h"

/**
 * _putchar - Writes a character to stdout
 * @c: The character to write
 *
 * Return: Always 0 (Success)
 */
int _putchar(char c)
{
	/* Write the character to stdout */
	write(1, &c, 1);

	/* Return success */
	return (0);
}

/**
 * _puts - Prints a string to stdout
 * @str: The string to print
 *
 * Return: Always 0 (Success)
 */
int _puts(const char *str)
{
	/* Write the string to stdout one character at a time */
	for (int i = 0; str[i] != '\0'; i++)
		_putchar(str[i]);

	/* Write a newline character to stdout */
	_putchar('\n');

	/* Return success */
	return (0);
}
