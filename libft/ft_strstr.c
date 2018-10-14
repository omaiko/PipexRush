/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aomelian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 16:46:45 by aomelian          #+#    #+#             */
/*   Updated: 2018/03/28 16:59:42 by aomelian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	const char	*tmp;

	if (!*needle)
		return ((char*)haystack);
	while (*haystack)
	{
		if (*haystack == *needle)
		{
			tmp = needle;
			while (*haystack == *tmp && *tmp && *haystack)
			{
				haystack++;
				tmp++;
			}
			if (!(*tmp))
				return ((char*)(haystack - (tmp - needle)));
			haystack = (const char*)(haystack - (tmp - needle));
		}
		haystack++;
	}
	return (NULL);
}
