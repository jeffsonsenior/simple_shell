#include "myshell.h"
/**
 * num_is_pos - checking is the string is positive number
 * @str : string
 *
 * Return 0 succes.
 */
int num_is_pos(char *str)
{
	int idx;

	if (!str)
		return (0);
	for (idx = 0; str[idx]; idx++)
	{
		if (str[idx] < '0' || str[idx] > '9')
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
	int idx, number = 0;

	for (idx = 0; str[idx]; idx++)
	{
		number *= 10;
		number += (str[idx] - '0');
	}
	return (number);
}
