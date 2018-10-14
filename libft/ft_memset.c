/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaiko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 18:28:20 by omaiko            #+#    #+#             */
/*   Updated: 2017/10/30 19:07:07 by omaiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t len)
{
	unsigned char	*c1;

	c1 = (unsigned char*)str;
	while (len > 0)
	{
		*c1++ = (unsigned char)c;
		len--;
	}
	return (str);
}
