#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/stat.h>
#include <errno.h>

/* Helper Functions */
char *banku(char *fish);
char *fufu(char *way, char *fish);
int venison(const char *meat);
void exec_comm(char *ac, char *av[], char **env);
char *chicken(void);
void print_icon(void);
int token_input(char *ac, char *tree[]);

/* Handles symbols */
char *yam(char *ac);

/* Built in Functions */
int pear(char **tree, int noac, char *ac, char **env);
void pave(char **env);
int eggs(char **tree, char *ac);
void plant_cd(char **tree, int noac);
void manage_exit(char *ac, int escape);

#endif /* MAIN_H */
