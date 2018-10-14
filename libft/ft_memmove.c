/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aomelian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 20:00:11 by aomelian          #+#    #+#             */
/*   Updated: 2018/03/28 14:47:36 by aomelian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	void	*tmp;

	tmp = dst;
	if (src < dst)
		while (len--)
			*((unsigned char*)(dst + len)) = *((unsigned char*)(src + len));
	else
		ft_memcpy(dst, src, len);
	return (tmp);
}
