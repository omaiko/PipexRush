/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaiko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 16:42:49 by omaiko            #+#    #+#             */
/*   Updated: 2017/11/14 18:59:32 by omaiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_str(size_t n, char *str, int i, int sign)
{
	str[i + 1] = '\0';
	if (sign)
		str[0] = '-';
	while (i >= sign)
	{
		if (n >= 10)
		{
			str[i] = n % 10 + 48;
			n = n / 10;
		}
		else
			str[i] = n + 48;
		i--;
	}
	return (str);
}

char			*ft_itoa(int n)
{
	int			sign;
	int			i;
	char		*str;
	long int	x;
	long int	n2;

	n2 = (size_t)n;
	i = 1;
	sign = 0;
	if (n2 < 0)
	{
		sign = 1;
		n2 = -n2;
	}
	x = n2;
	while (x >= 10)
	{
		x = x / 10;
		i++;
	}
	if (!(str = (char*)malloc(sign + i + 1)))
		return (0);
	return (ft_str(n2, str, sign + i - 1, sign));
}
