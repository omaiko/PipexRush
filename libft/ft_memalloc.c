/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aomelian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 22:33:19 by aomelian          #+#    #+#             */
/*   Updated: 2018/03/30 13:37:24 by aomelian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*ptr;
	void	*tmp;

	ptr = NULL;
	tmp = ptr;
	if ((ptr = malloc(size)))
	{
		tmp = ptr;
		while (size--)
			*(unsigned char*)ptr++ = 0;
	}
	return (tmp);
}
