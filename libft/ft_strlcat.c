/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aomelian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 20:03:47 by aomelian          #+#    #+#             */
/*   Updated: 2018/03/28 16:57:16 by aomelian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *restrict dst, const char *restrict src, size_t dstsize)
{
	char		*d;
	const char	*s;
	size_t		d_len;

	s = src;
	d = dst;
	d_len = 0;
	while (*dst++ && dstsize)
	{
		d_len++;
		dstsize--;
	}
	if (!dstsize)
		return (d_len + ft_strlen(src));
	while (*s)
		if (dstsize - 1)
		{
			*((d++) + d_len) = *s++;
			dstsize--;
		}
		else
			s++;
	*(d + d_len) = 0;
	return (d_len + (s - src));
}
