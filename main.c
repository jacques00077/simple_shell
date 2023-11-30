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
	char *buff = NULL;
	size_t trunks = 0;
	ssize_t nrd;
	pid_t rice;
	int beans

	while (1)
	{
		write(STDOUT_FILENO, "JBShell$ ", 9);
		nrd = getline(&buff, &trunks, stdin);

		if (nrd == -1)

		{
			perror("Exiting shell");
			exit(1);
		}

		rice = fork();

		if (rice == -1)
		{
			perror("Failed to create.");
			exit (410);
		}

		if (rice == 0)
		{
			/* We can execute the user input because the creation was successful */
			printf("Creation successful");
		}
		else
		{
			/* Wait for the child_process to execute before termination of the parent process */
			wait(*bean);
		}
		printf("%s", buff);
		printf("Buffer size: %ld\n", trunks);
	}
		free(buff);
		return (0);
}
