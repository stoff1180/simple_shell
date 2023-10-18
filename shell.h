#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>


extern char **environ;

char *read_input(void);
char **split_input(char *input);
int execute_input(char **command, char **argv, int idx);
void free_array(char **array);
int main(int ac, char **argv);
char *_getenv(char *var);
char *_getpath(char *command);
void printerror(char *name, char *cmd, int ind);
int _strlen(char *str);
char *_strdup(const char *str);
int _strcmp(char *s1, char *s2);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
char *_itoa(int n);
void rev_str(char *str, int len);
int is_posit_num(char *str);
int _atoi(char *str);
int is_builtin(char *cmd_line);
void handle_exit(char **cmd_line, char **argv, int *status, int ind);
void handle_builtin(char **cmd_line, char **argv, int *status, int ind);
void print_env(char **cmd_line, int *status);

#endif

