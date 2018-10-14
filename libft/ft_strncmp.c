/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaiko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 17:02:10 by omaiko            #+#    #+#             */
/*   Updated: 2017/11/07 17:35:56 by omaiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_strncmp(const char *s1, const char *s2, size_t len)
{
	int				i;
	unsigned char	s11;
	unsigned char	s22;
	int				n;

	i = 0;
	n = (int)len;
	while ((s1[i] == s2[i] && s1[i] != '\0') && i < n)
		i++;
	if (i == n)
		return (0);
	s11 = (unsigned char)s1[i];
	s22 = (unsigned char)s2[i];
	return (s11 - s22);
}
