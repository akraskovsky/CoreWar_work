/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprovolo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 11:51:15 by fprovolo          #+#    #+#             */
/*   Updated: 2019/09/20 16:02:33 by fprovolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_lstfree(t_list *list)
{
	t_list	*ptr;

	while (list)
	{
		free(list->content);
		ptr = list->next;
		free(list);
		list = ptr;
	}
}

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*newlist;
	t_list	*newitem;
	t_list	*lastitem;

	if (!lst || !f)
		return (NULL);
	if (!(newlist = f(lst)))
		return (NULL);
	lastitem = newlist;
	while (lst->next)
	{
		lst = lst->next;
		if (!(newitem = f(lst)))
		{
			ft_lstfree(newlist);
			return (NULL);
		}
		lastitem->next = newitem;
		lastitem = newitem;
		lastitem->next = NULL;
	}
	return (newlist);
}
