/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaiko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/14 22:50:52 by omaiko            #+#    #+#             */
/*   Updated: 2018/10/14 22:50:53 by omaiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include "libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

int		check_command(char *argv[], char *env[]);
void	run_command(char *argv[], char *env[]);
void	fexit(char *name);
int		check_access(char *path, unsigned mode);
#endif
