/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaiko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 17:08:30 by omaiko            #+#    #+#             */
/*   Updated: 2017/11/01 17:58:10 by omaiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*copydst;
	const unsigned char	*copysrc;

	copydst = (unsigned char*)dst;
	copysrc = (unsigned char*)src;
	if (copydst < copysrc)
	{
		while (len > 0)
		{
			*copydst++ = *copysrc++;
			len--;
		}
	}
	else
	{
		copydst += len - 1;
		copysrc += len - 1;
		while (len > 0)
		{
			*copydst-- = *copysrc--;
			len--;
		}
	}
	return (dst);
}
