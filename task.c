#include "shell.h"
/**
 *special_key - execute commands in enter
 *@line: parameter
*/
void special_key(char *line)
{
	int i = 0;
	char *tp = NULL;
	char **tmp = NULL;

	tp = my_strcpy(tp, line);
	tmp = delete_delimit(line, "/");
	for (i = 0; tmp[i + 1] != NULL; i++)
	{
	}
	i = execve(tp, &tmp[i], environ);
	if (i != 0)
		perror("shell");
}
/**
 *main - entry point
 *Return: 0
*/
int main(void)
{
	int a = 0;
	char *line = NULL;
	size_t n = 100;
	pid_t pid = 0;

	signal(SIGINT, SIG_IGN);
	if (a <= 1)
	{
		while (1)
		{
			write(1, "($) ", 4);
			if (getline(&line, &n, stdin))
			{
				line[my_strlen(line) - 1] = '\0';
				pid = fork();
				if (pid == 0)
					special_key(line);
				else
					wait(&pid);
			}
		}
	}
	else
	{
		line[my_strlen(line) - 1] = '\0';
		special_key(line);
	}
	return (0);
}
