#ifndef PIPEX_H
# define PIPEX_H
# include "libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

void	try_run_tool(char *argv[], char *env[]);
int		check_command(char *argv[], char *env[]);
void	run_command(char *argv[], char *env[]);
void	fexit(char *name);
int		check_access(char *path, unsigned mode);
#endif