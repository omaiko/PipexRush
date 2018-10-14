/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaiko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 16:15:07 by omaiko            #+#    #+#             */
/*   Updated: 2017/11/13 18:06:53 by omaiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *str)
{
	char	*s;
	int		i;
	int		letters;
	int		k;

	i = 0;
	if (!str)
		return (0);
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t')
		i++;
	letters = i;
	while (str[letters])
		letters++;
	letters -= 1;
	while (str[letters] == ' ' || str[letters] == '\n' || str[letters] == '\t')
		letters--;
	letters = (letters > i) ? letters - i : 0;
	if (!(s = (char*)malloc(letters + 2)))
		return (0);
	k = 0;
	while (k <= letters)
		s[k++] = str[i++];
	s[k] = '\0';
	return (s);
}
