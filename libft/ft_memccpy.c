/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aomelian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 19:59:38 by aomelian          #+#    #+#             */
/*   Updated: 2018/03/30 13:40:35 by aomelian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *restrict dst,
		const void *restrict src,
		int c,
		size_t n)
{
	while (n--)
		if ((*(unsigned char*)dst++ = *(unsigned char*)src++)
				== (unsigned char)c)
			return (dst);
	return (NULL);
}
