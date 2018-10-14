/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aomelian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 19:59:47 by aomelian          #+#    #+#             */
/*   Updated: 2018/03/26 20:52:02 by aomelian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	if (n)
		while (n-- && *(unsigned char*)s1++ == *(unsigned char*)s2++)
			;
	else
		return (0);
	return (*(unsigned char*)--s1 - *(unsigned char*)--s2);
}
