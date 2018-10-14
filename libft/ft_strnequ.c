/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aomelian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 14:54:16 by aomelian          #+#    #+#             */
/*   Updated: 2018/03/30 10:15:28 by aomelian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	if (s1 && s2)
	{
		while (*s1 && *s2 && n)
		{
			if (*s1 != *s2)
				break ;
			s1++;
			s2++;
			n--;
		}
	}
	else
		return (0);
	if (n)
		return ((*s1 - *s2) == 0);
	else
		return (1);
}
