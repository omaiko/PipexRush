/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_elements.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaiko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 14:47:55 by omaiko            #+#    #+#             */
/*   Updated: 2017/11/18 15:32:09 by omaiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_print_info(int l, int n, int s)
{
	ft_putstr("Number of letters in your string is: \n");
	ft_putnbr(l);
	ft_putstr("\nNumber of digits in your string is: \n");
	ft_putnbr(n);
	ft_putstr("\nNumber of spaces in your string is: \n");
	ft_putnbr(s);
}

int			ft_elements(char *str)
{
	int i;
	int numbers;
	int	letters;
	int	spaces;

	i = 0;
	numbers = 0;
	letters = 0;
	spaces = 0;
	while (str[i] != '\0')
	{
		if (str[i] && (ft_isalpha(str[i]) == 1))
			letters++;
		if (str[i] && (ft_isdigit(str[i]) == 1))
			numbers++;
		if (str[i] && (ft_whitespace(str[i]) == 1))
			spaces++;
		i++;
	}
	ft_print_info(letters, numbers, spaces);
	return (0);
}
