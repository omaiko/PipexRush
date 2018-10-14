/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aomelian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 22:56:55 by aomelian          #+#    #+#             */
/*   Updated: 2018/03/29 23:40:37 by aomelian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	str_len;
	char	*str;

	str = NULL;
	if (s && f)
	{
		str_len = ft_strlen(s);
		if ((str = (char*)malloc(sizeof(char) * (str_len + 1))) && str_len)
		{
			while (*s)
				*str++ = f(*s++);
			*str = 0;
			return (str - str_len);
		}
	}
	return (str);
}
