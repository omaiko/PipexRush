/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaiko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/14 15:58:18 by omaiko            #+#    #+#             */
/*   Updated: 2018/10/14 17:42:01 by omaiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "errno.h"

void	tipa_hendlim(void)
{
	ft_putstr_fd("Some text\n", 1);
	//printf("Something gone wrong: %d\n", a);
	//printf("Error: %s\n", strerror(errno));
}

int		ft_check_access(char *path)
{
	if (access(path, F_OK) == -1)
		ft_putstr_fd("zsh: no such file or directory\n", 2);
	else if (access(path, R_OK) == -1)
		ft_putstr_fd("read: .: Permission denied\n", 2);
	else if (access(path, W_OK) == -1)
		ft_putstr_fd("write: .: Permission denied\n", 2);
	else
		return (1);
	return (0);
}

char	**g_env;

int		open_file(char *path)
{
	int	fd;

	if ((fd = open(path, O_RDWR)) < 0)
		tipa_hendlim();
	return (fd);
}

void	run_cmd_1(char **cmd_splitted, int *pipefd, char *file1_path)
{
	int		pid;
	int		fd;

	pid = fork();
	if (pid > 0)
		;
	else if (pid == 0)
	{
		ft_check_access(file1_path);
		fd = open(file1_path, O_RDONLY, 0);
		dup2(fd, STDIN_FILENO);
		dup2(pipefd[1], STDOUT_FILENO);
		try_run_tool(*cmd_splitted, cmd_splitted, g_env);
	}
	else if (pid < 0)
	{
		ft_putstr_fd("Fork failed\n", 2);
		exit(0);
	}
}

void	run_cmd_2(char **cmd_splitted, int *pipefd, char *file2_path)
{
	int		pid;
	int		fd;

	pid = fork();
	if (pid > 0)
		;
	else if (pid == 0)
	{
		fd = open(file2_path, O_CREAT | O_RDWR | O_TRUNC, 0777);
		dup2(fd, STDOUT_FILENO);
		dup2(pipefd[0], STDIN_FILENO);
		close(pipefd[1]);
		try_run_tool(*cmd_splitted, cmd_splitted, g_env);
	}
	else if (pid < 0)
	{
		ft_putstr_fd("Fork failed\n", 2);
		exit(0);
	}
}

void	pipex(char **list)
{
	int		pipefd[2];
	char	*tmp_file1;
	char	**cmd_splitted1;
	char	**cmd_splitted2;
	char	*tmp_file2;

	if (pipe(pipefd) == -1)
		exit(0);
	tmp_file1 = *(list++);
	cmd_splitted1 = ft_strsplit(*(list++), ' ');
	cmd_splitted2 = ft_strsplit(*(list++), ' ');
	tmp_file2 = *list;
	run_cmd_2(cmd_splitted2, pipefd, tmp_file2);
	run_cmd_1(cmd_splitted1, pipefd, tmp_file1);
}

int		main(int argc, char **argv, char **environ)
{
	if (argc < 5)
	{
		ft_putstr_fd(argv[0], 2);
		ft_putstr_fd(": usage: ", 2);
		ft_putstr_fd(argv[0], 2);
		ft_putstr_fd(" file1 cmd1 cmd2 [cmd3] ... file2\n", 2);
		return (0);
	}
	g_env = environ;
	pipex(argv + 1);
}
