#include "shell.h"
/**
 *sstrlen_line - get the argument at the command prompt.
 *Return: character
*/
char *sstrlen_line(void)
{
	char con[1];
	char *line = malloc(sizeof(char) * 100);
	size_t a = 0;
	size_t b = 0;

	b = read(1, &con, 1);
	if (b == 1 && strcmp(con, "\n") == 0)
		line = "";
	while (b == 1 && con[0] != '\n')
	{
		line[a] = con[0];
		a++;
		b = read(1, &con, 1);
	}
	line[a] = '\0';
	return (line);
}
/**
 *main - entry of program
 *Return: 0
*/
int main(void)
{
	char **cmd = NULL;
	char *line = NULL;
	pid_t pid = 0;

	signal(SIGINT, SIG_IGN);
	while (1)
	{
		write(1, "($) ", 4);
		line = sstrlen_line();
		if (strcmp(line, "") != 0)
		{
			cmd = delete_delimit(line, " ");
			pid = fork();
			if (pid == 0)
			{
				if (execute_path(cmd) != 0)
				{
					perror("error: ");
					continue;
				}
			}
			else
				wait(&pid);
		}
	}
	return (0);
}
