/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaiko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 16:40:55 by omaiko            #+#    #+#             */
/*   Updated: 2017/11/14 18:56:50 by omaiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_strcmp(const char *s1, const char *s2)
{
	int				i;
	unsigned char	s11;
	unsigned char	s22;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0')
		i++;
	s11 = (unsigned char)s1[i];
	s22 = (unsigned char)s2[i];
	return (s11 - s22);
}
