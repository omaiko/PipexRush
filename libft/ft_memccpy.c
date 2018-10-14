/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaiko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 19:01:37 by omaiko            #+#    #+#             */
/*   Updated: 2017/11/09 16:55:56 by omaiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void							*ft_memccpy(void *dst, const void *src, int c,
		size_t n)
{
	unsigned char				c1;
	unsigned char				*copydst;
	unsigned const char			*copysrc;

	copydst = (unsigned char*)dst;
	copysrc = (unsigned char*)src;
	c1 = (unsigned char)c;
	while (n > 0)
	{
		if ((*copydst++ = *copysrc++) == c1)
			return ((void*)copydst);
		n--;
	}
	return (NULL);
}
