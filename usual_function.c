#include "shell.h"
/**
 *my_strlen - count the caracter number
 *@str: parameter
 *Return: int
*/
int my_strlen(char const *str)
{
	int a = 0;

	while (str[a] != '\0')
		a++;
	return (a);
}
/**
 *my_putchar - print a character
 *@c: character
*/
void my_putchar(char c)
{
	write(1, &c, 1);
}
/**
 *my_putstr - print a string
 *@str: string
 *Return: 0
*/
int my_putstr(char const *str)
{
	int li = 0;

	for (li = 0 ; str[li] != '\0' ; li++)
		my_putchar(str[li]);
	return (0);
}
/**
 *my_strcat - concatane string
 *@dest: first parameter
 *@src: second parameter
 *Return: the new string
*/
char *my_strcat(char *dest, char *src)
{
	int a = 0;
	int b = 0;
	int i = my_strlen(dest);
	int j = my_strlen(src);
	int n = i + j;
	char *res = malloc(sizeof(char) * (n + 1));

	for (a = 0; dest[a] != '\0'; a++)
		res[a] = dest[a];
	for (b = 0; src[b] != '\0'; b++)
	{
		res[a] = src[b];
		a++;
	}
	res[a] = '\0';
	return (res);
}

/**
 *my_strcmp - compare two strings
 *@s1: first parameter
 *@s2: second parameter
 *Return: 0 or (-1)
*/
int my_strcmp(char *s1, char *s2)
{
	int i = 0;
	int n1 = my_strlen(s1);
	int n2 = my_strlen(s2);

	if (n1 > n2)
		return (1);
	else if (n1 < n2)
		return (-1);
	for (i = 0; s1[i] != '\0'; i++)
	{
		if (s1[i] > s2[i])
			return (1);
		else if (s1[i] < s2[i])
			return (-1);
	}
	return (0);
}
