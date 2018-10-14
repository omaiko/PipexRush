/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tests_for_is.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaiko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 13:55:28 by omaiko            #+#    #+#             */
/*   Updated: 2017/11/18 14:38:52 by omaiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_tests_for_is(void)
{
	int		fail;
	int		c;

	fail = 0;
	c = 'A';
	while (c <= 'Z')
	{
		if (ft_isalpha(c) != ft_isalpha(c))
		{
			fail++;
			ft_putstr("\033[31mFail\033[0m in ft_NAME. Test #");
			ft_putnbr(fail);
			ft_putchar('\n');
		}
		c++;
	}
	if (fail == 0)
		ft_putstr("ft_NAME is \033[32mOK\033[0m\n");
}
