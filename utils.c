/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaiko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/14 22:50:37 by omaiko            #+#    #+#             */
/*   Updated: 2018/10/14 22:51:46 by omaiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	fexit(char *name)
{
	ft_puterr(2, name, ": failed to fork\n");
	exit(1);
}

int		check_access(char *path, unsigned mode)
{
	if (mode == 0 && access(path, F_OK) == -1)
	{
		ft_puterr(2, path, ": No such file or directory\n");
		return (1);
	}
	else if (mode == R_OK && access(path, R_OK) == -1)
	{
		ft_puterr(2, path, ": Permission denied\n");
		return (1);
	}
	else if (mode == W_OK && access(path, W_OK) == -1)
	{
		ft_puterr(2, path, ": Permission denied\n");
		return (1);
	}
	return (0);
}
