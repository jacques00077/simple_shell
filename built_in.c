#include "main.h"

/**
 * pave - Displays the environment variables
 * @env: The argument
 */

void pave(char **env)
{
	while (*env != NULL)
	{
		write(1, *env, strlen(*env));
		write(1, "\n", 1);
		env++;
	}
}

/**
 * manage_exit - Manages the functionality of the exit
 * @ac:Value to be managed as input
 * @escape: The exit status of the code
 */

void manage_exit(char *ac, int escape)
{
	free(ac);
	exit(escape);
}

/**
 * eggs - Manages the exit status
 * @tree: Function parameters
 * @ac: Examines the exit status
 *
 * Return: Exit status, 1 if conditions are not met
 */

int eggs(char **tree, char *ac)
{
	char *o_status;
	int escape, q;

	if (tree[1] != NULL)
	{
		escape = 0;
		o_status = tree[1];

		for (q = 0; o_status[q] != '\0'; q++)
		{
			if (o_status[q] < '0' || o_status[q] > '9')
			{
				manage_exit(ac, 2);
				return (1);
			}
			escape = escape * 10 + (o_status[q] - '0');
		}
		manage_exit(ac, escape);
	}
	else
	{
		manage_exit(ac, 87);
	}
	return (1);
}

/**
 * plant_cd - Manages the functionality of cd
 * @tree: Command arrays
 * @noac: Number of arguments
 */

void plant_cd(char **tree, int noac)
{
	const char *home_dir, *old_dir;

	home_dir = getenv("$HOME");
	old_dir = getenv("PWD");

	if (noac == 1 || strcmp(tree[1], "-") == 0)
	{
		if (!home_dir)
		{
			perror("Home environment is unset");
			return;
		}
		if (chdir(home_dir) != 0)
			perror("cd");
	}
	else if (noac == 2 && strcmp(tree[1], "-") == 0)
	{
		if (!old_dir)
		{
			perror("PWD environment is unset");
			return;
		}
		if (chdir(old_dir) != 0)
			perror("cd");
	}
	else
	{
		if (chdir(tree[1]) != 0)
			perror("cd");
	}
}
