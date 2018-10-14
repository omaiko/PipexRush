/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aomelian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 14:55:14 by aomelian          #+#    #+#             */
/*   Updated: 2018/03/29 23:54:46 by aomelian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;
	char	*tmp;

	if (!s)
		return (0);
	tmp = NULL;
	if ((str = (char*)malloc(sizeof(char) * (len + 1))))
	{
		tmp = str;
		str[len] = 0;
		while (len--)
			*str++ = *((s++) + start);
	}
	return (tmp);
}
