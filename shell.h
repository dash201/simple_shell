#ifndef SHELL_H_
#define SHELL_H_
#include <unistd.h>
#include <stddef.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <signal.h>
extern char **environ;

int my_strlen(char const *str);
void my_putchar(char c);
int my_putstr(char const *str);
char *my_strcat(char *dest, char *src);
int my_strcmp(char *s1, char *s2);
char *my_strcpy(char *dest, char const *src);
char **delete_delimit(char *line, char *delim);
char *copy(char **env, char *part);
char *my_getenv(char **env, char *rec);
int  execute_path(char **line);

#endif
