/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aomelian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 23:00:31 by aomelian          #+#    #+#             */
/*   Updated: 2018/03/30 19:43:06 by aomelian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	str_len;
	size_t	i;
	char	*str;

	str = NULL;
	if (s)
	{
		str_len = 0;
		i = 0;
		while (s[str_len])
			str_len++;
		if ((str = (char*)malloc(sizeof(char) * (str_len + 1))) && str_len)
		{
			str[str_len] = 0;
			while (i < str_len)
			{
				str[i] = f(i, s[i]);
				i++;
			}
		}
	}
	return (str);
}
