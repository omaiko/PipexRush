/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aomelian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 20:01:23 by aomelian          #+#    #+#             */
/*   Updated: 2018/03/28 14:55:27 by aomelian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*nstr;
	char	*tmp;

	if (!(nstr = (char*)malloc(sizeof(char) * (ft_strlen(s1) + 1))))
		return (NULL);
	tmp = nstr;
	if (tmp)
		while (*s1)
			*nstr++ = *s1++;
	*nstr = 0;
	return (tmp);
}
