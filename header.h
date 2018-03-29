#ifndef __HEADER__
#define __HEADER__

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
#include <stdio.h>
#include <signal.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/time.h>
#include <sys/resource.h>

#define delim "\n "

extern char **environ;

void type_prompt(void);
int read_cmd(char **param);
int location_check(char *cmd);
char *find_cmd(char *av, int count, char *param);
void _kill(char *lineptr, char *tmp, char **tok);
void env(void);
int write_nope(char *av, int count, char *param);
void fork_fail(int pid_value);
void child(char *av, char *param, int i, char *cmd);
void signalHandler(int sig_num __attribute__((unused)));

char *_itoa(int n);

int _strlen(char *s);
int _strcmp(char *s1, char *s2);
int _strncmp(char *s1, char *s2, int n);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);


#endif /* __HEADER__ */
