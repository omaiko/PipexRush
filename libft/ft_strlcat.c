/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaiko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 16:05:56 by omaiko            #+#    #+#             */
/*   Updated: 2017/11/14 18:56:03 by omaiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	char		*copydst;
	const char	*copysrc;
	size_t		fulllen;
	size_t		dstlen;

	copydst = dst;
	copysrc = src;
	fulllen = dstsize;
	while (fulllen-- != 0 && *copydst != '\0')
		copydst++;
	dstlen = copydst - dst;
	fulllen = dstsize - dstlen;
	if (fulllen == 0)
		return (dstlen + ft_strlen((char*)copysrc));
	while (*copysrc != '\0')
	{
		if (fulllen != 1)
		{
			*copydst++ = *copysrc;
			fulllen--;
		}
		copysrc++;
	}
	*copydst = '\0';
	return (dstlen + (copysrc - src));
}
