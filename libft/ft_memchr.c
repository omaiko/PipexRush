/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaiko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 17:59:35 by omaiko            #+#    #+#             */
/*   Updated: 2017/11/02 16:50:45 by omaiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned char	c1;
	unsigned char	*copystr;

	c1 = (unsigned char)c;
	copystr = (unsigned char*)str;
	if (n == 0)
		return (NULL);
	while (n != 0)
	{
		if (*copystr == c1)
			return ((void*)copystr);
		copystr++;
		n--;
	}
	return (NULL);
}
