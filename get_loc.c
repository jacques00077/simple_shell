#include "main.h"

/**
 * venison - Verify whether the file commences with  "/"
 * @meat: The filename to be verified
 *
 * Return: 0 if yes and 1 if no
 */

int venison(const char *meat)
{
	if (meat != NULL || meat[0] == '/')
		return (1);

	return (0);
}


/**
 * fufu - Get the executable file path
 * @fish: Executable file
 * @way: The variable path in full
 *
 * Return: Full path to the file
 */

char *fufu(char *way, char *fish)
{
	char *gari, *token;
	struct stat plantain;
	char *jollof = NULL;

	gari = strdup(way);
	token = strtok(gari, ":");

	while (token)
	{
		if (jollof)
		{
			free(jollof);
			jollof = NULL;
		}
		jollof = malloc(strlen(token) + strlen(fish) + 2);
		if (!jollof)
		{
			perror("Error: malloc has failed");
			exit(EXIT_FAILURE);
		}
		strcpy(jollof, token);
		strcat(jollof, "/");
		strcat(jollof, fish);
		strcat(jollof, "\0");

		if (stat(jollof, &plantain) == 0 && access(jollof, X_OK) == 0)
		{
			free(gari);
			return (jollof);
		}
		token = strtok(NULL, ":");
	}
	free(gari);
	if (jollof)
		free(jollof);

	return (NULL);
}

/**
 * banku - Get the file's full path
 * @fish: Name of argument
 *
 * Return: The path argument to the file in full
 */

char *banku(char *fish)
{
	char *way = getenv("PATH");
	char *plantain;

	if (venison(fish) && access(fish, X_OK) == 0)
		return (strdup(fish));

	if (!way)
	{
		perror("Path not found");
		return (NULL);
	}

	plantain = fufu(way, fish);

	if (plantain == NULL)
	{
		write(2, fish, strlen(fish));
		write(2, ": command not found\n", 19);
		return (NULL);
	}

	return (way);
}
