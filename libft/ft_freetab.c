/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freetab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aomelian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 15:06:28 by aomelian          #+#    #+#             */
/*   Updated: 2018/10/14 17:35:11 by omaiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_freetab(char **tab)
{
	char	**tab_cpy;

	if (!tab)
		return ;
	tab_cpy = tab;
	while (*tab)
		free(*(tab++));
	free(tab_cpy);
}
