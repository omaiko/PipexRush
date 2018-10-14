/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aomelian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 22:39:25 by aomelian          #+#    #+#             */
/*   Updated: 2018/03/31 17:08:13 by aomelian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*str;
	char	*tmp;

	str = NULL;
	tmp = str;
	if ((str = malloc(sizeof(char) * (size + 1))) != NULL)
	{
		tmp = str;
		while (size-- > 0)
			*str++ = 0;
		*str = 0;
	}
	return (tmp);
}
