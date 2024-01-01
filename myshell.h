#ifndef MYSHELL_H
#define MYSHELL_H

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <errno.h>

#define DELIM " \t\n"


extern char **environ;


/* tokenization.c */
char **tokenize(char *input_line);

/* execute.c */
char *read_line(void);
int _run_command(char **comd, char **cmd_argv, int cmd_index);
void free_string_array(char **array);

/* getenv.c */
char *_getenv(char *var);


/*strings.c */
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
int _strlen(const char *s);
int _strcmp(char *s1, char *s2);
char *_strdup(const char *str);

/* getpath.c */
char *getpath(char *comd);

/* myutils.c */
void _perror(char *name, char *comd, int cmd_index);
char *_atoi(int n);
void reverse_string(char *str, int len);

/* buitin */
void _display_env(char **comd, int *status);
void _quit_shell(char **comd, char **cmd_argv, int *status, int cmd_index);
void _handle_builtin(char **comd, char **cmd_argv, int *status, int cmd_index);
int _is_builtin(char *comd);

/* tools */
int custom_atoi(char *str);
int num_is_pos(char *str);


#endif
