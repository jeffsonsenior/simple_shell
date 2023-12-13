#include "myshell.h"

/**
 * _strdup - duplicate a string
 * @str: THe string to dublicate
 *
 * Return: ponter to the dublicated string
 */

char *_strdup(const char *str)
{
	int length = 0;
	char *ret;

	if (str == NULL)
		return (NULL);
	/* calculating the length of the input string */
	while (*str++)
		length++;
	/* allocating memory for a new string of the same lenth */
	ret = malloc(sizeof(char) * (length + 1));
	if (!ret)
		return (NULL);
	/* coppying the character in reverse order */
	for (length++; length--;)
	ret[length] = *--str;
	return (ret);
}
/**
 * _strcmp -performs glossarist comparison of two string.
 * @s1: the 1st string
 * @s2: the second string
 *
 * Return: negative if S1 < S2
 *         positive if S1 > S2
 */

int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		/* comparing characters */
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	/* strings are equal upto the NULL terminator */
	if (*s1 == *s2)
		return (0);
	else
		return (*s1 < *s2 ? -1 : 1);
}

/**
 * _strlen - return the length of the string
 * @s : the string whose length to check
 *
 * Return: interger length of a string
 */

int _strlen(char *s)
{
	int i = 0;
	/*checking if is a null pointer */
	if (!s)
		return (0);
	/* counting the characters untill null terminator is achived */
	while (*s++)
		i++;
	return (i);
}

/**
 * strcat - concatenate two strings.
 * @dest: the destination buffer.
 * @src: the source buffer.
 *
 * Return: pointer to destination buffer.
 */

char *_strcat(char *dest, char *src)
{
	char *ret = dest;
	/* finding the end of destinatination buffer */
	while (*dest)
		dest++;
	/* make sure proper null termination is attained */
	*dest = *src;
	return (ret);
}

/**
 * strcpy - copies a string
 * @dest: the destination
 * @src: the source
 *
 * Return: pointer to the destination
 */

char *_strcpy(char *dest, char *src)
{
	int i = 0;
	/* check overlapping strings or null sources */
	if (dest == src || src == 0)
		return (dest);
	/* coppy characters until null termination is attain */
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	/* proper null termination */
	dest[i] = 0;
	return (dest);
}
