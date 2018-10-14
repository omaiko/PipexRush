/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_findenv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aomelian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 15:03:48 by aomelian          #+#    #+#             */
/*   Updated: 2018/10/14 16:15:36 by omaiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** findenv --
**	Returns pointer to value associated with name, if any, else NULL.
*/

char	*find_env(char *name)
{
	size_t		len;
	char		*value;
	char		**p;
	extern char	**environ;

	len = ft_strlen(name);
	p = environ;
	while ((value = *(p++)) != NULL)
		if (ft_strncmp(value, name, len) == 0 && value[len] == '=')
			return (value + len + 1);
	return (NULL);
}
