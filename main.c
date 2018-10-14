/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaiko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/14 22:50:47 by omaiko            #+#    #+#             */
/*   Updated: 2018/10/14 22:52:00 by omaiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "errno.h"

char	**g_env;

void	infile_reddirection(char **argv, int pipefd[])
{
	int		fd;
	int		pid;
	char	**tmp;

	tmp = ft_strsplit(argv[1], ' ');
	check_command(tmp, g_env);
	if (check_access(argv[0], F_OK) || check_access(argv[0], R_OK))
		exit(1);
	if ((pid = fork()) == 0)
	{
		if ((fd = open(argv[0], O_RDONLY)) == -1)
			exit(1);
		dup2(fd, STDIN_FILENO);
		dup2(pipefd[1], STDOUT_FILENO);
		close(pipefd[0]);
		run_command(tmp, g_env);
	}
	else if (pid > 0)
	{
		ft_free_tab(tmp);
		free(tmp);
	}
	else if (pid < 0)
		fexit(argv[1]);
}

void	outfile_reddirection(int argc, char **argv, int pipefd[])
{
	int		fd;
	int		pid;
	char	**tmp;

	tmp = ft_strsplit(argv[argc - 2], ' ');
	check_command(tmp, g_env);
	if ((!access(argv[argc - 1], F_OK) && check_access(argv[argc - 1], W_OK)))
		exit(1);
	if ((pid = fork()) == 0)
	{
		if ((fd = open(argv[argc - 1],
				O_CREAT | O_RDWR | O_TRUNC, 0644)) == -1)
			exit(1);
		dup2(fd, STDOUT_FILENO);
		dup2(pipefd[0], STDIN_FILENO);
		close(pipefd[1]);
		run_command(tmp, g_env);
	}
	else if (pid > 0)
	{
		ft_free_tab(tmp);
		free(tmp);
	}
	else if (pid < 0)
		fexit(argv[argc - 2]);
}

void	pipex(int argc, char **argv)
{
	int		pipefd[2];
	int		fd_tmp;
	char	**cmd;

	((pipe(pipefd) == -1) ? exit(1) : 0);
	fd_tmp = pipefd[1];
	outfile_reddirection(argc, argv, pipefd);
	while ((argc--) - 4 > 0)
	{
		((pipe(pipefd) == -1) ? exit(1) : 0);
		check_command((cmd = ft_strsplit(argv[argc - 2], ' ')), g_env);
		if ((fork()) == 0)
		{
			close(pipefd[1]);
			dup2(fd_tmp, STDOUT_FILENO);
			dup2(pipefd[0], STDIN_FILENO);
			run_command(cmd, g_env);
		}
		ft_free_tab(cmd);
		free(cmd);
		fd_tmp = pipefd[1];
	}
	infile_reddirection(argv, pipefd);
}

int		main(int argc, char **argv, char **environ)
{
	g_env = environ;
	if (argc < 5)
	{
		ft_putstr_fd(argv[0], 2);
		ft_putstr_fd(": usage: ", 2);
		ft_putstr_fd(argv[0], 2);
		ft_putstr_fd(" file1 cmd1 cmd2 ... file2\n", 2);
		return (0);
	}
	pipex(argc - 1, argv + 1);
	return (0);
}
