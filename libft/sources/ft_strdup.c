/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprovolo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 13:46:53 by fprovolo          #+#    #+#             */
/*   Updated: 2019/09/11 13:26:30 by fprovolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *src)
{
	int		len;
	int		i;
	char	*target;

	len = 0;
	while (src[len] != '\0')
		len++;
	target = (char*)malloc(sizeof(*target) * (len + 1));
	if (target != NULL)
	{
		i = 0;
		while (i <= len)
		{
			target[i] = src[i];
			i++;
		}
	}
	return (target);
}
