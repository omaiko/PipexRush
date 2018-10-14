/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aomelian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 19:51:13 by aomelian          #+#    #+#             */
/*   Updated: 2018/04/02 15:44:49 by aomelian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_nbr_digits_base(int n, int base)
{
	int	i;

	i = 1;
	while ((n /= base))
		i++;
	return (i);
}

char			*ft_itoa_base(int nbr, char const *base_str)
{
	char	*number;
	char	sign;
	int		nbr_digits;
	int		base;

	sign = (char)(nbr > 0 ? 0 : 1);
	nbr = (sign ? -nbr : nbr);
	base = (unsigned int)ft_strlen(base_str);
	nbr_digits = ft_nbr_digits_base(nbr, base);
	number = ft_strnew((size_t)(base + sign));
	if (sign)
		*number = '-';
	while (nbr_digits)
	{
		*(number + (nbr_digits--)) = base_str[-(nbr % base)];
		nbr /= base;
	}
	return (number);
}
