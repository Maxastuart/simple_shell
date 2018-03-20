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

extern char **environ;

void type_prompt(void);

void read_cmd(char *cmd, char **param);

char *find_cmd(char *tcmd);

#endif /* __HEADER__ */
