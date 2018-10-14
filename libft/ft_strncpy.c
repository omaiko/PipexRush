/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaiko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 18:27:54 by omaiko            #+#    #+#             */
/*   Updated: 2017/11/14 18:55:12 by omaiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	i;

	i = 0;
	if (ft_strlen(src) > len)
		i = len;
	else
		i = ft_strlen(src);
	if (i < len)
		ft_memset(dst + i, '\0', len - i);
	return (ft_memcpy(dst, src, i));
}
