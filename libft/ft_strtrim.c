/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aomelian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 15:29:50 by aomelian          #+#    #+#             */
/*   Updated: 2018/03/30 13:32:46 by aomelian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	len;
	char	*str;

	str = NULL;
	if (!s)
		return (str);
	len = ft_strlen(s);
	while ((s[len - 1] == ' ' || s[len - 1] == '\n'
			|| s[len - 1] == '\t') && s[len - 1])
		len--;
	while ((*s == ' ' || *s == '\n' || *s == '\t') && *s && len)
	{
		s++;
		len--;
	}
	if (!(str = (char*)malloc(sizeof(char) * (len + 1))))
		return (str);
	str[len] = 0;
	while (len)
	{
		str[len - 1] = *(s + len - 1);
		len--;
	}
	return (str);
}
