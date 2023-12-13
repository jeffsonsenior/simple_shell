#include "myshell.h"
/**
 * num_is_pos - checking is the string is positive number
 * @str : string
 *
 * Return 0 succes.
 */
int num_is_pos(char *str)
{
	int i;

	if (!str)
		return (0);
	for (i = 0; str[i]; i++)
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
	}
	return (1);
}
/**
 * custom_atoi - convert string to integers
 * @str: string.
 *
 * Return: converted string
 */
int custom_atoi(char *str)
{
	int i, number = 0;

	for (i = 0; str[i]; i++)
	{
		number *= 10;
		number += (str[i] - '0');
	}
	return (number);
}
