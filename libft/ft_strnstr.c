/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaiko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 15:06:14 by omaiko            #+#    #+#             */
/*   Updated: 2017/11/17 18:04:55 by omaiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_hay_to_nee(const char *haystack, const char *needle, size_t len)
{
	while (*haystack != *needle)
	{
		if (*haystack == '\0')
			return ;
		haystack++;
		len--;
	}
}

char		*ft_strnstr(const char *haystack, const char *needle, size_t lenght)
{
	char	*copyhaystack;
	char	*copyneedle;
	int		len;
	int		len2;

	if (lenght == 0)
		return (NULL);
	copyneedle = (char*)needle;
	if (ft_strlen((char*)needle) == 0 || lenght == 0)
		return ((char*)haystack);
	len = (int)lenght;
	while (*haystack != '\0' && len > 0)
	{
		len2 = len;
		ft_hay_to_nee(haystack, needle, len);
		copyhaystack = (char*)haystack;
		while (*copyhaystack++ == *copyneedle++ && len-- > 0)
			if (*copyneedle == '\0')
				return ((char*)haystack);
		copyneedle = (char*)needle;
		len = len2 - 1;
		haystack++;
	}
	return (NULL);
}
