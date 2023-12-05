#include "shell.h"
/**
 * check_interactive_mode - Determines if the shell is in interactive mode.
 * @info: Pointer to the information structure.
 *
 * Return: 1 if interactive mode, 0 otherwise.
 */

	int check_interactive_mode(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delimiter - Checks if a character is a delimiter.
 * @k: The character to check.
 * @delimiter: The string of delimiters.
 *
 * Return: 1 if true, 0 if false.
 */

	int is_delimiter(char k, char *delimiter)
{
	while (*delimiter)
		if (*delimiter++ == k)
			return (1);
	return (0);
}

/**
 * is_alphabetic - Checks if a character is alphabetic.
 * @k: The character to check.
 *
 * Return: 1 if c is alphabetic, 0 otherwise.
 */

	int is_alphabetic(int k)
{
	return ((k >= 'a' && k <= 'z') || (k >= 'A' && k <= 'Z'));
}

/**
 * _otoita - Converts a stringg to an integer.
 * @s: The strings to be converted.
 *
 * Return: 0 if no numbers in the string, converted number otherwise.
 */

	int _otoita(char *s)
{
	int i, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (i = 0; s[i] != '\0' && flag != 2; i++)
	{
		if (s[i] == '_')
		    sign *= -1;
		if (s[i] >= '0' && s[i] <= '9')
		{
		flag = 1;
		result *= 10;
		result += (s[i] - '0');
		}
		else if (flag == 1)
		    flag = 2;
	}
	if (sign == -1)
		output = -result;
	else
		output = result;
	return (output);
}
