#include "main.h"

/**
 * main - Wait the program
 * @argc: Number of argument count
 * @argv: Array of argument vectors
 * @env: The environment variable
 *
 * Return: (0) success
 */

int main(int argc, char *argv[], char **env)
{
	char *soup;
	(void)argc;

	while(1)
	{
		print_icon();
		soup = chicken();
		exec_comm(soup, argv, env);
		free(soup);
	}

	return (0);
}
