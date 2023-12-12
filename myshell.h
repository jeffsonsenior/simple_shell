#ifndef MYSHELL_H
#define MYSHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>

#define DELIM " \t\n"


/* tokenization.c */
char **tokenize(char *input_line);

/* execute */
char *read_line(void);
int _run_command(char **input_line, char **cmd_args, int command_index);
void free_string_array(char *array);




















#endif
