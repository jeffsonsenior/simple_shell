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

/* execute.c */
char *read_line(void);
int _run_command(char **cmd_args, char **argv, int command_index);
void free_string_array(char **array);

/* getenv.c */
extern char **environ;

char *_getenv(char *var);


/*strings.c */
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, charv*src);
int _strlen(char *s);
int _strcmp(char *s1, char *s2);
char *_strcmp(const char *str);


/* getpath.c */
char *getpath(char *cmd_args);

/*myutils.c */
void _perror(char *name, char *cmd_args, int command_index);
char *_atoi(int n);
void reverse_string(char *str, int len);

/* buitin */
void _display_env(char **cmd_args, int *status);
void _quit_shell(char **cmd_args, char **argv, int *status,int command_index);
void _handle_builtin(char **cmd_args, char **argv, int *status, int command_index);
int _is_builtin(char *cmd_args);


int custom_atoi(char *str);
int num_is_pos(char *str);




#endif
