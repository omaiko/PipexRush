/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaiko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 12:36:17 by omaiko            #+#    #+#             */
/*   Updated: 2017/11/11 14:25:33 by omaiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmap(char const *s, char (*f)(char))
{
	char	*str;
	int		i;

	i = 0;
	if (!s)
		return (0);
	if (!(str = (char*)malloc(ft_strlen(s) + 1)))
		return (0);
	while (*s)
		str[i++] = f(*s++);
	str[i] = '\0';
	return (str);
}
