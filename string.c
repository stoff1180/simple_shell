#include "shell.h"

/**
 * _strdup - Duplicates a string.
 * @str: The string to duplicate.
 * Return: A pointer to the duplicated string, or NULL on failure.
 */
char *_strdup(const char *str)
{
	char *p;
	int len = 0;
	int i = 0;
	const char *temp = str;

	if (str == NULL)
		return (NULL);
	while (*temp != '\0')
	{
		len++;
		temp++;
	}
	p = (char *)malloc(sizeof(char) * (len + 1));
	if (p == NULL)
		return (NULL);
	while (i <= len)
	{
		p[i] = str[i];
		i++;
	}
	return (p);
}

/**
 * _strcmp - Compares two strings.
 * @s1: The first string to compare.
 * @s2: The second string to compare.
 * Return: An integer less than, equal to, or greater than zero if s1 is found
 *         be less than, equal to, or greater than s2, respectively.
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 != '\0' && *s2 != '\0' && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return ((int)*s1 - (int)*s2);
}

/**
 * _strlen - Calculates the length of a string.
 * @str: The string to calculate the length of.
 * Return: The length of the string.
 */
int _strlen(char *str)
{
	int len;

	for (len = 0; str[len]; len++)
		;
	return (len);
}

/**
 * _strcat - Concatenates two strings.
 * @dest: The destination string.
 * @src: The source string.
 * Return: A pointer to the resulting string (dest).
 */
char *_strcat(char *dest, char *src)
{
	char *ptr = dest;

	for (; *ptr; ptr++)
		;
	for (; *src; ptr++, src++)
	{
		*ptr = *src;
	}
	*ptr = *src;
	return (dest);
}

/**
 * _strcpy - Copies a string.
 * @dest: The destination string.
 * @src: The source string.
 * Return: A pointer to the resulting string (dest).
 */
char *_strcpy(char *dest, char *src)
{
	int i;

	if (dest == src || src == NULL)
		return (dest);
	for (i = 0; src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}
	dest[_strlen(src)] = '\0';
	return (dest);
}
