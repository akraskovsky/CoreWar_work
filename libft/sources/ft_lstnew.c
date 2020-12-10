/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprovolo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 17:09:01 by fprovolo          #+#    #+#             */
/*   Updated: 2019/09/19 17:44:12 by fprovolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*newitem;

	newitem = (t_list *)malloc(sizeof(t_list));
	if (!newitem)
		return (NULL);
	if (content == NULL)
	{
		newitem->content = NULL;
		newitem->content_size = 0;
	}
	else
	{
		if (!(newitem->content = malloc(content_size)))
		{
			free(newitem);
			return (NULL);
		}
		ft_memcpy(newitem->content, content, content_size);
		newitem->content_size = content_size;
	}
	newitem->next = NULL;
	return (newitem);
}
