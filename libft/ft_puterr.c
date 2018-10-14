/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puterr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aomelian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 16:44:12 by aomelian          #+#    #+#             */
/*   Updated: 2018/06/09 16:45:49 by aomelian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>

void	ft_puterr(int n, char *str, ...)
{
	va_list ap;
	char	*ptr;

	va_start(ap, str);
	write(2, str, ft_strlen(str));
	while ((n--) - 1)
	{
		ptr = va_arg(ap, char*);
		write(2, ptr, ft_strlen(ptr));
	}
	va_end(ap);
}
