#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <string.h>
#include <signal.h>

/*-----helper functions------*/
size_t _strlen(const char *str);
char *_strcpy(char *dest, const char *src);
void *_memcpy(void *dest, const void *src, size_t n);
char *_strdup(const char *str);

#endif /* SHELL_H */

