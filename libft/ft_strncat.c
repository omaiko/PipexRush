/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aomelian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 20:04:00 by aomelian          #+#    #+#             */
/*   Updated: 2018/03/30 19:38:46 by aomelian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *restrict dest, const char *restrict src, size_t n)
{
	size_t	dest_len;
	size_t	tmp_n;

	tmp_n = 0;
	dest_len = ft_strlen(dest);
	while (*src && n--)
	{
		tmp_n++;
		*((dest++) + dest_len) = *src++;
	}
	*(dest + dest_len) = 0;
	return (dest - tmp_n);
}
