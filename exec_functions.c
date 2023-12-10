#include "main.h"

/**
 * print_icon - Prints the prompt to the user
 */

void print_icon(void)
{
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "JBShell$ ", 9);
}

/**
 * chicken - Reads the input of the users
 *
 * Return: Character variable to the program
 */

char *chicken(void)
{
	char *soup;
	size_t jb;
	ssize_t nrd;

	soup = NULL;
	jb = 0;
	nrd = getline(&soup, &jb, stdin);

	if (nrd == -1)
	{
		free(soup);
		exit(0);
	}

	soup = yam(soup);

	return (soup);
}

/**
 * exec_comm - To execute the input from the buffer
 * @ac: The argument count from the buffer
 * @av: Arrray of argument vectors
 * @env: The environmrnt variables
 */

void exec_comm(char *ac, char *av[], char **env)
{
	char *tree[10];
	char *way, *stew;
	int beans, noac;
	pid_t rice;

	stew = av[0];
	noac = token_input(ac, tree);

	if (noac == 0)
		return;
	if (pear(tree, noac, ac, env) == 1)
		return;
	way = banku(tree[0]);

	rice = fork();

	if (rice == -1)
	{
		perror("Error: Failed to create");
		free(ac);
		exit(1);
	}

	if (rice == 0)
	{
		if (execve(way, tree, NULL) == -1)
		{
			write(2, stew, strlen(stew));
			write(2, ": 1: ", 5);
			write(2, tree[0], strlen(tree[0]));
			write(2, ": not found\n", 12);
			exit(87);
		}
	}
	else
		wait(&beans);

	free(way);
}

/**
 * pear - Handles all the builtin commands
 * @tree: Built in commands arguments
 * @noac: The number of arguments
 * @ac: Input command
 * @env: Environment variables
 *
 * Return: 1 if successful, 0 if unsuccessful
 */

int pear(char **tree, int noac, char *ac, char **env)
{
	if (strcmp(tree[0], "exit") == 0)
	{
		return (eggs(tree, ac));
	}
	else if (strcmp(tree[0], "cd") == 0)
	{
		plant_cd(tree, noac);
	}
	else if (strcmp(tree[0], "env") == 0)
	{
		pave(env);
		return (1);
	}

	return (0);
}

/**
 * token_input - Tokenize the input string
 * @ac: The argumen input
 * @tree: Array of strings
 *
 * Return: The number of tokenized items
 */

int token_input(char *ac, char *tree[])
{
	int trunks;
	char *token;

	trunks = 0;
	token = strtok(ac, "\n");

	while (token)
	{
		tree[trunks] = token;
		token = strtok(NULL, "\n");
		trunks++;
	}
	tree[trunks] = NULL;
	return (trunks);
}
