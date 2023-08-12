#include "shell.h"

/**
* main - Entry point for the simple shell
*
* Return: Always 0 on success
*/
int main(void)
{
char *line = NULL;
size_t len = 0;
ssize_t nread;

while (1) {
write(STDOUT_FILENO, "($) ", 4);  /* Display prompt */

nread = getline(&line, &len, stdin);
if (nread == -1) {
if (feof(stdin)) {
write(STDOUT_FILENO, "\n", 1);  /* Handle end of file (Ctrl+D) */
break;
}
perror("getline");
exit(1);
}

/* Remove newline character */
line[nread - 1] = '\0';

pid_t child_pid = fork();
if (child_pid == 0) {
/* Child process */
char *args[] = {line, NULL};
execve(line, args, NULL);

/* Print error if execve fails */
perror(line);
exit(1);
} else if (child_pid > 0) {
/* Parent process */
int status;
waitpid(child_pid, &status, 0);
} else {
perror("fork");
}
}

free(line);  /* Cleanup */
return 0;
}

