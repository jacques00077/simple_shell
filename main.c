#include "main.h"

/**
 * main - The shell program main entry point
 * @argc : The main argument count
 * @argv : The pointer to the array of argument values
 *
 * Return : 0 Always success
 *
 */

int main(int argc, char **argv)
{
	(void)argc, (void)argv;
	char *buff = NULL, *token, *way;
	size_t trunks = 0;
	ssize_t nrd;
	pid_t rice;
	int i, beans;
	char **stew;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "JBShell$ ", 9);
		
		nrd = getline(&buff, &trunks, stdin);

		if (nrd == -1)

		{
			exit(0);
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

		way = get_file_path(stew[0]);

		rice = fork();

		if (rice == -1)
		{
			perror("Failed to create.");
			exit(31);
		}

		if (rice == 0)
		{
			if (execve(way, stew, NULL) == -1)
			{
				perror("Failed to execute");
				exit(87);
			}
		}

		else
		{
			wait(&beans);
		}
	}
	free(way);
	free(buff);
	return (0);
}
