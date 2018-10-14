/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaiko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 16:14:12 by omaiko            #+#    #+#             */
/*   Updated: 2017/11/07 16:32:55 by omaiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strstr(const char *haystack, const char *needle)
{
	char	*copyhaystack;
	char	*copyneedle;

	copyneedle = (char*)needle;
	if (ft_strlen((char*)needle) == 0)
		return ((char*)haystack);
	while (*haystack != '\0')
	{
		while (*haystack != *needle)
		{
			if (*haystack == '\0')
				return (NULL);
			haystack++;
		}
		copyhaystack = (char*)haystack;
		while (*copyhaystack++ == *copyneedle++)
			if (*copyneedle == '\0')
				return ((char*)haystack);
		copyneedle = (char*)needle;
		haystack++;
	}
	return (NULL);
}
