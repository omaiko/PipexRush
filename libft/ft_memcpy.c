/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaiko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 17:51:11 by omaiko            #+#    #+#             */
/*   Updated: 2017/11/18 11:19:06 by omaiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memcpy(void *dst, const void *src, size_t n)
{
	char			*copydst;
	char const		*copysrc;

	copydst = dst;
	copysrc = src;
	while (n > 0)
	{
		*copydst++ = *copysrc++;
		n--;
	}
	return (dst);
}
