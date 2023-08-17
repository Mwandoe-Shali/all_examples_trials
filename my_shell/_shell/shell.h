#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

/*-----string functions------*/
size_t _strlen(const char *str);
char *_strcpy(char *dest, const char *src);
void *_memcpy(void *dest, const void *src, size_t n);
char *_strdup(const char *str);

/*-------print functions------*/
int _puts(const char *str);
int _putchar(char c);
int _printf(const char *format, ...);

#endif /* SHELL_H */
