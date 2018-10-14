/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaiko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 15:49:20 by omaiko            #+#    #+#             */
/*   Updated: 2017/11/11 16:51:26 by omaiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	n;

	i = start;
	n = 0;
	if (!s)
		return (0);
	if (!(str = (char*)malloc(len + 1)))
		return (0);
	while (n < len)
		str[n++] = s[i++];
	str[n] = '\0';
	return (str);
}
