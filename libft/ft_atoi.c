/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaiko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 15:51:37 by omaiko            #+#    #+#             */
/*   Updated: 2017/11/15 15:43:36 by omaiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int						ft_atoi(const char *str)
{
	size_t				i;
	int					sign;
	unsigned long int	res;
	unsigned long int	max;

	i = 0;
	sign = 1;
	res = 0;
	max = 9223372036854775807;
	while (ft_whitespace(str[i]))
		i++;
	if (str[i] == 45)
		sign = -1;
	if (str[i] == 43 || str[i] == 45)
		i++;
	while ((str[i] != '\0') && ft_isdigit(str[i]))
	{
		if ((res > max || (res == max && (str[i] - 48) > 7)) && sign == 1)
			return (-1);
		else if ((res > max || (res == max && (str[i] - 48) > 8)) && sign == -1)
			return (0);
		res = res * 10 + str[i] - 48;
		i++;
	}
	return ((int)res * sign);
}
