/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprovolo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 18:27:08 by fprovolo          #+#    #+#             */
/*   Updated: 2019/09/19 19:00:26 by fprovolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*current_ptr;
	t_list	*next;

	if (!alst || !*alst)
		return ;
	current_ptr = *alst;
	while (current_ptr)
	{
		next = current_ptr->next;
		del(current_ptr->content, current_ptr->content_size);
		free(current_ptr);
		current_ptr = next;
	}
	*alst = NULL;
}
