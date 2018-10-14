#include "pipex.h"
#include "errno.h"

void tipa_hendlim(int a)
{
	printf("Something gone wrong: %d\n", a);
	printf("Error: %s\n", strerror(errno));
}

void free_tab(char **str_tab)
{
	char	*tmp;
	char	**tmp_tab;

	if (!str_tab)
		return ;
	tmp_tab = str_tab;
	while (*str_tab)
	{
		tmp = *str_tab;
		str_tab++;
		free(tmp);
	}
	free(tmp_tab);
}

char	**g_env;

int		open_file(char *path)
{
	int	fd;

	if ((fd = open(path, O_RDWR)) < 0)
			tipa_hendlim(0);
	return (fd);
}

int		run_cmd_1(char **cmd_splitted, int *pipefd, char *file1_path)
{
	int		pid;
	char	buf;


	pid = fork();
	if (pid > 0)
		;
	else if (pid == 0)
	{
		// printf(">>>> %s run cmd write: %s\n", file1_path, cmd_splitted[0]);
		int	fd = open(file1_path, O_RDONLY, 0);
		dup2(fd, STDIN_FILENO);
		dup2(pipefd[1], STDOUT_FILENO);
		//close(pipefd[1]);
		//close(pipefd[0]);
		try_run_tool(*cmd_splitted, cmd_splitted + 1, g_env);
	}
	else if (pid < 0)
		tipa_hendlim(2);
}

void	run_cmd_2(char **cmd_splitted, int *pipefd, char *file2_path)
{
	int		pid;
	char	buf;

    // printf("run cmd read: %s\n", cmd_splitted[0]);
	pid = fork();
	if (pid > 0)
		;
	else if (pid == 0)
	{
		int	fd = open(file2_path, O_CREAT | O_RDWR | O_TRUNC, 0777);
		dup2(fd, STDOUT_FILENO);
		dup2(pipefd[0], STDIN_FILENO);
		close(pipefd[1]);
		try_run_tool(*cmd_splitted, cmd_splitted + 1, g_env);
//		if ((execve(cmd_splitted[0], cmd_splitted + 1, g_env)) < 0)
//		{
//			open("sucharaBABAH", O_CREAT);
//			tipa_hendlim(3);
//		}
	}
	else if (pid < 0)
		tipa_hendlim(4);
}

void	pipex(char **list)
{
	int	fd_file_1;
	int	fd_file_2;
	int	pipefd[2];


	if (pipe(pipefd) == -1) // pipefd[1] -> pipefd[0]
		tipa_hendlim(5);

	printf("pipe(): %d %d\n", pipefd[0], pipefd[1]);
	char *tmp_file1 = *(list++);
	char **cmd_splitted1 = ft_strsplit(*(list++), ' ');
	//	free_tab(cmd_splitted);

	char **cmd_splitted2 = ft_strsplit(*(list++), ' ');
	char *tmp_file2 = *list;
	printf("file1_path: %s file2_path: %s\n", tmp_file1, tmp_file2);


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
