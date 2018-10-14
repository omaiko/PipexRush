/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pathjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aomelian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 15:05:57 by aomelian          #+#    #+#             */
/*   Updated: 2018/06/15 15:06:17 by aomelian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*path_join(char *p1, char *p2)
{
	char		*np;
	size_t		len;

	if (!p1)
		return (ft_strdup(p2));
	len = 0;
	len += ft_strlen(p1);
	len += ft_strlen(p2);
	np = (char*)malloc(sizeof(char) * (len + 2));
	ft_bzero(np, len + 2);
	ft_strcat(np, p1);
	ft_strcat(np, "/");
	ft_strcat(np, p2);
	return (np);
}
