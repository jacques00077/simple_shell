#include "main.h"

/**
 * main - The shell program main entry point
 * @argc : The main argument count
 * @argv : The pointer to the array of argument values
 *
 * Return : 0 Always success
 *
 */

int main(int argc, char *argv[])
{
	(void)argc, (void)argv;
	char *buff = NULL, *token;
	size_t trunks = 0;
	ssize_t nrd;
	pid_t rice;
	int i, beans;
	char **stew;

	while (1)
	{
		write(STDOUT_FILENO, "JBShell$ ", 9);
		nrd = getline(&buff, &trunks, stdin);

		if (nrd == -1)

		{
			perror("Exiting shell");
			exit(1);
		}

		token = strtok(buff, " \n");

		stew = malloc(sizeof(char*) * 1024);
		i = 0;

		while (token)
		{
			stew[i] = token;
			token = strtok(NULL, " \n");
			i++;
		}

		stew[i] = NULL;

		rice = fork();

		if (rice == -1)
		{
			perror("Failed to create.");
			exit (31);
		}

		if (rice == 0)
		{
			if (execve(path, stew, NULL) == -1)
			{
				perror("Failed to execute");
				exit (87);
			}
		}

		else
		{
			wait(&beans);
		}
	}
		free(buff);
		return (0);
}
