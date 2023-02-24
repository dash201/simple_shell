#include "shell.h"

/**
 *my_strcpy - execute commands in enter
 *@src: first parameter
 *@dest: second parameter
 *Return: char dest
*/
char *my_strcpy(char *dest, char const *src)
{
	int a = 0;
	int x = 0;
	int b = my_strlen(src);

	dest = malloc(sizeof(char) * (b + 1));
	for (a = 0; src[a] != '\0'; a++)
	{
		dest[x] = src[a];
		x++;
	}
	dest[x] = '\0';
	return (dest);
}

/**
 *delete_delimit - separate command from arguments or options
 *@line: first parameter
 *@delim: second parameter
 *Return: command
*/
char **delete_delimit(char *line, char *delim)
{
	int a = 0;
	char *tmp = NULL;
	char **cmd = malloc(sizeof(char *) * 50);

	for (a = 0; a < 50; a++)
		cmd[a] = malloc(sizeof(char) * 100);
	a = 0;
	tmp = strtok(line, delim);
	while (tmp != NULL)
	{
		cmd[a] = strcpy(cmd[a], tmp);
		a++;
		tmp = strtok(NULL, delim);
	}
	cmd[a] = NULL;
	return (cmd);
}

/**
 *copy - retrieve the line corresponding to the environment variable
 *@env: first parameter
 *@part: second parameter
 *Return: char
*/
char *copy(char **env, char *part)
{
	int e = 0;
	int a = 0;
	char *pa = NULL;
	int n = strlen(part);
	char *cmp = malloc(sizeof(char) * (n + 1));

	for (a = 0; env[a] != NULL; a++)
	{
		for (e = 0; e < n; e++)
			cmp[e] = env[a][e];
		cmp[e] = '\0';
		if (strcmp(part, cmp) == 0)
		{
			pa = malloc(sizeof(char) * (strlen(env[a]) + 1));
			pa = strcpy(pa, env[a]);
		}
	}
	return (pa);
}

/**
 *my_getenv - retrieve line content
 *@env: first parameter
 *@rec: second parametr
 *Return: line
*/
char *my_getenv(char **env, char *rec)
{
	int i = 0;
	int n = 0;
	int c = strlen(rec) + 1;
	char *li = copy(env, rec);
	char *pa = malloc(sizeof(char) * 1000);

	for (i = c; li[i] != '\0'; i++)
	{
		pa[n] = li[i];
		n++;
	}
	pa[n] = '\0';
	return (pa);
}

/**
 *execute_path - execute the binaries that are in the env variable
 of the PATH
 *@line: command
 *Return: number
*/
int execute_path(char **line)
{
	int a = 0;
	int b = 0;
	char *path = my_getenv(environ, "PATH");
	char **cmd = delete_delimit(path, ":");
	char *first;
	char *end;

	while (cmd[a] != NULL)
	{
		first = strcat(cmd[a], "/");
		end = strcat(first, line[0]);
		b = execve(end, line, environ);
		if (b != 0)
			a++;
		else
			return (0);
	}
	return (b);
}
