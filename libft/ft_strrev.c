/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aomelian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 18:44:16 by aomelian          #+#    #+#             */
/*   Updated: 2018/03/31 19:55:48 by aomelian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strrev(char *str)
{
	int			i;
	int			len;
	char		c;

	len = (int)ft_strlen(str);
	i = 0;
	while (i < len / 2)
	{
		c = *(str + i);
		*(str + i) = *(str + len - i - 1);
		*(str + len - i - 1) = c;
		len--;
		i++;
	}
}
