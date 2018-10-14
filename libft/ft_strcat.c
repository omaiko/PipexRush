/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aomelian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 20:00:39 by aomelian          #+#    #+#             */
/*   Updated: 2018/03/28 14:56:11 by aomelian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *restrict s1, const char *restrict s2)
{
	int		i;
	size_t	s1_len;

	s1_len = ft_strlen(s1);
	i = -1;
	while (s2[++i])
		s1[s1_len + i] = s2[i];
	s1[s1_len + i] = 0;
	return (s1);
}
