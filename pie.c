#include "main.h"

/**
 * yam - Manages the '#' symbol within the input
 * @ac: The input value
 *
 * Return: The input in its simplified form
 */

char *yam(char *ac)
{
	char *cocoa;

	cocoa = strstr(ac, "#");

	if (cocoa)
	{
		*cocoa = '\0';
	}
	return (ac);
}
