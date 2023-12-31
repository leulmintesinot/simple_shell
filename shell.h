#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>

#define DELIM " \t\n"
extern char **environ;

char *read_line(void);
char **tokenizer(char *line);
int _execute(char **comm, char **argv, int idx);
char *_getenv(char *var);
char *_getpath(char *comm);

int is_builtin(char *comm);
void handle_builtin(char **comm, char **argv, int stat, int idx);
void exit_shell(char **comm, int stat);
void print_env(char **comm, int stat);

void freearray2D(char **arr);
void print_error(char *name, char *cmd, int idx);
char *_itoa(int n);
void reverse_string(char *str, int len);

char *strtok (char *__restrict __s, const char *__restrict __delim);
char *_strdup(const char *str);
int _strcmp(char *s1, char *s2);
int _strlen(char *s);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);


#endif
