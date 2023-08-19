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

/**
 * _printf - A custom implementation of the printf function
 *
 * @format: A format string that specifies the output
 * @...: The arguments to be printed
 *
 * Return: The number of characters printed
 */
int _printf(const char *format, ...)
{
	int count = 0;
	va_list args;

	va_start(args, format); /* Initialize va_list */
	/* Loop through the format string */
	while (*format)
	{
		/* Check for a format specifier */
		if (*format == '%')
		{
			/* Get the next character in the format string */
			format++;

			/* Switch on the format specifier */
			switch (*format)
			{
				case 'c':
					count += _putchar(va_arg(args, int)); /* character */
					break;
				case 's':
					count += _puts(va_arg(args, const char *)); /* string */
					break;
				default:
					/* Unknown format specifier */
					count += _putchar('%');
					count += _putchar(*format);
					break;
			}
		}
		else
		{
			/* Print the character */
			count += _putchar(*format);
		}
		format++; /* Next character */
	}
	va_end(args); /* Clean up the va_list */
	return (count); /* Return num of chars printed */
}
