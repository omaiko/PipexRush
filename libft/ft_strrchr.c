/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaiko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 11:51:16 by omaiko            #+#    #+#             */
/*   Updated: 2017/11/14 18:58:36 by omaiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrchr(const char *s, int c)
{
	char	c1;
	char	*str;

	c1 = (char)c;
	str = (char*)s + ft_strlen((char*)s);
	while (*str != c1)
	{
		if (str < s)
			return (0);
		str--;
	}
	return (str);
}
