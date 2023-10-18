#include "shell.h"

/**
 * is_posit_num - Checks if a string represents a positive number.
 * @str: The string to check.
 * Return: 1 if str is a positive number, 0 otherwise.
 */
int is_posit_num(char *str)
{
	int j = 0;

	if (!str)
		return (0);
	while (str[j])
	{
		if (str[j] < '0' || str[j] > '9')
			return (0);
		j++;
	}
	return (1);
}

/**
 * _atoi - Converts a string to an integer.
 * @str: The string to convert.
 * Return: The integer value of the string.
 */
int _atoi(char *str)
{
	int j = 0;
	int number = 0;

	while (str[j])
	{
		number *= 10;
		number += (str[j] - '0');
		j++;
	}
	return (number);
}

/**
 * rev_str - Reverses a string in place.
 * @str: The string to reverse.
 * @len: The length of the string.
 */
void rev_str(char *str, int len)
{
	char temp;
	int start = 0;
	int end = len - 1;

	for (; start < end; start++, end--)
	{
		temp = str[start];
		str[start] = str[end];
		str[end] = temp;
	}
}

/**
 * _itoa - Converts an integer to a string.
 * @num: The integer to convert.
 * Return: A pointer to the resulting string.
 */
char *_itoa(int num)
{
	char buf[19];
	int j = 0;

	if (num == 0)
		buf[j++] = '0';
	else
	{
		for (; num > 0; num /= 10)
		{
			buf[j++] = (num % 10) + '0';
		}
	}
	buf[j] = '\0';
	rev_str(buf, j);
	return (_strdup(buf));
}
