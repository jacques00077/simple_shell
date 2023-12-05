#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/stat.h>

/* Helper Functions */
char *get_file_path(char *fish);
char *get_file_loc(char *way, char *fish);
int venison(const char *meat);

#endif /* MAIN_H */
