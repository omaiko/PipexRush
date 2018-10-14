/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaiko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 17:10:22 by omaiko            #+#    #+#             */
/*   Updated: 2017/11/16 19:07:28 by omaiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*start;
	t_list	*newnode;
	t_list	*temp;

	if (!lst || !f)
		return (0);
	temp = f(lst);
	if (!(newnode = ft_lstnew(temp->content, temp->content_size)))
		return (0);
	start = newnode;
	lst = lst->next;
	while (lst)
	{
		temp = f(lst);
		if (!(newnode->next = ft_lstnew(temp->content, temp->content_size)))
			return (0);
		newnode = newnode->next;
		lst = lst->next;
	}
	return (start);
}
