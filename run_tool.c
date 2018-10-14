#include "libft.h"

static char	*find_env2(char *name, char **env)
{
	size_t	len;
	char	**p;

	len = ft_strlen(name);
	p = env;
	while (*p)
	{
		if (ft_strncmp(*p, name, len) == 0)
			return (*p);
		p++;
	}
	return (NULL);
}

static char	*find_sys_tool(char *t_name, char **env)
{
    char	**paths;
    char	**paths_cpy;
    char	*destinations;
    char	*full_path;

    full_path = NULL;
    if (!t_name || (destinations = find_env2("PATH", env)) == NULL)
        return (NULL);
    if ((paths = ft_strsplit(destinations, ':')) == NULL)
        return (NULL);
    if (*(paths_cpy = paths) == NULL && !access(t_name, X_OK))
        full_path = path_join(".", t_name);
    while (*paths)
    {
        full_path = path_join(*(paths++), t_name);
        if (access(full_path, F_OK) == 0)
            break ;
        free(full_path);
        full_path = NULL;
    }
    ft_free_tab(paths_cpy);
    return (full_path);
}

static int	execute_tool(char *tool_path, char *argv[], char *env[])
{
	int	status;

	if (execve(tool_path, argv, env) == -1)
		ft_puterr(2, argv[0],": failed to run proccess\n");
	exit(1);
}

void		try_run_tool(char *argv[], char *env[])
{
	char *path;

	if (argv == NULL || *argv == NULL)
		exit(1);
	path = find_sys_tool(argv[0], env);
	if (path && access(path, X_OK) == -1)
	{
		ft_puterr(3, "minishell: permission denied: ", argv[0], "\n");
		free(path);
	}
	else if (path)
	{
		execute_tool(path, argv, env);
		free(path);
	}
	else if (!path && access(argv[0], X_OK) == 0)
		execute_tool(path, argv, env);
	else
		ft_puterr(2, argv[0], ": command not found\n");
	exit(1);
}

void		run_command(char *argv[], char *env[])
{
	char *path;

	path = find_sys_tool(argv[0], env);
	if (path && execve(path, argv, env) == -1)
	{
		ft_puterr(2, argv[0],": failed to run proccess\n");
		exit(1);
	}
	else if (!path && access(argv[0], X_OK) == 0
		&& execve(path, argv, env) == -1)
	{
		ft_puterr(2, argv[0],": failed to run proccess\n");
		exit(1);
	}
}

void		check_command(char *argv[], char *env[])
{
	char *path;

	if (argv == NULL)
		exit(1);
	path = find_sys_tool(argv[0], env);
	if (path && access(path, X_OK) == -1)
	{
		ft_puterr(3, "minishell: permission denied: ", argv[0], "\n");
		free(path);
		exit(1);
	}
	else if (path)
		free(path);
	else if (!path && access(argv[0], X_OK) == 0)
		;
	else
	{
		ft_puterr(2, argv[0], ": command not found\n");
		exit (1);
	}
}