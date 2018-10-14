/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aomelian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 15:05:53 by aomelian          #+#    #+#             */
/*   Updated: 2018/03/30 13:34:28 by aomelian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	str[1];

	if (fd < 0)
		return ;
	if (n < 0)
	{
		write(fd, "-", 1);
		if (n == -2147483648)
		{
			ft_putnbr_fd(-(n / 10), fd);
			ft_putnbr_fd(8, fd);
			return ;
		}
		ft_putnbr_fd(-n, fd);
		return ;
	}
	str[0] = n % 10 + 48;
	if (n / 10)
		ft_putnbr_fd(n / 10, fd);
	write(fd, str, 1);
}
