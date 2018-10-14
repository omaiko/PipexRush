/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aomelian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 15:05:30 by aomelian          #+#    #+#             */
/*   Updated: 2018/06/15 15:05:52 by aomelian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**tab_cpy(char **tab)
{
	char	**tab_cpy;
	char	**tab_cpy_tmp;
	ssize_t	len;

	tab_cpy = tab;
	len = 0;
	while (*(tab_cpy++))
		len++;
	if (!(tab_cpy = (char**)malloc(sizeof(char*) * (len + 1))))
		return (NULL);
	tab_cpy_tmp = tab_cpy;
	while (*tab)
	{
		if (!(*tab_cpy_tmp = ft_strdup(*tab)))
			return (NULL);
		tab++;
		tab_cpy_tmp++;
	}
	*tab_cpy_tmp = NULL;
	return (tab_cpy);
}
