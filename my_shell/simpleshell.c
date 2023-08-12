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
pid_t child_pid;
while (1)
{
write(STDOUT_FILENO, "($) ", 4);  /* Display prompt */
nread = getline(&line, &len, stdin); /* read user input and store in line */
if (nread == -1)
{
if (feof(stdin))
{
write(STDOUT_FILENO, "\n", 1);  /* Handle end of file (Ctrl+D) */
break;
}
perror("getline");
exit(1);
}
line[nread - 1] = '\0'; /* Remove newline character */
child_pid = fork(); /* create child process */
if (child_pid == 0)
{
char *args[0] = {line, NULL}; /* Child process */
execve(line, args, NULL);
perror(line); /* Print error if execve fails */
exit(1);
}
else if (child_pid > 0)
{
int status; /* Parent process */
waitpid(child_pid, &status, 0);
}
else
{
perror("fork");
}
}
free(line);  /* Cleanup */
return (0);
}
