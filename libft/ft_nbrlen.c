/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbr_digits.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aomelian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 19:51:33 by aomelian          #+#    #+#             */
/*   Updated: 2018/03/31 19:52:29 by aomelian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long int					ft_nbrlen(long long int n)
{
	long int	i;

	i = 1;
	while ((n /= 10))
		i++;
	return (i);
}
