/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaiko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 16:52:40 by omaiko            #+#    #+#             */
/*   Updated: 2017/11/14 19:02:23 by omaiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strncat(char *dst, const char *src, size_t n)
{
	size_t	size;
	char	*s;

	s = dst;
	dst = dst + ft_strlen(dst);
	if (ft_strlen(src) < n)
		size = ft_strlen(src);
	else
		size = n;
	dst[size] = '\0';
	ft_memcpy(dst, src, size);
	return (s);
}
