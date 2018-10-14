/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aomelian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 16:46:45 by aomelian          #+#    #+#             */
/*   Updated: 2018/03/30 10:51:28 by aomelian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	const char	*tmp;

	if (!*needle)
		return ((char*)haystack);
	while (*haystack && len)
	{
		if (*haystack == *needle)
		{
			tmp = needle;
			while (*haystack == *tmp && *tmp && *haystack && len)
			{
				haystack++;
				tmp++;
				len--;
			}
			if (!(*tmp))
				return ((char*)(haystack - (tmp - needle)));
			len += tmp - needle;
			haystack = (const char*)(haystack - (tmp - needle));
		}
		len--;
		haystack++;
	}
	return (NULL);
}
