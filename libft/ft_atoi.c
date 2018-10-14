/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aomelian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 19:57:45 by aomelian          #+#    #+#             */
/*   Updated: 2018/03/30 13:38:40 by aomelian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	unsigned long long int	nbr;
	int						sign;

	nbr = 0;
	sign = 0;
	while (*str && (*str == ' ' || *str == '\n' || *str == '\v'
			|| *str == '\r' || *str == '\t' || *str == '\f'))
		str++;
	if (*str == '-' || *str == '+')
		if (*str++ == '-')
			sign = 1;
	while (*str >= '0' && *str <= '9' && *str)
		nbr = nbr * 10 + (*(str++) - 48);
	if (nbr > 9223372036854775807 && sign)
		return (0);
	else if (nbr > 9223372036854775807)
		return (-1);
	if (sign)
		return (-nbr);
	return (nbr);
}
