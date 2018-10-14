/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aomelian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 18:47:56 by aomelian          #+#    #+#             */
/*   Updated: 2018/03/30 13:37:03 by aomelian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*ft_create_elem(void *content, size_t content_size)
{
	t_list	*new;

	if ((new = (t_list*)malloc(sizeof(t_list))))
	{
		new->content = content;
		new->content_size = content_size;
		new->next = NULL;
	}
	return (new);
}

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*tmp_node;
	t_list	*new_lst;
	t_list	*begin_lst;

	begin_lst = NULL;
	if (f && lst)
	{
		tmp_node = f(lst);
		new_lst = ft_create_elem(tmp_node->content, tmp_node->content_size);
		begin_lst = new_lst;
		lst = lst->next;
		while (lst)
		{
			tmp_node = f(lst);
			new_lst->next = ft_create_elem(tmp_node->content,
					tmp_node->content_size);
			new_lst = new_lst->next;
			lst = lst->next;
		}
	}
	return (begin_lst);
}
