/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_array.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaiko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 16:30:05 by omaiko            #+#    #+#             */
/*   Updated: 2017/11/20 17:02:14 by omaiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_array(char **array, char delimiter)
{
	int	i;

	i = 0;
	while (array[i])
	{
		ft_putstr(array[i]);
		if (array[i + 1] || delimiter == '\n')
			ft_putchar(delimiter);
		else
			ft_putchar('\n');
		i++;
	}
}
