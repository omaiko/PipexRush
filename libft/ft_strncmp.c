/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aomelian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 19:49:39 by aomelian          #+#    #+#             */
/*   Updated: 2018/03/30 10:35:31 by aomelian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n)
		while (*s1 == *s2 && *s1 && *s2 && --n)
		{
			s1++;
			s2++;
		}
	else
		return (0);
	return (*(unsigned char*)s1 - *(unsigned char*)s2);
}
