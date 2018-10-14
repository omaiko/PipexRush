/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_tool.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaiko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/14 16:06:47 by omaiko            #+#    #+#             */
/*   Updated: 2018/10/14 17:34:36 by omaiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "pipex.h"

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
	if (execve(tool_path, argv, env) == -1)
		ft_puterr(1, "minishell: failed to run proccess\n");
	return (-1);
}

int			try_run_tool(char *name, char *argv[], char *env[])
{
	char *path;

	path = find_sys_tool(name, env);
	if (path && access(path, X_OK) == -1)
	{
		ft_puterr(3, "minishell: permission denied: ", name, "\n");
		free(path);
		return (0);
	}
	else if (path)
	{
		execute_tool(path, argv, env);
		free(path);
		return (0);
	}
	return (1);
}
